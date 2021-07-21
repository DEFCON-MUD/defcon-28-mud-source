/* Definition of the hacker race */
inherit "/std/race";

void create(void) {
   ::create();

   set_race_short_desc("Goons are player killing enabled denizens of the DEFCON MUD");
   set_race_long_desc("This is a goon, they like to player kill, remember, hug a goon today.");
   set_language("english");

   base_stat_minimum["str"] = 1;
   base_stat_minimum["con"] = 1;
   base_stat_minimum["dex"] = 1;
   base_stat_minimum["int"] = 1;
   base_stat_minimum["wis"] = 1;
   base_stat_minimum["cha"] = 1;

   base_stat_maximum["str"] = 30;
   base_stat_maximum["con"] = 30;
   base_stat_maximum["dex"] = 30;
   base_stat_maximum["int"] = 30;
   base_stat_maximum["wis"] = 30;
   base_stat_maximum["cha"] = 1;

}

