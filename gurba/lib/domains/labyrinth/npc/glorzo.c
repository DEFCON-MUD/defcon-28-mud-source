inherit "/std/monster";
#include "../domain.h" 

void setup( void ) {
   set_name("glorzo");
   set_short("A glorzo");
   set_long("A glorzo");
   set_gender("male");
   set_race("glorzo");
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 120);
   set_skill("combat/defense", 120);
   set_level(6);
}

