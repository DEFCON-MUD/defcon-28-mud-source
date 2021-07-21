inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("lizard");
  add_adj("average");
  add_adj("lizard");
  set_short( "average lizard" );
  set_long( "Before you stands a average lizard. It smells like uggghhhhh and appears to be covered in blood." );

  set_gender("neuter");
  set_race("lizard");

  set_level(6);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 30);
  set_skill("combat/defense", 30);
  add_object(DIR + "/objects/wis_potion.c", 9);
}
