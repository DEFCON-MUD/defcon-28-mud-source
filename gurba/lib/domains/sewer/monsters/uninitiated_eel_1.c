inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  string UNINITIATEDEEL;
  UNINITIATEDEEL = FLAG_D->query_flag("UNINITIATEDEEL");
  set_name("eel");
  add_adj("uninitiated");
  add_adj("eel");
  set_short( "uninitiated eel" );
  set_long( "Before you stands a uninitiated eel. It smells like uggghhhhh and appears to be covered in blood.\n\n" + UNINITIATEDEEL + "\n\n" );

  set_gender("neuter");
  set_race("eel");

  set_level(1);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 5);
  set_skill("combat/defense", 5);
  add_object(DIR + "/objects/dex_potion.c", 9);
}
