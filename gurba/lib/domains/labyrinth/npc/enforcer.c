inherit "/std/monster";
#include "../domain.h" 

void setup( void ) {
   set_name("enforcer");
   set_short("A enforcer");
   set_long("A enforcer");
   set_gender("female");
   set_race("enforcer");
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 120);
   set_skill("combat/defense", 120);
   set_level(6);
}

