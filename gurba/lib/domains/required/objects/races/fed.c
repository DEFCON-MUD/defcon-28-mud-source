/* Definition of the hacker race */
inherit "/std/race";

void create(void) {
   ::create();

   set_race_short_desc("Feds are boring people in suits...");
   set_race_long_desc("This is a boring and stuff fed, they have no imagination and are otherwise completely unremarkable.");
   set_language("english");
   set_difficulty(1);

   base_stat_minimum["str"] = 1;
   base_stat_minimum["con"] = 1;
   base_stat_minimum["dex"] = 1;
   base_stat_minimum["int"] = 12;
   base_stat_minimum["wis"] = 12;
   base_stat_minimum["cha"] = 1;

   base_stat_maximum["str"] = 30;
   base_stat_maximum["con"] = 30;
   base_stat_maximum["dex"] = 30;
   base_stat_maximum["int"] = 30;
   base_stat_maximum["wis"] = 30;
   base_stat_maximum["cha"] = 2;

}
