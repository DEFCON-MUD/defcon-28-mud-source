inherit "/std/monster";
#include "../domain.h" 

void setup( void ) {
   set_name("technician");
   set_short("A technician");
   set_long("A technician");
   set_gender("female");
   set_race("technician");
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 260);
   set_skill("combat/defense", 260);
   set_level(13);
}

