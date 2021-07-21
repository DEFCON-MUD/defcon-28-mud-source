inherit "/std/monster";

#include "../domain.h"

void setup(void) {
   set_name("wpad");

   /* Leave out the gender specification, get a random one */
   /*  set_gender( "male" ); */

   set_short("WPAD");
   set_long("This is the easy vuln, its basically easy mode for all domains.");
   set_race("vuln");
   set_level(5);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 20);
   set_skill("combat/defense", 1);
}
