inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("worm");
  add_adj("newbie");
  add_adj("worm");
  set_short( "newbie worm" );
  set_long( "Before you stands a newbie worm. It smells like uggghhhhh and appears to be covered in gunk." );

  set_gender("neuter");
  set_race("worm");

  set_level(2);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 10);
  set_skill("combat/defense", 10);
  add_object(DIR + "/objects/str_potion.c", 9);
}
