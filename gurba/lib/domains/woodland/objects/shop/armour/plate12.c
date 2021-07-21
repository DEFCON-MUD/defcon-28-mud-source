inherit "/std/armor";

#include "../../../domain.h"

void setup(void) {
  set_id("titanium-carbide plate");
  add_id("titanium-carbide");
  add_id("armour");  add_id("plate");
  set_ac(12);
  set_value(28800);
  set_size(12);
  set_weight(120);
  set_slot("torso");
  set_short("A titanium-carbide plate");
  set_long("A titanium-carbide plate");
}
