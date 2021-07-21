inherit "/std/armor";

#include "../../../domain.h"

void setup(void) {
  set_id("iron armour");
  add_id("iron");
  add_id("armour");  add_id("armour");
  set_ac(2);
  set_value(800);
  set_size(2);
  set_weight(20);
  set_slot("body");
  set_short("A iron armour");
  set_long("A iron armour");
}
