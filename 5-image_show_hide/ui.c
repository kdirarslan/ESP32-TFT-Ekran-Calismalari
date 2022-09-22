// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: ikiekran

#include "ui.h"
#include "ui_helpers.h"
///////////////////// VARIABLES ////////////////////
//void dinamik_ekran_ayarlari(const char* anaMesaj);
void ui_event_hosgeldiniz(lv_event_t * e);
lv_obj_t * ui_hosgeldiniz;
lv_obj_t * ui_Label1;
void ui_event_gecisizniyok(lv_event_t * e);
lv_obj_t * ui_gecisizniyok;
lv_obj_t * ui_Image1;
lv_obj_t * ui_uyarimesaji;
void ui_event_geciniz(lv_event_t * e);
lv_obj_t * ui_geciniz;
lv_obj_t * ui_Label2;
lv_obj_t * ui_Image3;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
#error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
#error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
/*
  void ui_event_hosgeldiniz(lv_event_t * e)
  {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t * target = lv_event_get_target(e);
  if (event_code == LV_EVENT_SCREEN_LOADED) {
    _ui_screen_change(ui_geciniz, LV_SCR_LOAD_ANIM_NONE, 2000, NULL);
  }
  }
  void ui_event_gecisizniyok(lv_event_t * e)
  {
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        _ui_screen_change(ui_hosgeldiniz, LV_SCR_LOAD_ANIM_NONE, 2000, NULL);
    }
  }
  void ui_event_geciniz(lv_event_t * e)
  {
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        _ui_screen_change(ui_gecisizniyok, LV_SCR_LOAD_ANIM_NONE, 2000, NULL);
    }
  }*/

void dinamik_ekran_ayarlari(bool durum)
{
  if (durum) {
    _ui_flag_modify(ui_Image3, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    lv_label_set_text(ui_Label1, "HOSGELDINIZ");
  }
  else {
    _ui_flag_modify(ui_Image3, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    lv_label_set_text(ui_Label1, "GECINIZ");
  }
}

///////////////////// SCREENS ////////////////////
void ui_hosgeldiniz_screen_init(void)
{
  ui_hosgeldiniz = lv_obj_create(NULL);
  lv_obj_clear_flag(ui_hosgeldiniz, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
  lv_obj_set_style_radius(ui_hosgeldiniz, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_hosgeldiniz, lv_color_hex(0xDCDEE0), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_hosgeldiniz, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_Label1 = lv_label_create(ui_hosgeldiniz);
  lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
  lv_obj_set_x(ui_Label1, 0);
  lv_obj_set_y(ui_Label1, -101);
  lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);
  lv_label_set_text(ui_Label1, "HOSGELDINIZ");
  lv_obj_add_flag(ui_Label1, LV_OBJ_FLAG_CLICKABLE);     /// Flags
  lv_obj_set_style_text_color(ui_Label1, lv_color_hex(0x1903C9), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_Label1, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_Image3 = lv_img_create(ui_hosgeldiniz);
  lv_img_set_src(ui_Image3, &ui_img_isubulogo_png);
  //lv_img_set_src(ui_Image3, "/spiffs/resimler/isubulogo.png");
  lv_obj_set_width(ui_Image3, LV_SIZE_CONTENT);   /// 120
  lv_obj_set_height(ui_Image3, LV_SIZE_CONTENT);    /// 142
  lv_obj_set_x(ui_Image3, 0);
  lv_obj_set_y(ui_Image3, 36);
  lv_obj_set_align(ui_Image3, LV_ALIGN_CENTER);
  lv_obj_add_flag(ui_Image3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
  lv_obj_clear_flag(ui_Image3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

  //lv_obj_add_event_cb(ui_hosgeldiniz, ui_event_hosgeldiniz, LV_EVENT_ALL, NULL);

}
void ui_gecisizniyok_screen_init(void)
{
  ui_gecisizniyok = lv_obj_create(NULL);
  lv_obj_clear_flag(ui_gecisizniyok, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
  lv_obj_set_style_radius(ui_gecisizniyok, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_gecisizniyok, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_gecisizniyok, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_Image1 = lv_img_create(ui_gecisizniyok);
  lv_img_set_src(ui_Image1, &ui_img_exclamation_png);
  lv_obj_set_width(ui_Image1, LV_SIZE_CONTENT);   /// 64
  lv_obj_set_height(ui_Image1, LV_SIZE_CONTENT);    /// 64
  lv_obj_set_x(ui_Image1, 0);
  lv_obj_set_y(ui_Image1, -90);
  lv_obj_set_align(ui_Image1, LV_ALIGN_CENTER);
  lv_obj_add_flag(ui_Image1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
  lv_obj_clear_flag(ui_Image1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

  ui_uyarimesaji = lv_label_create(ui_gecisizniyok);
  lv_obj_set_width(ui_uyarimesaji, lv_pct(88));
  lv_obj_set_height(ui_uyarimesaji, lv_pct(53));
  lv_obj_set_x(ui_uyarimesaji, 0);
  lv_obj_set_y(ui_uyarimesaji, 45);
  lv_obj_set_align(ui_uyarimesaji, LV_ALIGN_CENTER);
  lv_label_set_text(ui_uyarimesaji, "GECIS IZNINIZ YOK LUTFEN SISTEM YETKILISI ILE GORUSUNUZ");
  lv_obj_set_style_text_color(ui_uyarimesaji, lv_color_hex(0xFEFEFE), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_uyarimesaji, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_uyarimesaji, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

  //lv_obj_add_event_cb(ui_gecisizniyok, ui_event_gecisizniyok, LV_EVENT_ALL, NULL);
}

void ui_geciniz_screen_init(void)
{
  ui_geciniz = lv_obj_create(NULL);
  lv_obj_clear_flag(ui_geciniz, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
  lv_obj_set_style_radius(ui_geciniz, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_geciniz, lv_color_hex(0xDCDEE0), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_geciniz, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_Label2 = lv_label_create(ui_geciniz);
  lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
  lv_obj_set_x(ui_Label2, 0);
  lv_obj_set_y(ui_Label2, -101);
  lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
  lv_label_set_text(ui_Label2, "GECINIZ");
  lv_obj_add_flag(ui_Label2, LV_OBJ_FLAG_CLICKABLE);     /// Flags
  lv_obj_set_style_text_color(ui_Label2, lv_color_hex(0x1903C9), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_Label2, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);

  //fex.drawJpgFile(SPIFFS, "/resimler/isubulogo.png", 0, 36);
  /*
    ui_Image3 = lv_img_create(ui_geciniz);
    lv_img_set_src(ui_Image3, &ui_img_isubulogo_png);
    //lv_img_set_src(ui_Image3, "/spiffs/resimler/isubulogo.png");
    lv_obj_set_width(ui_Image3, LV_SIZE_CONTENT);   /// 120
    lv_obj_set_height(ui_Image3, LV_SIZE_CONTENT);    /// 142
    lv_obj_set_x(ui_Image3, 0);
    lv_obj_set_y(ui_Image3, 36);
    lv_obj_set_align(ui_Image3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
  */
  //lv_obj_add_event_cb(ui_geciniz, ui_event_geciniz, LV_EVENT_ALL, NULL);

}

void ui_init(void)
{
  lv_disp_t * dispp = lv_disp_get_default();
  lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                       false, LV_FONT_DEFAULT);
  lv_disp_set_theme(dispp, theme);
  ui_hosgeldiniz_screen_init();
  ui_gecisizniyok_screen_init();
  ui_geciniz_screen_init();
  lv_disp_load_scr(ui_hosgeldiniz);
}
