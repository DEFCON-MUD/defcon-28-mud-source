inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("rat");
  add_adj("newbie");
  add_adj("rat");
  set_short( "newbie rat" );
  set_long( "Before you stands a newbie rat. It smells like hacker and appears to be covered in gunk." );

  set_gender("female");
  set_race("rat");

  set_level(2);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 10);
  set_skill("combat/defense", 10);
  add_object(DIR + "/objects/str_potion.c", 9);
}
