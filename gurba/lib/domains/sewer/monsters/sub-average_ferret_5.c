inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("ferret");
  add_adj("sub-average");
  add_adj("ferret");
  set_short( "sub-average ferret" );
  set_long( "Before you stands a sub-average ferret. It smells like death and appears to be covered in blood." );

  set_gender("neuter");
  set_race("ferret");

  set_level(5);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 25);
  set_skill("combat/defense", 25);
  add_object(DIR + "/objects/cha_potion.c", 9);
}
