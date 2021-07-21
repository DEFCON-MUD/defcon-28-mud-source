inherit "/std/armor";

#include "../../../domain.h"

void setup(void) {
  set_id("tungsten plate");
  add_id("tungsten");
  add_id("armour");  add_id("plate");
  set_ac(6);
  set_value(7200);
  set_size(6);
  set_weight(60);
  set_slot("torso");
  set_short("A tungsten plate");
  set_long("A tungsten plate");
}
