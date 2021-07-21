inherit "/std/armor";

#include "../../../domain.h"

void setup(void) {
  set_id("tungsten-carbide plate");
  add_id("tungsten-carbide");
  add_id("armour");  add_id("plate");
  set_ac(9);
  set_value(16200);
  set_size(9);
  set_weight(90);
  set_slot("torso");
  set_short("A tungsten-carbide plate");
  set_long("A tungsten-carbide plate");
}
