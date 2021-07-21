inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("alligator");
  add_adj("uninitiated");
  add_adj("alligator");
  set_short( "uninitiated alligator" );
  set_long( "Before you stands a uninitiated alligator. It smells like death and appears to be covered in gunk." );

  set_gender("neuter");
  set_race("alligator");

  set_level(1);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 5);
  set_skill("combat/defense", 5);
  add_object(DIR + "/objects/dex_potion.c", 9);
}
