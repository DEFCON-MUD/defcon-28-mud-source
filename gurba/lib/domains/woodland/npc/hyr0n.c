inherit "/std/monster";
inherit "/std/modules/m_wander";

#include "../domain.h"

void setup(void) {
  set_name("hyr0n the gerbil");
  add_id("hyr0n");
  add_id("gerbil");
  set_short( "hyr0n the gerbil" );
  set_long( "A small light brown furry gerbil. He has a white tummy, and very sharp claws. He is very cute, and quite friendly but scared of strangers. He will probably run from you if you come near him.\n\nA flag for the AND!XOR badge... %^EXT_122%^flag:2LwRLe%^RESET%^\n" );

  set_gender("male");
  set_race("gerbil");

  set_level(20);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 360);
  set_skill("combat/defense", 360);

  if (next_clone()) {
    call_out("destroy_me", 0.1, "");
   }

  set_wander_area("woodland");
  start_wander(4, 10);

}

int destroy_me(string args) {
  this_object()->destruct();
  return 1;
}
