#ifndef STATUS_BAR_H
#define STATUS_BAR_H

#include "lvgl.h"

typedef struct status_bar_t
{
    lv_obj_t *root;
    lv_obj_t *network;
    lv_obj_t *location;
    lv_obj_t *time;
    lv_obj_t *city;
    lv_obj_t *battery;
    lv_obj_t *bluetooth;
} status_bar_t;

void init_status_bar(status_bar_t *ui, lv_obj_t *parent);

#endif
