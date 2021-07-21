inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("parrot");
  add_adj("average");
  add_adj("parrot");
  set_short( "average parrot" );
  set_long( "Before you stands a average parrot. It smells like hacker and appears to be covered in gunk." );

  set_gender("male");
  set_race("parrot");

  set_level(6);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 30);
  set_skill("combat/defense", 30);
  add_object(DIR + "/objects/int_potion.c", 9);
}
