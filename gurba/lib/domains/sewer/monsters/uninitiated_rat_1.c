inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("rat");
  add_adj("uninitiated");
  add_adj("rat");
  set_short( "uninitiated rat" );
  set_long( "Before you stands a uninitiated rat. It smells like hacker and appears to be covered in sewage." );

  set_gender("neuter");
  set_race("rat");

  set_level(1);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 5);
  set_skill("combat/defense", 5);
  add_object(DIR + "/objects/wis_potion.c", 9);
}
