inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("ferret");
  add_adj("uninitiated");
  add_adj("ferret");
  set_short( "uninitiated ferret" );
  set_long( "Before you stands a uninitiated ferret. It smells like death and appears to be covered in blood." );

  set_gender("male");
  set_race("ferret");

  set_level(1);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 5);
  set_skill("combat/defense", 5);
  add_object(DIR + "/objects/wis_potion.c", 9);
}
