inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("mouse");
  add_adj("sub-average");
  add_adj("mouse");
  set_short( "sub-average mouse" );
  set_long( "Before you stands a sub-average mouse. It smells like sewer and appears to be covered in dirt." );

  set_gender("neuter");
  set_race("mouse");

  set_level(5);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 25);
  set_skill("combat/defense", 25);
  add_object(DIR + "/objects/str_potion.c", 9);
}
