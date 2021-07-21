inherit "/std/monster";
#include "../domain.h" 

void setup( void ) {
   set_name("dba");
   set_short("A dba");
   set_long("A dba");
   set_gender("female");
   set_race("dba");
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 160);
   set_skill("combat/defense", 160);
   set_level(8);
}

