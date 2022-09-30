
#include <lvgl.h>
#include <TFT_eSPI.h>

/*Ekran Çözünürlüğü*/
static const uint16_t screenWidth  = 480;
static const uint16_t screenHeight = 320;

TFT_eSPI tft = TFT_eSPI(); // TFT instance
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * 10 ];

/* Display flushing */
void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p )
{
  uint32_t w = ( area->x2 - area->x1 + 1 );
  uint32_t h = ( area->y2 - area->y1 + 1 );

  tft.startWrite();
  tft.setAddrWindow( area->x1, area->y1, w, h );
  tft.pushColors( ( uint16_t * )&color_p->full, w * h, true );
  tft.endWrite();

  lv_disp_flush_ready( disp );
}

/*Read the touchpad*/
void my_touchpad_read( lv_indev_drv_t * indev_driver, lv_indev_data_t * data )
{
  uint16_t touchX, touchY;
  bool touched = tft.getTouch( &touchX, &touchY, 600 );

  if ( !touched )  {
    data->state = LV_INDEV_STATE_REL;
  }
  else
  {
    data->state = LV_INDEV_STATE_PR;
    /*Set the coordinates*/
    data->point.x = touchX;
    data->point.y = touchY;

    Serial.print( "Data x " );    Serial.println( touchX );
    Serial.print( " - Data y " ); Serial.println( touchY );
  }
}

void setup() {

  Serial.begin(115200);
  String LVGL_Arduino = "Hello ESP32! ";
  LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();

  lv_init();
  tft.begin();
  tft.setRotation(3); /*Ekran  Landscape orientation */

  /*Ekran kalibrasyon
     Generic -> Touch_calibrate example from the TFT_eSPI library*/
  uint16_t calData[5] = { 299, 3588, 348, 3474, 1 };
  tft.setTouch( calData );

  lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth * 10 );

  /*Initialize the display*/
  static lv_disp_drv_t disp_drv;     //HAL tarafından kaydedilen Display driver struct'ıdır.
  lv_disp_drv_init( &disp_drv );
  /*Ekran çözünürlüğüne göre aşağıdaki kodları değiştiriniz*/
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush; //Ekran flash'lama
  disp_drv.draw_buf = &draw_buf;     //Kullanılacak buffer
  lv_disp_drv_register( &disp_drv );

  /*Initialize the (dummy) input device driver
     Kurulum ve kayıt için cihaz girdi sürücüleri, 4 tür girdi vardır.
     LV_INDEV_TYPE_POINTER(Touchpad veya mouse)
     LV_INDEV_TYPE_KEYPAD (klavye veya tuş takımı)
     LV_INDEV_TYPE_ENCODER (sağ, sol, buton özellikleri olan)
     LV_INDEV_TYPE_BUTTON (ekrana basan harici butonlar)
  */
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init( &indev_drv );
  indev_drv.type = LV_INDEV_TYPE_POINTER; //Cihaz girdisi olarak POINTER Seçilmiş
  indev_drv.read_cb = my_touchpad_read;   //Girdi olarak Touchpad kullanılacak
  lv_indev_drv_register( &indev_drv );

  /* Create simple label */
  lv_obj_t *label = lv_label_create(lv_scr_act());
  lv_obj_set_width(label, 150);
  lv_label_set_text(label, LVGL_Arduino.c_str());
  lv_obj_align(label, LV_ALIGN_CENTER, 0, 0 );
}

void loop() {
  lv_task_handler(); /* let the GUI do its work */
  delay(5);
}
