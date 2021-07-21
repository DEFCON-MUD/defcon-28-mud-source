inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("lizard");
  add_adj("strong");
  add_adj("lizard");
  set_short( "strong lizard" );
  set_long( "Before you stands a strong lizard. It smells like sewer and appears to be covered in dirt." );

  set_gender("female");
  set_race("lizard");

  set_level(7);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 35);
  set_skill("combat/defense", 35);
  add_object(DIR + "/objects/int_potion.c", 9);
}
