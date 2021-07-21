inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  string MEHRAT;
  MEHRAT = FLAG_D->query_flag("MEHRAT");
  set_name("rat");
  add_adj("meh");
  add_adj("rat");
  set_short( "meh rat" );
  set_long( "Before you stands a meh rat. It smells like death and appears to be covered in dirt.\n\n" + MEHRAT + "\n\n" );

  set_gender("neuter");
  set_race("rat");

  set_level(3);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 15);
  set_skill("combat/defense", 15);
}
