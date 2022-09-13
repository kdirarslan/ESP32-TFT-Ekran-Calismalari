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
  lv_label_set_text(label, "Button");               /*Set the labels text*/
  lv_obj_center(label);


  //BUTON1
  lv_obj_t * btn1 = lv_btn_create(lv_scr_act());
  lv_obj_add_event_cb(btn1, btn_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_align(btn1, LV_ALIGN_CENTER, 0, -40);

  label = lv_label_create(btn1);
  lv_label_set_text(label, "Buton ORTA");
  lv_obj_center(label);

  //TOOGLE BUTON
  lv_obj_t * btn2 = lv_btn_create(lv_scr_act());
  lv_obj_add_event_cb(btn2, btn_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_align(btn2, LV_ALIGN_CENTER, 0, 40);
  lv_obj_add_flag(btn2, LV_OBJ_FLAG_CHECKABLE);
  lv_obj_set_height(btn2, LV_SIZE_CONTENT);

  label = lv_label_create(btn2);
  lv_label_set_text(label, "TOGGLE");
  lv_obj_center(label);


}
