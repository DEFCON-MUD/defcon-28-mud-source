inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("rat");
  add_adj("average");
  add_adj("rat");
  set_short( "average rat" );
  set_long( "Before you stands a average rat. It smells like death and appears to be covered in dirt." );

  set_gender("male");
  set_race("rat");

  set_level(6);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 30);
  set_skill("combat/defense", 30);
  add_object(DIR + "/objects/str_potion.c", 9);
}
