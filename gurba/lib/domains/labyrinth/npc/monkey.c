inherit "/std/monster";
#include "../domain.h" 

void setup( void ) {
   set_name("monkey");
   set_short("A monkey");
   set_long("A monkey");
   set_gender("male");
   set_race("monkey");
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 200);
   set_skill("combat/defense", 200);
   set_level(10);
}

