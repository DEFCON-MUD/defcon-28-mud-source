inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("lizard");
  add_adj("sub-average");
  add_adj("lizard");
  set_short( "sub-average lizard" );
  set_long( "Before you stands a sub-average lizard. It smells like uggghhhhh and appears to be covered in oil." );

  set_gender("male");
  set_race("lizard");

  set_level(5);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 25);
  set_skill("combat/defense", 25);
  add_object(DIR + "/objects/int_potion.c", 9);
}
