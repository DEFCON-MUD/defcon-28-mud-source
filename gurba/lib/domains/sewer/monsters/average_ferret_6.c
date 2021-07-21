inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  set_name("ferret");
  add_adj("average");
  add_adj("ferret");
  set_short( "average ferret" );
  set_long( "Before you stands a average ferret. It smells like sewer and appears to be covered in gunk." );

  set_gender("neuter");
  set_race("ferret");

  set_level(6);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 30);
  set_skill("combat/defense", 30);
  add_object(DIR + "/objects/wis_potion.c", 9);
}
