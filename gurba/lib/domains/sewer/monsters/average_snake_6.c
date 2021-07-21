inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("snake");
  add_adj("average");
  add_adj("snake");
  set_short( "average snake" );
  set_long( "Before you stands a average snake. It smells like sewer and appears to be covered in blood." );

  set_gender("neuter");
  set_race("snake");

  set_level(6);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 30);
  set_skill("combat/defense", 30);
  add_object(DIR + "/objects/con_potion.c", 9);
}
