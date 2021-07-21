inherit "/std/monster";

#include "../domain.h"

void setup(void) {
  string UNINITIATEDSNAKE;
  UNINITIATEDSNAKE = FLAG_D->query_flag("UNINITIATEDSNAKE");
  set_name("snake");
  add_adj("uninitiated");
  add_adj("snake");
  set_short( "uninitiated snake" );
  set_long( "Before you stands a uninitiated snake. It smells like sewer and appears to be covered in blood.\n\n" + UNINITIATEDSNAKE + "\n\n" );

  set_gender("male");
  set_race("snake");

  set_level(1);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 5);
  set_skill("combat/defense", 5);
}
