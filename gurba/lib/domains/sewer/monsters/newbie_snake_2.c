inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("snake");
  add_adj("newbie");
  add_adj("snake");
  set_short( "newbie snake" );
  set_long( "Before you stands a newbie snake. It smells like death and appears to be covered in sewage." );

  set_gender("male");
  set_race("snake");

  set_level(2);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 10);
  set_skill("combat/defense", 10);
  add_object(DIR + "/objects/con_potion.c", 9);
}
