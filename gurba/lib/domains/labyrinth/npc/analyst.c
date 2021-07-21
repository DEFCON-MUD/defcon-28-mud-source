inherit "/std/monster";
#include "../domain.h" 

void setup( void ) {
   set_name("analyst");
   set_short("An analyst");
   set_long("An analyst");
   set_gender("male");
   set_race("analyst");
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 140);
   set_skill("combat/defense", 140);
   set_level(7);
}

