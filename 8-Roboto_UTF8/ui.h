// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

extern lv_obj_t * ui_Screen1;
extern lv_obj_t * ui_Label1;
extern lv_obj_t * ui_Image2;


LV_IMG_DECLARE(ui_img_isubulogo_png);    // assets\isubulogo.png


LV_FONT_DECLARE(ui_font_times);
LV_FONT_DECLARE(ui_font_Saira);
LV_FONT_DECLARE(ui_font_Roboto);


void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
