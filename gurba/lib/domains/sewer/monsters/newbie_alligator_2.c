inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("alligator");
  add_adj("newbie");
  add_adj("alligator");
  set_short( "newbie alligator" );
  set_long( "Before you stands a newbie alligator. It smells like sewer and appears to be covered in dirt." );

  set_gender("male");
  set_race("alligator");

  set_level(2);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 10);
  set_skill("combat/defense", 10);
  add_object(DIR + "/objects/str_potion.c", 9);
}
