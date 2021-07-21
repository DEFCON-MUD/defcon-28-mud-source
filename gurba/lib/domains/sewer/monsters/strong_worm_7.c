inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("worm");
  add_adj("strong");
  add_adj("worm");
  set_short( "strong worm" );
  set_long( "Before you stands a strong worm. It smells like uggghhhhh and appears to be covered in gunk." );

  set_gender("neuter");
  set_race("worm");

  set_level(7);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 35);
  set_skill("combat/defense", 35);
  add_object(DIR + "/objects/wis_potion.c", 9);
}
