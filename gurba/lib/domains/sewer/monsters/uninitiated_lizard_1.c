inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("lizard");
  add_adj("uninitiated");
  add_adj("lizard");
  set_short( "uninitiated lizard" );
  set_long( "Before you stands a uninitiated lizard. It smells like hacker and appears to be covered in sewage." );

  set_gender("male");
  set_race("lizard");

  set_level(1);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 5);
  set_skill("combat/defense", 5);
  add_object(DIR + "/objects/cha_potion.c", 9);
}
