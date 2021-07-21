inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("ferret");
  add_adj("newbie");
  add_adj("ferret");
  set_short( "newbie ferret" );
  set_long( "Before you stands a newbie ferret. It smells like sewer and appears to be covered in dirt." );

  set_gender("male");
  set_race("ferret");

  set_level(2);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 10);
  set_skill("combat/defense", 10);
  add_object(DIR + "/objects/wis_potion.c", 9);
}
