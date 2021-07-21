inherit "/std/armor";

#include "../../../domain.h"

void setup(void) {
  set_id("tungsten ring");
  add_id("tungsten");
  add_id("armour");  add_id("ring");
  set_ac(6);
  set_value(7200);
  set_size(6);
  set_weight(60);
  set_slot("finger");
  set_short("A tungsten ring");
  set_long("A tungsten ring");
}
