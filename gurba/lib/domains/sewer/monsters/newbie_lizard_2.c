inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("lizard");
  add_adj("newbie");
  add_adj("lizard");
  set_short( "newbie lizard" );
  set_long( "Before you stands a newbie lizard. It smells like sewer and appears to be covered in gunk." );

  set_gender("male");
  set_race("lizard");

  set_level(2);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 10);
  set_skill("combat/defense", 10);
  add_object(DIR + "/objects/int_potion.c", 9);
}
