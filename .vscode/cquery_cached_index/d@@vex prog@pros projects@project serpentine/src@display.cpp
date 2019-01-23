#include "main.h"

LV_IMG_DECLARE(fieldResizedIMG);
LV_IMG_DECLARE(redNearIMG);

bool readyBtnExists = false;

lv_obj_t *titleLabel = lv_label_create(lv_scr_act(), NULL);

lv_obj_t *redNearBtn = lv_btn_create(lv_scr_act(), NULL);
//--
lv_obj_t *redNear1Btn = lv_btn_create(lv_scr_act(), NULL);
lv_obj_t *redNear2Btn = lv_btn_create(lv_scr_act(), NULL);
lv_obj_t *progSkillsBtn = lv_btn_create(lv_scr_act(), NULL);

lv_obj_t *redFarBtn = lv_btn_create(lv_scr_act(), NULL);
//--
lv_obj_t *redFar1Btn = lv_btn_create(lv_scr_act(), NULL);
lv_obj_t *redFar2Btn = lv_btn_create(lv_scr_act(), NULL);

lv_obj_t *blueNearBtn = lv_btn_create(lv_scr_act(), NULL);
//--
lv_obj_t *blueNear1Btn = lv_btn_create(lv_scr_act(), NULL);
lv_obj_t *blueNear2Btn = lv_btn_create(lv_scr_act(), NULL);

lv_obj_t *blueFarBtn = lv_btn_create(lv_scr_act(), NULL);
//--
lv_obj_t *blueFar1Btn = lv_btn_create(lv_scr_act(), NULL);
lv_obj_t *blueFar2Btn = lv_btn_create(lv_scr_act(), NULL);

lv_obj_t *fieldPic = lv_img_create(lv_scr_act(), NULL);

lv_style_t pathStyle;

lv_res_t readySelect(lv_obj_t *btn) {

  // printf("READY\n");
  switch (autonRoutine) {
  case notSelected:
    printf("NS\n");
    break;

  case progSkills:
    printf("PS\n");
    initProgSkills();
    break;

  case redNear1:
    printf("RN1\n");
    initRedNear1();
    break;

  case redNear2:
    printf("RN2\n");
    initRedNear2();
    break;

  case redFar1:
    initRedFar1();
    printf("RF1\n");
    break;

  case redFar2:
    initRedFar2();
    printf("RF2\n");
    break;

  case blueNear1:
    initBlueNear1();
    printf("BN1\n");
    break;

  case blueNear2:
    initBlueNear2();
    printf("BN2\n");
    break;

  case blueFar1:
    initBlueFar1();
    printf("BF1\n");
    break;

  case blueFar2:
    initBlueFar2();
    printf("BF2\n");
    break;
  }

  lv_btn_set_state(btn, LV_BTN_STATE_INA);

  // lv_scr_act();

  return LV_RES_OK; /*Return OK if the button is not deleted*/
}

