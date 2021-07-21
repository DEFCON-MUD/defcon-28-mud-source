inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  string MEDIOCREALIGATOR;
  MEDIOCREALIGATOR = FLAG_D->query_flag("MEDIOCREALIGATOR");
  set_name("alligator");
  add_adj("mediocre");
  add_adj("alligator");
  set_short( "mediocre alligator" );
  set_long( "Before you stands a mediocre alligator. It smells like death and appears to be covered in sewage.\n\n" + MEDIOCREALIGATOR + "\n\n" );

  set_gender("neuter");
  set_race("alligator");

  set_level(4);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 20);
  set_skill("combat/defense", 20);
}
