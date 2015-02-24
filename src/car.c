#include <pebble.h>
#include "common.h"
    #include <car.h>

static Window *window;

static SimpleMenuLayer *simple_menu_layer;
static SimpleMenuSection menu_sections;
static SimpleMenuItem menu_items[5];

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  int num_a_items = 0;

  menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Base",
    .subtitle = "df"
  };
  
  menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Per Min",
    .subtitle = "sadf"
  };
  
  menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Per Mile",
    .subtitle = "asdf"
  };

    menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "safe",
      .subtitle = "sadf"
  };

    menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "min fare",
      .subtitle = "sdf"
  };


  menu_sections.num_items = 5;
  menu_sections.items = menu_items;

  simple_menu_layer = simple_menu_layer_create(bounds, window, &menu_sections, 1, NULL);
  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
}

 void cars_init(int index) {
  APP_LOG(APP_LOG_LEVEL_INFO, "TESTING");
  window = window_create();
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  const bool animated = true;
  window_stack_push(window, animated);
}

 void cars_deinit(void) {
  window_destroy(window);
}

