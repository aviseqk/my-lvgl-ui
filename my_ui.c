#include "lvgl.h"
#include "my_ui.h"
#include "home_screen.h"

void my_ui_init(void)
{
    lv_obj_t *label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Hello LVGL!");
    lv_obj_center(label);

    screen_home_t home;
    init_home_screen(&home);

    // load between screens
    // at start we do,lv_screen_load(home_screen) or something like that;
    lv_screen_load(home.root);
}
