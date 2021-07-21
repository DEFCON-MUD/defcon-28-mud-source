inherit "/std/monster";
#include "../domain.h" 

void setup( void ) {
   set_name("salesdroid");
   set_short("A salesdroid");
   set_long("A salesdroid");
   set_gender("female");
   set_race("salesdroid");
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 120);
   set_skill("combat/defense", 120);
   set_level(6);
}

