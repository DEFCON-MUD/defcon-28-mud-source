inherit "/std/armor";

#include "../../../domain.h"

void setup(void) {
  set_id("mithril plate");
  add_id("mithril");
  add_id("armour");  add_id("plate");
  set_ac(8);
  set_value(12800);
  set_size(8);
  set_weight(80);
  set_slot("torso");
  set_short("A mithril plate");
  set_long("A mithril plate");
}
