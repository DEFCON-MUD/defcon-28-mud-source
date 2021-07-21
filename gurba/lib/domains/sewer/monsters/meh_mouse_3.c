inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("mouse");
  add_adj("meh");
  add_adj("mouse");
  set_short( "meh mouse" );
  set_long( "Before you stands a meh mouse. It smells like death and appears to be covered in blood." );

  set_gender("male");
  set_race("mouse");

  set_level(3);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 15);
  set_skill("combat/defense", 15);
  add_object(DIR + "/objects/cha_potion.c", 9);
}
