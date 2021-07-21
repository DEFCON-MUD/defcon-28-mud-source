inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("rat");
  add_adj("sub-average");
  add_adj("rat");
  set_short( "sub-average rat" );
  set_long( "Before you stands a sub-average rat. It smells like sewer and appears to be covered in sewage." );

  set_gender("female");
  set_race("rat");

  set_level(5);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 25);
  set_skill("combat/defense", 25);
  add_object(DIR + "/objects/con_potion.c", 9);
}
