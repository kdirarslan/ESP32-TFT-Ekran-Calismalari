static void btn_event_cb(lv_event_t * e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * btn = lv_event_get_target(e);

  if (code == LV_EVENT_CLICKED) {
    static uint8_t cnt = 0;
    cnt++;

    /*Butonun ilk child'ının label'ını al ve ekrana yaz.*/
    lv_obj_t * label = lv_obj_get_child(btn, 0);
    char * txt = lv_label_get_text(label);

    client.publish(topicTelefonAra, txt);
    Serial.print("Buton label: "); Serial.println(txt);
    //lv_label_set_text_fmt(label, "Button: %d", cnt); //label'ın içeriğini değiştir.
  }
}

/**
   Create a button with a label and react on click event.
*/
void lv_example_get_started_1(void)
{
  //BUTON
  lv_obj_t * btn = lv_btn_create(lv_scr_act());     /*Add a button the current screen*/
  lv_obj_align(btn, LV_ALIGN_CENTER, 0, -120);
  //lv_obj_set_pos(btn, 10, 10);                    /*Set its position*/
  lv_obj_set_size(btn, 120, 50);                    /*Set its size*/
  lv_obj_add_event_cb(btn, btn_event_cb, LV_EVENT_ALL, NULL);           /*Assign a callback to the button*/

  lv_obj_t * label = lv_label_create(btn);          /*Add a label to the button*/
  lv_label_set_text(label, "KISI 1");               /*Set the labels text*/
  lv_obj_center(label);


  //BUTON1
  lv_obj_t * btn1 = lv_btn_create(lv_scr_act());
  lv_obj_align(btn1, LV_ALIGN_CENTER, 0, -60);
  lv_obj_set_size(btn1, 120, 50);
  lv_obj_add_event_cb(btn1, btn_event_cb, LV_EVENT_ALL, NULL);

  label = lv_label_create(btn1);
  lv_label_set_text(label, "KISI 2");
  lv_obj_center(label);

  //BUTON3
  lv_obj_t * btn3 = lv_btn_create(lv_scr_act());
  lv_obj_align(btn3, LV_ALIGN_CENTER, 0, -0);
  lv_obj_set_size(btn3, 120, 50);
  lv_obj_add_event_cb(btn3, btn_event_cb, LV_EVENT_ALL, NULL);

  label = lv_label_create(btn3);
  lv_label_set_text(label, "KISI 3");
  lv_obj_center(label);

  //BUTON4
  lv_obj_t * btn4 = lv_btn_create(lv_scr_act());
  lv_obj_align(btn4, LV_ALIGN_CENTER, 0, 120);
  lv_obj_set_size(btn4, 120, 50);
  lv_obj_add_event_cb(btn4, btn_event_cb, LV_EVENT_ALL, NULL);

  label = lv_label_create(btn4);
  lv_label_set_text(label, "KISI 4");
  lv_obj_center(label);


  //TOOGLE BUTON
  lv_obj_t * btn2 = lv_btn_create(lv_scr_act());
  lv_obj_align(btn2, LV_ALIGN_CENTER, 0, 60);
  lv_obj_set_size(btn2, 120, 50);
  lv_obj_add_event_cb(btn2, btn_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_add_flag(btn2, LV_OBJ_FLAG_CHECKABLE);
  lv_obj_set_height(btn2, LV_SIZE_CONTENT);

  label = lv_label_create(btn2);
  lv_label_set_text(label, "KISI 5");
  lv_obj_center(label);
}


/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
  uint16_t c;

  tft.startWrite(); /* Start new TFT transaction */
  tft.setAddrWindow(area->x1, area->y1, (area->x2 - area->x1 + 1), (area->y2 - area->y1 + 1)); /* set the working window */
  for (int y = area->y1; y <= area->y2; y++) {
    for (int x = area->x1; x <= area->x2; x++) {
      c = color_p->full;
      tft.writeColor(c, 1);
      color_p++;
    }
  }
  tft.endWrite(); /* terminate TFT transaction */
  lv_disp_flush_ready(disp); /* tell lvgl that flushing is done */
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
    Serial.print(" - Data y "); Serial.println(touchY);
  }
}
