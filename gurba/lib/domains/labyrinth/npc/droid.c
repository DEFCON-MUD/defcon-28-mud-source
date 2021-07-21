inherit "/std/monster";
#include "../domain.h" 

void setup( void ) {
   set_name("droid");
   set_short("A droid");
   set_long("A droid");
   set_gender("male");
   set_race("droid");
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 180);
   set_skill("combat/defense", 180);
   set_level(9);
}

