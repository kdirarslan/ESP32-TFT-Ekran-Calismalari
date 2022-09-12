#include <lvgl.h>
#include <SPI.h>
/*Ekran Çözünürlüğü*/
static const uint16_t screenWidth  = 480;
static const uint16_t screenHeight = 320;

#include <TFT_eSPI.h>
TFT_eSPI tft = TFT_eSPI(); // TFT instance
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * 10 ];

static lv_obj_t * label;

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
  else {
    data->state = LV_INDEV_STATE_PR;
    /*Set the coordinates*/
    data->point.x = touchX;
    data->point.y = touchY;

    Serial.print("Data x ");   Serial.print(touchX);
    Serial.print(" - Data y ");Serial.println(touchY);
  }
}

void setup() {

  Serial.begin(115200);
  lv_init();
  tft.begin();
  tft.setRotation(1); /*Ekran Landscape(Yatay) olacak */

  /*Ekran kalibrasyonu için TFT_eSPI örnekleri içerisinden Generic -> Touch_calibrate*/
  uint16_t calData[5] = { 222, 3375, 445, 3250, 0 };
  tft.setTouch( calData );

  lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth * 10 );

  /*Initialize the display*/
  static lv_disp_drv_t disp_drv;    //HAL tarafından kaydedilen Display driver struct.
  lv_disp_drv_init( &disp_drv );
  /*Ekran çözünürlüğüne göre aşağıdaki kodları değiştiriniz*/
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush; //Ekran flash'lama
  disp_drv.draw_buf = &draw_buf;     //Kullanılacak buffer
  lv_disp_drv_register( &disp_drv );

  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init( &indev_drv );
  indev_drv.type = LV_INDEV_TYPE_POINTER; //Cihaz girdisi olarak POINTER Seçildi
  indev_drv.read_cb = my_touchpad_read;   //Girdi olarak Touchpad kullanılacak
  lv_indev_drv_register( &indev_drv );

  lv_example_get_started_3();
  Serial.println("Slider ornegi");
}

void loop() {
  lv_task_handler(); /* let the GUI do its work */
  delay(5);
}
