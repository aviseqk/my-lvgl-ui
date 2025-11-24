#include "status_bar.h"
#include <stdio.h>
#include <inttypes.h>

void print_data(char *name, lv_obj_t *widget)
{
    int32_t w = lv_obj_get_width(widget);
    int32_t h = lv_obj_get_height(widget);
    int32_t content_w = lv_obj_get_content_width(widget);
    int32_t content_h = lv_obj_get_content_height(widget);

    printf("[%s] -> Width: %" PRId32 " Height: %" PRId32 " Content Width: %" PRId32 " Content Height: %" PRId32 "\n", name, w, h, content_w, content_h);
}

static bool fix_w_get_glyph_dsc(const lv_font_t *font, lv_font_glyph_dsc_t *dsc, uint32_t letter, uint32_t letter_next)
{
    bool ret = lv_font_get_glyph_dsc_fmt_txt(font, dsc, letter, letter_next);
    if (!ret)
        return false;

    /* Set a fixed width */
    dsc->adv_w = 20;
    dsc->ofs_x = (dsc->adv_w - dsc->box_w) / 2;
    return true;
}

void init_status_bar(status_bar_t *ui, lv_obj_t *parent)
{
    // TODO: Check out https://docs.lvgl.io/master/details/common-widget-features/coordinates.html for better ways of positioning children and sibling widgets

    lv_obj_t *bar = lv_obj_create(parent);
    lv_obj_set_height(bar, 40);
    lv_obj_set_width(bar, 238);
    lv_obj_set_y(bar, 0);
    ui->root = bar;

    // GPS Symbol
    lv_obj_t *gps = lv_label_create(bar);
    lv_label_set_text(gps, LV_SYMBOL_GPS);
    lv_obj_set_x(gps, 0);
    ui->location = gps;

    // Bluetooth Symbol
    lv_obj_t *bluetooth = lv_label_create(bar);
    lv_label_set_text(bluetooth, LV_SYMBOL_BLUETOOTH);
    lv_obj_set_x(bluetooth, 25);
    ui->bluetooth = bluetooth;

    // Battery Symbol
    lv_obj_t *battery = lv_label_create(bar);
    lv_label_set_text(battery, LV_SYMBOL_BATTERY_1);
    lv_obj_set_x(battery, 200);
    ui->battery = battery;

    /* Clone original font and override its behavior */
    static lv_font_t mono_font;
    mono_font = lv_font_montserrat_12;
    // mono_font.get_glyph_dsc = fix_w_get_glyph_dsc;

    /* create the label with normal font */
    lv_obj_t *label1 = lv_label_create(bar);
    lv_obj_set_style_text_font(label1, &lv_font_montserrat_12, 0);
    lv_label_set_text(label1, "blr");
    lv_obj_set_x(label1, 140);

    /* Create a label with fixed-width glyph descriptor override */
    lv_obj_t *label2 = lv_label_create(bar);
    lv_obj_set_x(label2, 70);
    // lv_obj_set_y(label2, 30);
    lv_obj_set_style_text_font(label2, &mono_font, 0);
    lv_label_set_text(label2, "10:44PM");

    ui->location = label1;
    ui->time = label2;

    print_data("status bar", bar);
    print_data("gps", gps);
    print_data("bluletooth", bluetooth);
    print_data("battery", battery);
    print_data("location", label1);
    print_data("time", label2);
}
