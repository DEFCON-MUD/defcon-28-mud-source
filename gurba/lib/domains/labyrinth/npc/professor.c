inherit "/std/monster";
#include "../domain.h" 

void setup( void ) {
   set_name("professor");
   set_short("A professor");
   set_long("A professor");
   set_gender("female");
   set_race("professor");
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 120);
   set_skill("combat/defense", 120);
   set_level(6);
}

