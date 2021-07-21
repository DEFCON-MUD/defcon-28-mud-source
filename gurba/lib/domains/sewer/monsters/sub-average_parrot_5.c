inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("parrot");
  add_adj("sub-average");
  add_adj("parrot");
  set_short( "sub-average parrot" );
  set_long( "Before you stands a sub-average parrot. It smells like uggghhhhh and appears to be covered in sewage." );

  set_gender("neuter");
  set_race("parrot");

  set_level(5);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 25);
  set_skill("combat/defense", 25);
  add_object(DIR + "/objects/str_potion.c", 9);
}
