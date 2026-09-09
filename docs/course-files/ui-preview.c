/* LVGL 9.4: call once after display/input initialization.
 * Manual state preview only; Finish is not a real timer.
 */
#include "lvgl.h"

static lv_obj_t *status_label;

static void show_ready(lv_event_t *event)
{
    (void)event;
    lv_label_set_text(status_label, "Ready");
}

static void show_working(lv_event_t *event)
{
    (void)event;
    lv_label_set_text(status_label, "Working");
}

static void show_done(lv_event_t *event)
{
    (void)event;
    lv_label_set_text(status_label, "Done");
}

lv_obj_t *ui_preview_create(void)
{
    lv_obj_t *screen = lv_screen_active();
    status_label = lv_label_create(screen);
    lv_label_set_text(status_label, "Ready");
    lv_obj_align(status_label, LV_ALIGN_TOP_MID, 0, 14);

    lv_obj_t *start = lv_button_create(screen);
    lv_obj_set_size(start, 160, 44);
    lv_obj_align(start, LV_ALIGN_TOP_MID, 0, 48);
    lv_obj_add_event_cb(start, show_working, LV_EVENT_CLICKED, NULL);
    lv_obj_t *start_text = lv_label_create(start);
    lv_label_set_text(start_text, "Start");
    lv_obj_center(start_text);

    lv_obj_t *finish = lv_button_create(screen);
    lv_obj_set_size(finish, 160, 44);
    lv_obj_align(finish, LV_ALIGN_TOP_MID, 0, 108);
    lv_obj_add_event_cb(finish, show_done, LV_EVENT_CLICKED, NULL);
    lv_obj_t *finish_text = lv_label_create(finish);
    lv_label_set_text(finish_text, "Finish (preview)");
    lv_obj_center(finish_text);

    lv_obj_t *reset = lv_button_create(screen);
    lv_obj_set_size(reset, 160, 44);
    lv_obj_align(reset, LV_ALIGN_TOP_MID, 0, 168);
    lv_obj_add_event_cb(reset, show_ready, LV_EVENT_CLICKED, NULL);
    lv_obj_t *reset_text = lv_label_create(reset);
    lv_label_set_text(reset_text, "Reset / Cancel");
    lv_obj_center(reset_text);
    return screen;
}

#ifdef UI_PREVIEW_SELF_TEST
#include <assert.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
    lv_init();
    lv_display_t *display = lv_display_create(240, 240);
    lv_obj_t *screen = ui_preview_create();
    assert(strcmp(lv_label_get_text(status_label), "Ready") == 0);
    lv_obj_send_event(lv_obj_get_child(screen, 1), LV_EVENT_CLICKED, NULL);
    assert(strcmp(lv_label_get_text(status_label), "Working") == 0);
    lv_obj_send_event(lv_obj_get_child(screen, 2), LV_EVENT_CLICKED, NULL);
    assert(strcmp(lv_label_get_text(status_label), "Done") == 0);
    lv_obj_send_event(lv_obj_get_child(screen, 3), LV_EVENT_CLICKED, NULL);
    assert(strcmp(lv_label_get_text(status_label), "Ready") == 0);
    lv_obj_send_event(lv_obj_get_child(screen, 1), LV_EVENT_CLICKED, NULL);
    lv_obj_send_event(lv_obj_get_child(screen, 3), LV_EVENT_CLICKED, NULL);
    assert(strcmp(lv_label_get_text(status_label), "Ready") == 0);
    lv_display_delete(display);
    lv_deinit();
    puts("LVGL preview: start, finish, reset and cancel passed.");
    return 0;
}
#endif
