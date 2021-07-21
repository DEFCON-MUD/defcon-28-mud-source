inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("eel");
  add_adj("sub-average");
  add_adj("eel");
  set_short( "sub-average eel" );
  set_long( "Before you stands a sub-average eel. It smells like sewer and appears to be covered in blood." );

  set_gender("neuter");
  set_race("eel");

  set_level(5);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 25);
  set_skill("combat/defense", 25);
  add_object(DIR + "/objects/cha_potion.c", 9);
}
