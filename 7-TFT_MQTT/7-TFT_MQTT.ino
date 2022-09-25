#include <WiFi.h>
#include <PubSubClient.h>

#include <lvgl.h>
#include <Ticker.h>
#include <TFT_eSPI.h>

#define LVGL_TICK_PERIOD 60
/*Ekran Çözünürlüğü*/
static const uint16_t screenWidth  = 480;
static const uint16_t screenHeight = 320;

Ticker tick; /* timer for interrupt handler */
TFT_eSPI tft = TFT_eSPI(); /* TFT instance */
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * 10 ];

lv_obj_t * slider_label;

//WiFi ve MQTT Ayarları
const char* ssid = ""; //WiFi SSDID
const char* password = ""; //WiFi Password
const char* mqtt_server = "10.0.0.0"; //MQTT Broker adresi

//Abone olunan ve mesaj gönderilen topicler
const char* topicTelefonAra ="esp32telefon";
const char* topicESP32Mesaj = "esp32mesaj";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

const int ledPin = 24;

void setup() {

  Serial.begin(115200);

  lv_init();

  tft.begin();
  tft.setRotation(1);
  //uint16_t calData[5] = { 275, 3620, 264, 3532, 1 };
  uint16_t calData[5] = { 222, 3375, 445, 3250, 0 };
  tft.setTouch(calData);

  lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth * 10 );

  /*Initialize the display*/
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);

  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);             /*Descriptor of a input device driver*/
  indev_drv.type = LV_INDEV_TYPE_POINTER;    /*Touch pad is a pointer-like device*/
  indev_drv.read_cb = my_touchpad_read;      /*Set your driver function*/
  lv_indev_drv_register(&indev_drv);         /*Finally register the driver*/

  lv_example_get_started_1();

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  if (!client.connected()) {
    reconnect();
  }
  pinMode(ledPin, OUTPUT);
}

void loop() {
  lv_task_handler(); /* let the GUI do its work */
  delay(5);

  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
