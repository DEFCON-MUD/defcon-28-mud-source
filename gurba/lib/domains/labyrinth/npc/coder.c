inherit "/std/monster";
#include "../domain.h" 

void setup( void ) {
   set_name("coder");
   set_short("A coder");
   set_long("A coder");
   set_gender("female");
   set_race("coder");
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 140);
   set_skill("combat/defense", 140);
   set_level(7);
}

