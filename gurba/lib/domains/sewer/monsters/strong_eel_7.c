inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("eel");
  add_adj("strong");
  add_adj("eel");
  set_short( "strong eel" );
  set_long( "Before you stands a strong eel. It smells like uggghhhhh and appears to be covered in sewage." );

  set_gender("neuter");
  set_race("eel");

  set_level(7);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 35);
  set_skill("combat/defense", 35);
  add_object(DIR + "/objects/str_potion.c", 9);
}
