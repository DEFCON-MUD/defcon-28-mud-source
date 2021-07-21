inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("eel");
  add_adj("mediocre");
  add_adj("eel");
  set_short( "mediocre eel" );
  set_long( "Before you stands a mediocre eel. It smells like uggghhhhh and appears to be covered in gunk." );

  set_gender("male");
  set_race("eel");

  set_level(4);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 20);
  set_skill("combat/defense", 20);
  add_object(DIR + "/objects/wis_potion.c", 9);
}
