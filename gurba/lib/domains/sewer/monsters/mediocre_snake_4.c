inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("snake");
  add_adj("mediocre");
  add_adj("snake");
  set_short( "mediocre snake" );
  set_long( "Before you stands a mediocre snake. It smells like hacker and appears to be covered in oil." );

  set_gender("female");
  set_race("snake");

  set_level(4);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 20);
  set_skill("combat/defense", 20);
  add_object(DIR + "/objects/dex_potion.c", 9);
}
