inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("parrot");
  add_adj("mediocre");
  add_adj("parrot");
  set_short( "mediocre parrot" );
  set_long( "Before you stands a mediocre parrot. It smells like death and appears to be covered in oil." );

  set_gender("male");
  set_race("parrot");

  set_level(4);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 20);
  set_skill("combat/defense", 20);
  add_object(DIR + "/objects/wis_potion.c", 9);
}
