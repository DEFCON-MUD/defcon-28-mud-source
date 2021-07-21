inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("eel");
  add_adj("meh");
  add_adj("eel");
  set_short( "meh eel" );
  set_long( "Before you stands a meh eel. It smells like death and appears to be covered in gunk." );

  set_gender("male");
  set_race("eel");

  set_level(3);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 15);
  set_skill("combat/defense", 15);
  add_object(DIR + "/objects/dex_potion.c", 9);
}
