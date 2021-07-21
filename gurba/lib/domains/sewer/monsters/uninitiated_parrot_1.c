inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("parrot");
  add_adj("uninitiated");
  add_adj("parrot");
  set_short( "uninitiated parrot" );
  set_long( "Before you stands a uninitiated parrot. It smells like sewer and appears to be covered in blood." );

  set_gender("neuter");
  set_race("parrot");

  set_level(1);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 5);
  set_skill("combat/defense", 5);
  add_object(DIR + "/objects/wis_potion.c", 9);
}
