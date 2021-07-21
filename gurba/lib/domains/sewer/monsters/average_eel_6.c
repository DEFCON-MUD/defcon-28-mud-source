inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("eel");
  add_adj("average");
  add_adj("eel");
  set_short( "average eel" );
  set_long( "Before you stands a average eel. It smells like sewer and appears to be covered in oil." );

  set_gender("neuter");
  set_race("eel");

  set_level(6);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 30);
  set_skill("combat/defense", 30);
  add_object(DIR + "/objects/wis_potion.c", 9);
}
