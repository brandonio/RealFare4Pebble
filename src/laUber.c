#include <pebble.h>
#include "common.h"
    #include <car.h>



static Window *window;

static SimpleMenuLayer *simple_menu_layer;
static SimpleMenuSection menu_sections;
static SimpleMenuItem menu_items[6];



static void car_selected(int index, void* context) {
  APP_LOG(APP_LOG_LEVEL_INFO, "Index: %d", index);
  cars_init(index);
}


static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  int num_a_items = 0;

  menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Uber X",
    .callback = car_selected
  };
  
  menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Uber XL",
        .callback = car_selected
  };
  
  menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Uber Plus",
        .callback = car_selected
  };

    menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Uber Black",
        .callback = car_selected
  };

    menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Uber SUV",
        .callback = car_selected
  };

    menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Uber Lux",
        .callback = car_selected
  };

  menu_sections.num_items = 6;
  menu_sections.items = menu_items;

  simple_menu_layer = simple_menu_layer_create(bounds, window, &menu_sections, 1, NULL);
  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
}

 void lainit(void) {
  APP_LOG(APP_LOG_LEVEL_INFO, "Boooooooo");
  window = window_create();
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  const bool animated = true;
  window_stack_push(window, animated);
}

 void ladeinit(void) {
  window_destroy(window);
}