inherit "/std/armor";

#include "../../../domain.h"

void setup(void) {
  set_id("iron ring");
  add_id("iron");
  add_id("armour");  add_id("ring");
  set_ac(2);
  set_value(800);
  set_size(2);
  set_weight(20);
  set_slot("finger");
  set_short("A iron ring");
  set_long("A iron ring");
}
