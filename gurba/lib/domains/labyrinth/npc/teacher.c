inherit "/std/monster";
#include "../domain.h" 

void setup( void ) {
   set_name("teacher");
   set_short("A teacher");
   set_long("A teacher");
   set_gender("male");
   set_race("teacher");
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 220);
   set_skill("combat/defense", 220);
   set_level(11);
}

