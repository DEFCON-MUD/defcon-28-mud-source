inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("ferret");
  add_adj("strong");
  add_adj("ferret");
  set_short( "strong ferret" );
  set_long( "Before you stands a strong ferret. It smells like sewer and appears to be covered in oil." );

  set_gender("neuter");
  set_race("ferret");

  set_level(7);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 35);
  set_skill("combat/defense", 35);
  add_object(DIR + "/objects/dex_potion.c", 9);
}
