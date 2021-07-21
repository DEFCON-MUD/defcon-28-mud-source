inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("eel");
  add_adj("newbie");
  add_adj("eel");
  set_short( "newbie eel" );
  set_long( "Before you stands a newbie eel. It smells like uggghhhhh and appears to be covered in oil." );

  set_gender("neuter");
  set_race("eel");

  set_level(2);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 10);
  set_skill("combat/defense", 10);
  add_object(DIR + "/objects/con_potion.c", 9);
}
