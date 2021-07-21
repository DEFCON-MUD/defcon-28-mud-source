inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("worm");
  add_adj("sub-average");
  add_adj("worm");
  set_short( "sub-average worm" );
  set_long( "Before you stands a sub-average worm. It smells like sewer and appears to be covered in oil." );

  set_gender("male");
  set_race("worm");

  set_level(5);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 25);
  set_skill("combat/defense", 25);
  add_object(DIR + "/objects/int_potion.c", 9);
}
