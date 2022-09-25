#include <lvgl.h>
#include <TFT_eSPI.h>

#include <demos/lv_demos.h>
#include <extra/libs/qrcode/lv_qrcode.h>

/*Change to your screen resolution*/
static const uint16_t screenWidth  = 480;
static const uint16_t screenHeight = 320;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * 10 ];

TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */

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

    if( !touched )
    {
        data->state = LV_INDEV_STATE_REL;
    }
    else
    {
        data->state = LV_INDEV_STATE_PR;

        /*Set the coordinates*/
        data->point.x = touchX;
        data->point.y = touchY;

        Serial.print( "Data x " );
        Serial.println( touchX );

        Serial.print( "Data y " );
        Serial.println( touchY );
    }
}

void setup()
{
    Serial.begin(115200); /* prepare for possible serial debug */

    String LVGL_Arduino = "HOSGELDINIZ! ";
    LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();

    Serial.println( LVGL_Arduino );
    Serial.println( "I am LVGL_Arduino" );

    lv_init();

    tft.begin();          /* TFT init */
    tft.setRotation( 3 ); /* Landscape orientation, flipped */

    /*Set the touchscreen calibration data,
     the actual data for your display can be acquired using
     the Generic -> Touch_calibrate example from the TFT_eSPI library*/
    uint16_t calData[5] = { 299, 3588, 348, 3474, 1 };
    tft.setTouch( calData );

    lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth * 10 );

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;     //HAL tarafından kaydedilen Display driver struct'ıdır. 
    lv_disp_drv_init( &disp_drv );     
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;   //Ekran flash'lama yöntemi
    disp_drv.draw_buf = &draw_buf;       //Kullanılacak buffer
    lv_disp_drv_register( &disp_drv );

    /*Initialize the (dummy) input device driver
     * Kurulum ve kayıt için cihaz girdi sürücüleri. 4 tür girdi vardır.
     * LV_INDEV_TYPE_POINTER(Touchpad veya mouse)
     * LV_INDEV_TYPE_KEYPAD (klavye veya tuş takımı)
     * LV_INDEV_TYPE_ENCODER (sağ, sol, buton özellikleri olan)
     * LV_INDEV_TYPE_BUTTON (ekrana basan harici butonlar)
    */
    static lv_indev_drv_t indev_drv; 
    lv_indev_drv_init( &indev_drv ); 
    indev_drv.type = LV_INDEV_TYPE_POINTER; //Cihaz girdisi olarak POINTER Seçilmiş
    indev_drv.read_cb = my_touchpad_read;   //Girdi olarak Touchpad kullanılacak 
    lv_indev_drv_register( &indev_drv );

    lv_example_qrcode_1();

    Serial.println( "Setup done" );
    
}

void lv_example_qrcode_1(void)
{
    lv_color_t bg_color = lv_palette_lighten(LV_PALETTE_LIGHT_BLUE, 5);
    lv_color_t fg_color = lv_palette_darken(LV_PALETTE_BLUE, 4);

    lv_obj_t * qr = lv_qrcode_create(lv_scr_act(), 150, fg_color, bg_color);

    /*Set data*/
    const char * data = "HOSGELDINIZ";
    lv_qrcode_update(qr, data, strlen(data));
    lv_obj_center(qr);

    /*Add a border with bg_color*/
    lv_obj_set_style_border_color(qr, bg_color, 0);
    lv_obj_set_style_border_width(qr, 5, 0);
}

void loop()
{
    lv_timer_handler(); /* let the GUI do its work */
    delay( 5 );
}
