inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  string MEHFERRET;
  MEHFERRET = FLAG_D->query_flag("MEHFERRET");
  set_name("ferret");
  add_adj("meh");
  add_adj("ferret");
  set_short( "meh ferret" );
  set_long( "Before you stands a meh ferret. It smells like uggghhhhh and appears to be covered in sewage.\n\n" + MEHFERRET + "\n\n" );

  set_gender("neuter");
  set_race("ferret");

  set_level(3);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 15);
  set_skill("combat/defense", 15);
  add_object(DIR + "/objects/str_potion.c", 9);
}
