#include <pebble.h>
#include "common.h"
    #include <car.h>

static Window *window;

 pricing carPrice{
	
 carPrice = malloc(sizeof(pricing));
  carPrice->base = 0.0;
   carPrice->perMin = 0.0;
   carPrice->perMile = 0.0;
   carPrice->safe = 0.0;
   carPrice->min = 0.0;
}

static SimpleMenuLayer *simple_menu_layer;
static SimpleMenuSection menu_sections;
static SimpleMenuItem menu_items[5];

void pricesinit(int index) {
	
  if (index == 1) {
       
     pr->base = 3.0;
     pr->perMin = 0.35;
     pr->perMile = 1.85;
     pr->safe = 1.0;
     pr->min = 7.0;
       }
        
if (index == 2) {
 
 pr->base = 8.0;
   pr->perMin = 0.45;
   pr->perMile = 3.55;
   pr->safe = 0.0;
   pr->min = 15.0;
 }
      
if (index == 3) {

   pr->base = 15.0;
   pr->perMin = 0.55;
   pr->perMile = 4.25;
   pr->safe = 0.0;
   pr->min = 25.0;
}
      
 if (index == 4) {

   pr->base = 5.0;
   pr->perMin = 0.4;
   pr->perMile = 2.35;
   pr->safe = 1.0;
   pr->min = 7.0;
}
      
 if (index == 5) {

     pr->base = 8.0;
   pr->perMin = 0.45;
   pr->perMile = 3.55;
   pr->safe = 0.0;
   pr->min = 15.0; 
    
if (index == 6) {
 
    pr->base = 2.20;
    pr->perMin = 0.26;
    pr->perMile = 1.3;
    pr->safe = 1.0;
    pr->min = 5.0;
 }
       
if (index == 7) {
 
    pr->base = 5.0;
    pr->perMin = 0.45;
    pr->perMile = 2.15;
    pr->safe = 1.0;
    pr->min = 8.0;
 }
       
if (index == 8) {
 
    pr->base = 8.0;
    pr->perMin = 0.65;
    pr->perMile = 3.75;
    pr->safe = 0.0;
    pr->min = 10.0;
 }
       
if (index == 9) {
 
    pr->base = 15.0;
    pr->perMin = 0.9;
    pr->perMile = 0.26;
    pr->safe = 0.0;
    pr->min = 25.0;
 }
       
 if (index == 10) {
 
    pr->base = 3.0;
    pr->perMin = 0.4;
    pr->perMile = 2.15;
    pr->safe = 1.0;
    pr->min = 8.0;
 }
       
if (index == 11) {
      
    pr->base = 4.50;
    pr->perMin = 0.6;
    pr->perMile = 3.25;
    pr->safe = 1.0;
    pr->min = 12.0;
      }
       
if (index == 12) {

    pr->base = 7.0;
    pr->perMin = 0.65;
    pr->perMile = 3.75;
    pr->safe = 0.0;
    pr->min = 15.0;
}
  
if (index == 13) {
                                                                              
    pr->base = 14.0;
    pr->perMin = 0.8;
    pr->perMile = 4.5;
    pr->safe = 0.0;
    pr->min = 25.0;

}

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

  simple_menu_layer = simple_menu_layer_create(bounds, window, &menu_sections, 5, NULL);
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
   pricesinit(index);
}

 void cars_deinit(void) {
  window_destroy(window);
}

