// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: ikiekran

#ifndef _IKIEKRAN_UI_H
#define _IKIEKRAN_UI_H

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
void dinamik_ekran_ayarlari(bool durum, const char* mesaj);
void ui_event_hosgeldiniz(lv_event_t * e);
extern lv_obj_t * ui_hosgeldiniz;
extern lv_obj_t * ui_Label1;
void ui_event_gecisizniyok(lv_event_t * e);
extern lv_obj_t * ui_gecisizniyok;
extern lv_obj_t * ui_Image1;
extern lv_obj_t * ui_uyarimesaji;
void ui_event_geciniz(lv_event_t * e);
extern lv_obj_t * ui_geciniz;
extern lv_obj_t * ui_Label2;
extern lv_obj_t * ui_Image3;


LV_IMG_DECLARE(ui_img_exclamation_png);    // assets\exclamation.png
LV_IMG_DECLARE(ui_img_isubulogo_png);    // assets\isubulogo.png


void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
