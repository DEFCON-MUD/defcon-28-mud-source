/* Definition of the vuln race */
inherit "/std/monster_race";

void create(void) {
   ::create();

   set_race_short_desc("This is a vulnerability");
   set_race_long_desc("POP POP RET");
}
