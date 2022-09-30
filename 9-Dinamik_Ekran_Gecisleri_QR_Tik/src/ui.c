// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: KGS_Ekran_Tasarimi

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_anaEkran;
void ui_event_tarihSaat(lv_event_t * e);
lv_obj_t * ui_tarihSaat;
void ui_event_mesaj(lv_event_t * e);
lv_obj_t * ui_mesaj;
lv_obj_t * ui_imageTik;
lv_obj_t * ui_imageWifi;
lv_obj_t * qr;
///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
#error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
#error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_tarihSaat(lv_event_t * e)
{
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t * target = lv_event_get_target(e);
  if (event_code == LV_EVENT_CLICKED) {
    _ui_flag_modify(ui_imageTik, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    _ui_flag_modify(ui_imageWifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
  }
}
void ui_event_mesaj(lv_event_t * e)
{
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t * target = lv_event_get_target(e);
  if (event_code == LV_EVENT_CLICKED) {
    _ui_flag_modify(ui_imageWifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    _ui_flag_modify(ui_imageTik, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
  }
}

void dinamik_ekran_ayarlari(bool durum, const char* mesaj)
{
  if (durum) { //ANA EKRAN MESAJI
    _ui_flag_modify(ui_imageTik, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD); //tik kaldır
    _ui_flag_modify(qr, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);      //QR göster
  }
  else { //QR Okutunuz mesajı
    _ui_flag_modify(qr, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    _ui_flag_modify(ui_imageTik, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);


  }
  lv_label_set_text(ui_mesaj, mesaj);
}

void lv_example_qrcode_1(void)
{   
    lv_color_t bg_color = lv_color_hsv_to_rgb(219,59,27);
    //lv_color_t bg_color = lv_palette_lighten(LV_PALETTE_LIGHT_BLUE, 5);
    lv_color_t fg_color = lv_color_hsv_to_rgb(0,0,100);

    qr = lv_qrcode_create(ui_anaEkran, 120, fg_color, bg_color);

    /*Set data*/
    const char * data = "HOSGELDINIZ";
    lv_qrcode_update(qr, data, strlen(data));
    lv_obj_set_x(qr, 0);
    lv_obj_set_y(qr, -30);
    lv_obj_set_align(qr, LV_ALIGN_CENTER);

    /*Add a border with bg_color*/
    lv_obj_set_style_border_color(qr, bg_color, 0);
    lv_obj_set_style_border_width(qr, 5, 0);
}



///////////////////// SCREENS ////////////////////
void ui_anaEkran_screen_init(void)
{
  ui_anaEkran = lv_obj_create(NULL);
  lv_obj_clear_flag(ui_anaEkran, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
  lv_obj_set_style_bg_color(ui_anaEkran, lv_color_hex(0x1c2a44), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_anaEkran, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_example_qrcode_1();

  ui_tarihSaat = lv_label_create(ui_anaEkran);
  lv_obj_set_width(ui_tarihSaat, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_tarihSaat, LV_SIZE_CONTENT);    /// 1
  lv_obj_set_x(ui_tarihSaat, -160);
  lv_obj_set_y(ui_tarihSaat, -139);
  lv_obj_set_align(ui_tarihSaat, LV_ALIGN_CENTER);
  lv_label_set_text(ui_tarihSaat, "28.08.2022  12:00");
  lv_obj_add_flag(ui_tarihSaat, LV_OBJ_FLAG_CLICKABLE);     /// Flags
  lv_obj_set_style_text_color(ui_tarihSaat, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_tarihSaat, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_tarihSaat, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_mesaj = lv_label_create(ui_anaEkran);
  lv_obj_set_width(ui_mesaj, lv_pct(94));
  lv_obj_set_height(ui_mesaj, LV_SIZE_CONTENT);    /// 1
  lv_obj_set_x(ui_mesaj, 0);
  lv_obj_set_y(ui_mesaj, 72);
  lv_obj_set_align(ui_mesaj, LV_ALIGN_CENTER);
  lv_label_set_text(ui_mesaj, "ISPARTA UYGULAMALI BİLİMLER ÜNİVERSİTESİ BİLGİ İŞLEM DAİRE BAŞKANLIĞI");
  lv_obj_add_flag(ui_mesaj, LV_OBJ_FLAG_CLICKABLE);     /// Flags
  lv_obj_set_style_text_color(ui_mesaj, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_mesaj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_align(ui_mesaj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_mesaj, &ui_font_GothamNarrow, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_imageTik = lv_img_create(ui_anaEkran);
  lv_img_set_src(ui_imageTik, &ui_img_110_png);
  lv_obj_set_width(ui_imageTik, LV_SIZE_CONTENT);   /// 110
  lv_obj_set_height(ui_imageTik, LV_SIZE_CONTENT);    /// 110
  lv_obj_set_x(ui_imageTik, 0);
  lv_obj_set_y(ui_imageTik, -30);
  lv_obj_set_align(ui_imageTik, LV_ALIGN_CENTER);
  lv_obj_add_flag(ui_imageTik, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
  lv_obj_clear_flag(ui_imageTik, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

  lv_obj_add_event_cb(ui_tarihSaat, ui_event_tarihSaat, LV_EVENT_ALL, NULL);
  lv_obj_add_event_cb(ui_mesaj, ui_event_mesaj, LV_EVENT_ALL, NULL);

}

void ui_init(void)
{
  lv_disp_t * dispp = lv_disp_get_default();
  lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                       false, LV_FONT_DEFAULT);
  lv_disp_set_theme(dispp, theme);
  ui_anaEkran_screen_init();
  lv_disp_load_scr(ui_anaEkran);
}