lv_res_t secondaryBtnToggle(lv_obj_t *btn) {

  if (btn == redNear1Btn) {
    lv_btn_set_state(redNear2Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(progSkillsBtn, LV_BTN_STATE_REL);
    lv_btn_set_state(redFar1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(redFar2Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueNear1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueNear2Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueFar1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueFar2Btn, LV_BTN_STATE_REL);
    autonRoutine = redNear1;

    displayRedNear1();
  }
  if (btn == redNear2Btn) {
    lv_btn_set_state(redNear1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(progSkillsBtn, LV_BTN_STATE_REL);
    lv_btn_set_state(redFar1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(redFar2Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueNear1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueNear2Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueFar1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueFar2Btn, LV_BTN_STATE_REL);
    autonRoutine = redNear2;
  }
  if (btn == progSkillsBtn) {
    lv_btn_set_state(redNear1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(redNear2Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(redFar1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(redFar2Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueNear1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueNear2Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueFar1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueFar2Btn, LV_BTN_STATE_REL);
    autonRoutine = progSkills;
  }
  if (btn == redFar1Btn) {
    lv_btn_set_state(redNear1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(redNear2Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(progSkillsBtn, LV_BTN_STATE_REL);
    lv_btn_set_state(redFar2Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueNear1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueNear2Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueFar1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueFar2Btn, LV_BTN_STATE_REL);
    autonRoutine = redFar1;
  }
  if (btn == redFar2Btn) {
    lv_btn_set_state(redNear1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(redNear2Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(progSkillsBtn, LV_BTN_STATE_REL);
    lv_btn_set_state(redFar1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueNear1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueNear2Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueFar1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueFar2Btn, LV_BTN_STATE_REL);
    autonRoutine = redFar2;
  }
  if (btn == blueNear1Btn) {
    lv_btn_set_state(redNear1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(redNear2Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(progSkillsBtn, LV_BTN_STATE_REL);
    lv_btn_set_state(redFar1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(redFar2Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueNear2Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueFar1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueFar2Btn, LV_BTN_STATE_REL);
    autonRoutine = blueNear1;
  }
  if (btn == blueNear2Btn) {
    lv_btn_set_state(redNear1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(redNear2Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(progSkillsBtn, LV_BTN_STATE_REL);
    lv_btn_set_state(redFar1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(redFar2Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueNear1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueFar1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueFar2Btn, LV_BTN_STATE_REL);
    autonRoutine = blueNear2;
  }
  if (btn == blueFar1Btn) {
    lv_btn_set_state(redNear1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(redNear2Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(progSkillsBtn, LV_BTN_STATE_REL);
    lv_btn_set_state(redFar1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(redFar2Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueNear1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueNear2Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueFar2Btn, LV_BTN_STATE_REL);
    autonRoutine = blueFar1;
  }
  if (btn == blueFar2Btn) {
    lv_btn_set_state(redNear1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(redNear2Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(progSkillsBtn, LV_BTN_STATE_REL);
    lv_btn_set_state(redFar1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(redFar2Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueNear1Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueNear2Btn, LV_BTN_STATE_REL);
    lv_btn_set_state(blueFar1Btn, LV_BTN_STATE_REL);
    autonRoutine = blueFar2;
  }

  lv_img_set_src(fieldPic, &redNearIMG);

  lv_btn_set_state(btn, LV_BTN_STATE_TGL_REL); /*Set toggled state*/

  lv_obj_align(fieldPic, lv_scr_act(), LV_ALIGN_IN_BOTTOM_MID, 0, -2);

  lv_obj_set_hidden(titleLabel, true);

  // if (readyBtnExists == false) {
  readyBtnExists = true;
  lv_obj_t *readyBtn = lv_btn_create(lv_scr_act(), NULL);
  lv_obj_set_size(readyBtn, 200, 36);
  lv_obj_t *readyBtnLabel = lv_label_create(readyBtn, NULL);
  lv_label_set_text(readyBtnLabel, "Ready?");
  lv_obj_align(readyBtn, lv_scr_act(), LV_ALIGN_IN_TOP_MID, 0, 1);
  lv_btn_set_action(readyBtn, LV_BTN_ACTION_CLICK, readySelect);
  // }

  return LV_RES_OK; /*Return OK if the button is not deleted*/
}

lv_res_t mainBtnToggle(lv_obj_t *btn) {

  lv_style_copy(&pathStyle, &lv_style_plain);
  pathStyle.line.color = LV_COLOR_HEX(0x000000);
  pathStyle.line.width = 6;

  /* The button is released.
   * Make something here */

  lv_btn_set_state(btn, LV_BTN_STATE_TGL_REL); /*Set toggled state*/

  if (btn == redNearBtn) {

    lv_obj_set_hidden(redFar1Btn, true);
    lv_obj_set_hidden(redFar2Btn, true);

    lv_obj_set_hidden(blueNear1Btn, true);
    lv_obj_set_hidden(blueNear2Btn, true);

    lv_obj_set_hidden(blueFar1Btn, true);
    lv_obj_set_hidden(blueFar2Btn, true);

    // lv_img_set_src(fieldPic, &redNear1);
    printf("Button Red Near Pressed\n");
    lv_btn_set_state(redFarBtn, LV_BTN_STATE_REL);   /*Set untoggled state*/
    lv_btn_set_state(blueNearBtn, LV_BTN_STATE_REL); /*Set untoggled state*/
    lv_btn_set_state(blueFarBtn, LV_BTN_STATE_REL);  /*Set untoggled state*/

    lv_obj_set_hidden(redNear1Btn, false);
    lv_obj_set_hidden(redNear2Btn, false);
    lv_obj_set_hidden(progSkillsBtn, false);

    lv_obj_set_size(redNear1Btn, 40, 40);
    lv_obj_t *redNear1BtnLabel = lv_label_create(redNear1Btn, NULL);
    lv_label_set_text(redNear1BtnLabel, "1");
    lv_obj_align(redNear1Btn, lv_scr_act(), LV_ALIGN_IN_LEFT_MID, 8, 0);
    lv_btn_set_action(redNear1Btn, LV_BTN_ACTION_CLICK, secondaryBtnToggle);

    lv_obj_set_size(redNear2Btn, 40, 40);
    lv_obj_t *redNear2BtnLabel = lv_label_create(redNear2Btn, NULL);
    lv_label_set_text(redNear2BtnLabel, "2");
    lv_obj_align(redNear2Btn, lv_scr_act(), LV_ALIGN_IN_LEFT_MID, 50, 0);
    lv_btn_set_action(redNear2Btn, LV_BTN_ACTION_CLICK, secondaryBtnToggle);

    lv_obj_set_size(progSkillsBtn, 40, 40);
    lv_obj_t *progSkillsBtnLabel = lv_label_create(progSkillsBtn, NULL);
    lv_label_set_text(progSkillsBtnLabel, "PS");
    lv_obj_align(progSkillsBtn, lv_scr_act(), LV_ALIGN_IN_LEFT_MID, 92, 0);
    lv_btn_set_action(progSkillsBtn, LV_BTN_ACTION_CLICK, secondaryBtnToggle);
  }

  if (btn == redFarBtn) {
    // lv_img_set_src(fieldPic, &redNear1);

    lv_obj_set_hidden(redNear1Btn, true);
    lv_obj_set_hidden(redNear2Btn, true);
    lv_obj_set_hidden(progSkillsBtn, true);

    lv_obj_set_hidden(blueNear1Btn, true);
    lv_obj_set_hidden(blueNear2Btn, true);

    lv_obj_set_hidden(blueFar1Btn, true);
    lv_obj_set_hidden(blueFar2Btn, true);

    printf("Button Red Far Pressed\n");
    lv_btn_set_state(redNearBtn, LV_BTN_STATE_REL);  /*Set untoggled state*/
    lv_btn_set_state(blueNearBtn, LV_BTN_STATE_REL); /*Set untoggled state*/
    lv_btn_set_state(blueFarBtn, LV_BTN_STATE_REL);  /*Set untoggled state*/

    lv_obj_set_hidden(redFar1Btn, false);
    lv_obj_set_hidden(redFar2Btn, false);

    // lv_cont_set_fit(redNear1Btn, true, true);
    lv_obj_set_size(redFar1Btn, 40, 40);
    lv_obj_t *redFar1BtnLabel = lv_label_create(redFar1Btn, NULL);
    lv_label_set_text(redFar1BtnLabel, "1");
    lv_obj_align(redFar1Btn, lv_scr_act(), LV_ALIGN_IN_LEFT_MID, 8, 0);
    lv_btn_set_action(redFar1Btn, LV_BTN_ACTION_CLICK, secondaryBtnToggle);

    lv_obj_set_size(redFar2Btn, 40, 40);
    lv_obj_t *redFar2BtnLabel = lv_label_create(redFar2Btn, NULL);
    lv_label_set_text(redFar2BtnLabel, "2");
    lv_obj_align(redFar2Btn, lv_scr_act(), LV_ALIGN_IN_LEFT_MID, 92, 0);
    lv_btn_set_action(redFar2Btn, LV_BTN_ACTION_CLICK, secondaryBtnToggle);
  }

  if (btn == blueNearBtn) {

    lv_obj_set_hidden(redNear1Btn, true);
    lv_obj_set_hidden(redNear2Btn, true);
    lv_obj_set_hidden(progSkillsBtn, true);

    lv_obj_set_hidden(redFar1Btn, true);
    lv_obj_set_hidden(redFar2Btn, true);

    lv_obj_set_hidden(blueFar1Btn, true);
    lv_obj_set_hidden(blueFar2Btn, true);

    printf("Button Blue Near Pressed\n");
    lv_btn_set_state(redNearBtn, LV_BTN_STATE_REL); /*Set untoggled state*/
    lv_btn_set_state(redFarBtn, LV_BTN_STATE_REL);  /*Set untoggled state*/
    lv_btn_set_state(blueFarBtn, LV_BTN_STATE_REL); /*Set untoggled state*/

    lv_obj_set_hidden(blueNear1Btn, false);
    lv_obj_set_hidden(blueNear2Btn, false);

    lv_obj_set_size(blueNear1Btn, 40, 40);
    lv_obj_t *blueNear1BtnLabel = lv_label_create(blueNear1Btn, NULL);
    lv_label_set_text(blueNear1BtnLabel, "1");
    lv_obj_align(blueNear1Btn, lv_scr_act(), LV_ALIGN_IN_RIGHT_MID, -92, 0);
    lv_btn_set_action(blueNear1Btn, LV_BTN_ACTION_CLICK, secondaryBtnToggle);

    lv_obj_set_size(blueNear2Btn, 40, 40);
    lv_obj_t *blueNear2BtnLabel = lv_label_create(blueNear2Btn, NULL);
    lv_label_set_text(blueNear2BtnLabel, "2");
    lv_obj_align(blueNear2Btn, lv_scr_act(), LV_ALIGN_IN_RIGHT_MID, -8, 0);
    lv_btn_set_action(blueNear2Btn, LV_BTN_ACTION_CLICK, secondaryBtnToggle);
  }

  if (btn == blueFarBtn) {

    lv_obj_set_hidden(redNear1Btn, true);
    lv_obj_set_hidden(redNear2Btn, true);
    lv_obj_set_hidden(progSkillsBtn, true);

    lv_obj_set_hidden(redFar1Btn, true);
    lv_obj_set_hidden(redFar2Btn, true);

    lv_obj_set_hidden(blueNear1Btn, true);
    lv_obj_set_hidden(blueNear2Btn, true);

    printf("Button Blue Far Pressed\n");
    lv_btn_set_state(redNearBtn, LV_BTN_STATE_REL);  /*Set untoggled state*/
    lv_btn_set_state(redFarBtn, LV_BTN_STATE_REL);   /*Set untoggled state*/
    lv_btn_set_state(blueNearBtn, LV_BTN_STATE_REL); /*Set untoggled state*/

    lv_obj_set_hidden(blueFar1Btn, false);
    lv_obj_set_hidden(blueFar2Btn, false);

    lv_obj_set_size(blueFar1Btn, 40, 40);
    lv_obj_t *blueFar1BtnLabel = lv_label_create(blueFar1Btn, NULL);
    lv_label_set_text(blueFar1BtnLabel, "1");
    lv_obj_align(blueFar1Btn, lv_scr_act(), LV_ALIGN_IN_RIGHT_MID, -92, 0);
    lv_btn_set_action(blueFar1Btn, LV_BTN_ACTION_CLICK, secondaryBtnToggle);

    lv_obj_set_size(blueFar2Btn, 40, 40);
    lv_obj_t *blueFar2BtnLabel = lv_label_create(blueFar2Btn, NULL);
    lv_label_set_text(blueFar2BtnLabel, "2");
    lv_obj_align(blueFar2Btn, lv_scr_act(), LV_ALIGN_IN_RIGHT_MID, -8, 0);
    lv_btn_set_action(blueFar2Btn, LV_BTN_ACTION_CLICK, secondaryBtnToggle);
  }

  return LV_RES_OK; /*Return OK if the button is not deleted*/
}

void autonSelector() {
  lv_scr_act();

  lv_obj_set_hidden(redNear1Btn, true);
  lv_obj_set_hidden(redNear2Btn, true);
  lv_obj_set_hidden(progSkillsBtn, true);

  lv_obj_set_hidden(redFar1Btn, true);
  lv_obj_set_hidden(redFar2Btn, true);

  lv_obj_set_hidden(blueNear1Btn, true);
  lv_obj_set_hidden(blueNear2Btn, true);

  lv_obj_set_hidden(blueFar1Btn, true);
  lv_obj_set_hidden(blueFar2Btn, true);

  lv_label_set_text(titleLabel, "Select Auton:");
  lv_obj_align(titleLabel, lv_scr_act(), LV_ALIGN_IN_TOP_MID, 0, 5);

  lv_cont_set_fit(redNearBtn, false, true);
  lv_obj_t *redNearBtnLabel = lv_label_create(redNearBtn, NULL);
  lv_label_set_text(redNearBtnLabel, "Red Near");
  lv_obj_align(redNearBtn, lv_scr_act(), LV_ALIGN_IN_TOP_LEFT, 8, 15);
  lv_btn_set_action(redNearBtn, LV_BTN_ACTION_CLICK, mainBtnToggle);

  lv_cont_set_fit(redFarBtn, false, true);
  lv_obj_t *redFarBtnLabel = lv_label_create(redFarBtn, NULL);
  lv_label_set_text(redFarBtnLabel, "Red Far");
  lv_obj_align(redFarBtn, lv_scr_act(), LV_ALIGN_IN_BOTTOM_LEFT, 8, -15);
  lv_btn_set_action(redFarBtn, LV_BTN_ACTION_CLICK, mainBtnToggle);

  lv_cont_set_fit(blueNearBtn, false, true);
  lv_obj_t *blueNearBtnLabel = lv_label_create(blueNearBtn, NULL);
  lv_label_set_text(blueNearBtnLabel, "Blue Near");
  lv_obj_align(blueNearBtn, lv_scr_act(), LV_ALIGN_IN_TOP_RIGHT, -8, 15);
  lv_btn_set_action(blueNearBtn, LV_BTN_ACTION_CLICK, mainBtnToggle);

  lv_cont_set_fit(blueFarBtn, false, true);
  lv_obj_t *blueFarBtnLabel = lv_label_create(blueFarBtn, NULL);
  lv_label_set_text(blueFarBtnLabel, "Blue Far");
  lv_obj_align(blueFarBtn, lv_scr_act(), LV_ALIGN_IN_BOTTOM_RIGHT, -8, -15);
  lv_btn_set_action(blueFarBtn, LV_BTN_ACTION_CLICK, mainBtnToggle);

  lv_img_set_src(fieldPic, &fieldResizedIMG);
  lv_obj_align(fieldPic, lv_scr_act(), LV_ALIGN_IN_TOP_MID, 0, 25);
}

void lcdCode2() {
  lv_scr_act();
  /*Create an array for the points of the line*/
  static lv_point_t line_points[] = {
      {5, 5}, {70, 70}, {120, 10}, {180, 60}, {240, 10}};

  static lv_style_t pathStyle;
  lv_style_copy(&pathStyle, &lv_style_plain);
  pathStyle.line.color = LV_COLOR_MAKE(0x2e, 0x3b, 0x75);
  pathStyle.line.width = 5;

  /*Create line with default style*/
  lv_obj_t *line1;
  line1 = lv_line_create(lv_scr_act(), NULL);
  lv_line_set_style(line1, &pathStyle);
  lv_line_set_points(line1, line_points, 5); /*Set the points*/
  lv_obj_align(line1, NULL, LV_ALIGN_IN_TOP_MID, 0, 20);
}

void displayRedNear1() {
  // path1
  // static lv_point_t path1Points[] = {
  //     {0, 0}, {60, 0}, {20, 0}, {15, -60}, {20, 0}};
  //
  // lv_obj_t *path1 = lv_line_create(lv_scr_act(), NULL);
  // lv_line_set_style(path1, &pathStyle);
  // lv_line_set_points(path1, path1Points, 5);
  // lv_obj_align(path1, fieldPic, LV_ALIGN_IN_TOP_LEFT, 16,
  //              82); // set start point
}
