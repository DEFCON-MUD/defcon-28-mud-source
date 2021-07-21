inherit "/std/monster";

#include "../domain.h"

void setup(void) {
   set_name("heartbleed");

   /* Leave out the gender specification, get a random one */
   /*  set_gender( "male" ); */

   set_short("Heartbleed");
   set_long("This is an ancient vulnerability, no idea how its still here.");
   set_race("vuln");
   set_level(4);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 20);
   set_skill("combat/defense", 1);
   add_object(DIR + "/objects/cha_potion.c", 9);
}
