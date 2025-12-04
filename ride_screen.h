#ifndef RIDE_SCREEN_H
#define RIDE_SCREEN_H

#include "lvgl.h"

typedef struct ride_metrics_t
{
    lv_obj_t *curr_speed;
    lv_obj_t *avg_speed;
    lv_obj_t *distance;
    lv_obj_t *elapsed_time;
} ride_metrics_t;

typedef struct ride_screen_t
{
    lv_obj_t *root;
    lv_obj_t *status_bar;
    lv_obj_t *map_tile;
    lv_obj_t *marker;
    lv_obj_t *nav_advice;
    ride_metrics_t *ride_metrics;
} ride_screen_t;

void init_ride_screen(ride_screen_t *ui);

#endif
