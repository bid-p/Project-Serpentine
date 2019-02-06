#include "adaptivepurepursuit.hpp"
// #include "config.hpp"
#include "drive.hpp"

namespace pathfollowing
{
AdaptivePurePursuit::AdaptivePurePursuit(
	std::unique_ptr<okapi::IterativePosPIDController> straight,
	std::unique_ptr<okapi::IterativePosPIDController> turn,
	int lookahead, double lookaheadKf) : straightController(std::move(straight)),
										 turnController(std::move(turn)),
										 mainLookahead(lookahead),
										 lookahead(lookahead),
										 lookaheadKf(lookaheadKf),
										 direction(1) {}

void AdaptivePurePursuit::setPath(path::Path *path)
{
	this->path = path;
	int look = path->getLookahead();
	lookahead = (look < 0) ? mainLookahead : look;
}

void AdaptivePurePursuit::setLookahead(int lookahead)
{
	this->lookahead = lookahead;
}

void AdaptivePurePursuit::loop()
{
	using namespace okapi;

	path::Point robotPosition = {odometry::currX, odometry::currY};
	path::PointAndDistance closestPointAndDistance = path->getClosestPointAndDistance(robotPosition);
	int newLookahead = lookahead - (closestPointAndDistance.distance.convert(inch) * lookaheadKf);
	newLookahead = (newLookahead < 0) ? 1 : newLookahead;

	int requiredPosition = closestPointAndDistance.point.t;
	target = path->pointAt(requiredPosition + newLookahead);

	double distTolookaheadPoint =
		sqrt(pow(target.x.convert(inch) - robotPosition.x.convert(inch), 2) + pow(target.y.convert(inch) - robotPosition.y.convert(inch), 2));

	straightController->setTarget(distTolookaheadPoint);

	double forwardPower = straightController->step(0);
	QAngle bearing =
		std::atan2((this->target.x.convert(inch) - robotPosition.x.convert(inch)),
				   (this->target.y.convert(inch) - robotPosition.y.convert(inch))) *
		radian;

	// auto xError = this->target.x.convert(inch) - robotPosition.x.convert(inch);
	// auto yError = this->target.y.convert(inch) - robotPosition.y.convert(inch);

	// auto atanBearing = xError == 0 ? 0 : std::atan(yError / xError);

	// QAngle bearing = std::atan2(
	// 		std::cos(atanBearing),
	// 		std::atan(atanBearing)
	// );

	direction = 1;

	// if (bearing.convert(degree) > 90)
	// {
	// 	//bearing = (bearing.convert(degree) - 180) * degree;
	// 	direction *= -1;
	// }
	// else if (bearing.convert(degree) < -90)
	// {
	// 	//bearing = (bearing.convert(degree) + 180) * degree;
	// 	direction *= -1;
	// }

	QAngle turnControllerPV = odometry::currAngle;

	if (bearing.convert(radian) < 0 && turnControllerPV.convert(radian) > 0)
	{
		turnControllerPV = (turnControllerPV.convert(radian) - M_PI * 2) * radian;
	}

	turnController->setTarget(bearing.convert(degree));

	// double turnPower = turnController->step(odometry::currAngle.convert(degree));
	// double turnPower = turnController->step(currHeading.convert(degree));
	double turnPower = turnController->step(turnControllerPV.convert(degree));

	// printf("%f\n", bearing.convert(degree)); //lul that's big brain

	// printf("%.0f,%.5f,%.5f,%.5f,%.5f\n", bearing.convert(degree), this->target.x.convert(inch), this->target.y.convert(inch), robotPosition.x.convert(inch), robotPosition.y.convert(inch));
	printf("Heading: %.0f\nTarget heading: %.0f\n\nDistance to point: %.10f\n\nPoint at: %d\n\nPoint: (%.10f, %.10f)\nRobot: (%.10f, %.10f)\n\nClosest Point (%d) (%.10f, %.10f)", odometry::currAngle.convert(degree), bearing.convert(degree), distTolookaheadPoint, requiredPosition + newLookahead, this->target.x.convert(inch), this->target.y.convert(inch), robotPosition.x.convert(inch), robotPosition.y.convert(inch), closestPointAndDistance.point.t, closestPointAndDistance.point.x, closestPointAndDistance.point.y);

	drive::chassis.driveVector(direction * forwardPower, turnPower); // TODO CHASSIS MODEL IN CONSTRUCTOR INSTEAD OF HERE
}

bool AdaptivePurePursuit::isSettled()
{
	path::Point endPoint = path->pointAt(path->getResolution());
	double distance = sqrt(pow(endPoint.x.convert(inch) - odometry::currX.convert(inch), 2) + pow(endPoint.y.convert(inch) - odometry::currY.convert(inch), 2));
	if (distance < 1.5)
	{ // stop as soon as 1.5 inch away from endpoint
		return true;
	}
	return false;
}
} // namespace pathfollowing
