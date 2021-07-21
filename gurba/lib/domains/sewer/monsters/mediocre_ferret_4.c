inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("ferret");
  add_adj("mediocre");
  add_adj("ferret");
  set_short( "mediocre ferret" );
  set_long( "Before you stands a mediocre ferret. It smells like death and appears to be covered in dirt." );

  set_gender("male");
  set_race("ferret");

  set_level(4);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 20);
  set_skill("combat/defense", 20);
  add_object(DIR + "/objects/con_potion.c", 9);
}
