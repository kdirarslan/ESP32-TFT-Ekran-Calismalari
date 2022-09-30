// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: KGS_Ekran_Tasarimi

#ifndef _KGS_EKRAN_TASARIMI_UI_H
#define _KGS_EKRAN_TASARIMI_UI_H

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
extern lv_obj_t * ui_anaEkran;
void ui_event_tarihSaat(lv_event_t * e);
extern lv_obj_t * ui_tarihSaat;
void ui_event_mesaj(lv_event_t * e);
extern lv_obj_t * ui_mesaj;
extern lv_obj_t * ui_imageTik;
extern lv_obj_t * qr;

LV_IMG_DECLARE(ui_img_110_png);    // assets\110.png


LV_FONT_DECLARE(ui_font_GothamNarrow);
LV_FONT_DECLARE(ui_font_GothamNarrowSmall);


void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
