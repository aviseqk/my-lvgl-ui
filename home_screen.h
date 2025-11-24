#ifndef HOME_SCREEN_H
#define HOME_SCREEN_H

#include "lvgl.h"

typedef struct screen_home_t
{
    lv_obj_t *root;
    lv_obj_t *status_bar;
    lv_obj_t *flash_cards;
    lv_obj_t *btn_container;
    lv_obj_t *ride_btn;
    lv_obj_t *stats_btn;
    lv_obj_t *settings_btn;
} screen_home_t;

void init_home_screen(screen_home_t *ui);
void create_home_buttons(screen_home_t *ui);
void create_home_buttons_w_text(screen_home_t *ui);

#endif
