inherit "/std/monster";

#include "../domain.h"

void setup(void) {
   set_name("ms17-010");

   /* Leave out the gender specification, get a random one */
   /*  set_gender( "male" ); */

   set_short("MS17-010");
   set_long("This is an ancient vulnerability, no idea how its still here.");
   set_race("vuln");
   set_level(2);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 10);
   set_skill("combat/defense", 1);
}
