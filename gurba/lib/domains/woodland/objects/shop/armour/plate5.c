inherit "/std/armor";

#include "../../../domain.h"

void setup(void) {
  set_id("aluminum plate");
  add_id("aluminum");
  add_id("armour");  add_id("plate");
  set_ac(5);
  set_value(5000);
  set_size(5);
  set_weight(50);
  set_slot("torso");
  set_short("A aluminum plate");
  set_long("A aluminum plate");
}
