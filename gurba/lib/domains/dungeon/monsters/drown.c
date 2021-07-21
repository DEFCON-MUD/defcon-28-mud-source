inherit "/std/monster";

#include "../domain.h"

void setup(void) {
   set_name("drown");

   /* Leave out the gender specification, get a random one */
   /*  set_gender( "male" ); */

   set_short("DROWN");
   set_long("This is a vulnerability of mythical proporions, very few have code to exploit it.");
   set_race("vuln");
   set_level(15);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 100);
   set_skill("combat/defense", 1);
}
