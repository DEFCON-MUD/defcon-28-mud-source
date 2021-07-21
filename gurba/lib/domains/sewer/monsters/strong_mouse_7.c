inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("mouse");
  add_adj("strong");
  add_adj("mouse");
  set_short( "strong mouse" );
  set_long( "Before you stands a strong mouse. It smells like death and appears to be covered in oil." );

  set_gender("female");
  set_race("mouse");

  set_level(7);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 35);
  set_skill("combat/defense", 35);
  add_object(DIR + "/objects/cha_potion.c", 9);
}
