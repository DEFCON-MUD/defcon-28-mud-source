inherit "/std/armor";

#include "../../../domain.h"

void setup(void) {
  set_id("iron plate");
  add_id("iron");
  add_id("armour");  add_id("plate");
  set_ac(2);
  set_value(800);
  set_size(2);
  set_weight(20);
  set_slot("torso");
  set_short("A iron plate");
  set_long("A iron plate");
}
