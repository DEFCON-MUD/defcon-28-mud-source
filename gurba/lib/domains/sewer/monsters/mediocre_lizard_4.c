inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  string MEDIOCRELIZARD;
  MEDIOCRELIZARD = FLAG_D->query_flag("MEDIOCRELIZARD");
  set_name("lizard");
  add_adj("mediocre");
  add_adj("lizard");
  set_short( "mediocre lizard" );
  set_long( "Before you stands a mediocre lizard. It smells like hacker and appears to be covered in gunk.\n\n" + MEDIOCRELIZARD + "\n\n" );

  set_gender("male");
  set_race("lizard");

  set_level(4);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 20);
  set_skill("combat/defense", 20);
  add_object(DIR + "/objects/con_potion.c", 9);
}
