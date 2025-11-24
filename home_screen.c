/* This is for the Home Screen */
#include "home_screen.h"
#include "status_bar.h"

// get the icons from assets/ folder (Icons downloaded in 36px,36px, in png format and then converted using lvgl image converter and added as source files)
extern const lv_image_dsc_t bicycle_bold;
extern const lv_image_dsc_t chart_bar_bold;
extern const lv_image_dsc_t gear_bold;

void init_home_screen(screen_home_t *ui)
{
    ui->root = lv_obj_create(NULL);
    lv_obj_set_width(ui->root, 240);
    lv_obj_set_height(ui->root, 320);

    status_bar_t s_bar;
    init_status_bar(&s_bar, ui->root);
    ui->status_bar = s_bar.root;

    create_home_buttons_w_text(ui);

    /* styling the top status bar */
    // NOTE: If a style is not to be changed during running, it's better to create them as const variables, to save RAM
    // static lv_style_t style_status_bar;
    // lv_style_init(&style_status_bar);
    // lv_style_set_width(&style_status_bar, 240);
    // lv_style_set_height(&style_status_bar, 20);
    // lv_style_set_bg_color(&style_status_bar, lv_color_hex(0x115588));
    // lv_style_set_border_width(&style_status_bar, 2);
    // lv_style_set_border_color(&style_status_bar, lv_color_black());

    // lv_obj_add_style(ui->status_bar, &style_status_bar, 0);
}

void create_home_buttons(screen_home_t *ui)
{
    /* Button Container Size: 240px x 120px*/
    lv_obj_t *btn_container = lv_obj_create(ui->root);
    lv_obj_set_size(btn_container, 240, 120);
    // lv_obj_set_style_radius(btn_container, LV_RADIUS_CIRCLE, 0);

    lv_obj_set_flex_flow(btn_container, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_pad_row(btn_container, 0, 0);
    lv_obj_set_style_pad_column(btn_container, 15, 0);
    lv_obj_set_style_pad_all(btn_container, 0, 0);
    lv_obj_set_flex_align(btn_container, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    lv_obj_set_y(btn_container, 200);
    lv_obj_set_style_bg_color(btn_container, lv_color_hex(0x272323), 0);

    ui->btn_container = btn_container;

    /* Create all three buttons */
    lv_obj_t *buttons[3];

    lv_obj_t *ride_btn = lv_button_create(btn_container);
    lv_obj_center(ride_btn);
    lv_obj_t *img1 = lv_image_create(ride_btn);
    lv_image_set_src(img1, &bicycle_bold);
    lv_obj_center(img1);
    buttons[0] = ride_btn;

    lv_obj_t *stats_btn = lv_button_create(btn_container);
    lv_obj_center(stats_btn);
    lv_obj_t *img2 = lv_image_create(stats_btn);
    lv_image_set_src(img2, &chart_bar_bold);
    lv_obj_center(img2);
    buttons[1] = stats_btn;

    lv_obj_t *settings_btn = lv_button_create(btn_container);
    lv_obj_center(settings_btn);
    lv_obj_t *img3 = lv_image_create(settings_btn);
    lv_image_set_src(img3, &gear_bold);
    lv_obj_center(img3);
    buttons[2] = settings_btn;

    for (int i = 0; i < 3; i++)
    {
        lv_obj_set_size(buttons[i], 60, 60); // elliptical shape
        lv_obj_set_style_radius(buttons[i], LV_RADIUS_CIRCLE, 0);
        lv_obj_set_style_bg_color(buttons[i], lv_color_hex(0xD9D9D9), 0);
    }

    ui->ride_btn = ride_btn;
    ui->settings_btn = settings_btn;
    ui->stats_btn = stats_btn;
}

void create_home_buttons_w_text(screen_home_t *ui)
{
    /* Button Container Size: 240px x 120px*/
    lv_obj_t *btn_container = lv_obj_create(ui->root);
    lv_obj_set_style_pad_left(btn_container, 0, 0);
    lv_obj_set_style_pad_right(btn_container, 0, 0);
    lv_obj_set_style_pad_top(btn_container, 0, 0);
    lv_obj_set_style_pad_bottom(btn_container, 0, 0);

    lv_obj_set_size(btn_container, 240, 120);
    // lv_obj_set_style_radius(btn_container, LV_RADIUS_CIRCLE, 0);

    lv_obj_set_flex_flow(btn_container, LV_FLEX_FLOW_ROW);
    // lv_obj_set_style_pad_row(btn_container, 0, 0);
    lv_obj_set_style_pad_column(btn_container, 15, 0);
    // lv_obj_set_style_pad_all(btn_container, 0, 0);
    lv_obj_set_flex_align(btn_container, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    lv_obj_set_y(btn_container, 200);
    lv_obj_set_style_bg_color(btn_container, lv_color_hex(0x272323), 0);

    ui->btn_container = btn_container;

    /* Static UI Content */
    const char *texts[3] = {"RIDE", "STATS", "CONFIG"};
    const lv_image_dsc_t *icons[3] = {
        &bicycle_bold,
        &chart_bar_bold,
        &gear_bold};

    /* create 3 containers, with elliptical buttons and the texts beneath, all following FLEX */
    for (int i = 0; i < 3; i++)
    {
        // vertical container for each buttons and text
        lv_obj_t *item = lv_obj_create(btn_container);
        lv_obj_set_size(item, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        lv_obj_set_style_bg_opa(item, LV_OPA_TRANSP, 0);
        lv_obj_set_style_border_width(item, 0, 0);
        lv_obj_set_flex_flow(item, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_row(item, 5, 0); // spacing between button and text

        // making sure item containers don’t add width
        lv_obj_set_style_pad_all(item, 0, 0);
        lv_obj_set_style_border_width(item, 0, 0);
        lv_obj_set_style_pad_column(item, 0, 0);

        // elliptical button
        lv_obj_t *btn = lv_button_create(item);
        lv_obj_set_size(btn, 60, 60);
        lv_obj_set_style_radius(btn, LV_RADIUS_CIRCLE, 0);
        lv_obj_set_style_bg_color(btn, lv_color_hex(0xD9D9D9), 0);

        // load icon inside the button
        lv_obj_t *img = lv_image_create(btn);
        lv_image_set_src(img, icons[i]);
        lv_obj_center(img);

        // add Label udner the button
        lv_obj_t *label = lv_label_create(item);
        lv_label_set_text(label, texts[i]);
        lv_obj_set_style_text_font(label, &lv_font_montserrat_14, 0);
        lv_obj_set_style_text_color(label, lv_color_white(), 0);
        lv_obj_set_width(label, 60); // same width as the circle button
        lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);
    }
}
