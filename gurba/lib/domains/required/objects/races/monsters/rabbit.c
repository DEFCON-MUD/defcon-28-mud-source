inherit "/std/monster_race";

void create(void) {
   ::create();
   set_race_short_desc("A rabbit...");
   set_race_long_desc("This is a rabbit.");
   base_stat_minimum["str"] = 1;
   base_stat_minimum["con"] = 1;
   base_stat_minimum["dex"] = 1;
   base_stat_minimum["int"] = 1;
   base_stat_minimum["wis"] = 1;
   base_stat_minimum["cha"] = 1;

   base_stat_maximum["str"] = 20;
   base_stat_maximum["con"] = 20;
   base_stat_maximum["dex"] = 30;
   base_stat_maximum["int"] = 20;
   base_stat_maximum["wis"] = 20;
   base_stat_maximum["cha"] = 20;
}
