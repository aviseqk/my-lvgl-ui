#include "ride_screen.h"
#include "status_bar.h"

void init_ride_screen(ride_screen_t *ui)
{
    ui->root = lv_obj_create(NULL);
    lv_obj_set_width(ui->root, 240);
    lv_obj_set_height(ui->root, 320);

    lv_obj_set_style_bg_color(ui->root, lv_color_hex(0x717171), 0);

    status_bar_t s_bar;
    init_status_bar(&s_bar, ui->root);
    ui->status_bar = s_bar.root;
}
