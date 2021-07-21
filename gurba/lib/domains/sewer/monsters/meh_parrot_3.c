inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("parrot");
  add_adj("meh");
  add_adj("parrot");
  set_short( "meh parrot" );
  set_long( "Before you stands a meh parrot. It smells like hacker and appears to be covered in dirt." );

  set_gender("neuter");
  set_race("parrot");

  set_level(3);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 15);
  set_skill("combat/defense", 15);
  add_object(DIR + "/objects/int_potion.c", 9);
}
