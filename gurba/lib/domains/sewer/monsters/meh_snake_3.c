inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("snake");
  add_adj("meh");
  add_adj("snake");
  set_short( "meh snake" );
  set_long( "Before you stands a meh snake. It smells like uggghhhhh and appears to be covered in gunk." );

  set_gender("male");
  set_race("snake");

  set_level(3);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 15);
  set_skill("combat/defense", 15);
  add_object(DIR + "/objects/con_potion.c", 9);
}
