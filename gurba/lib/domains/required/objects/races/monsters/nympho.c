inherit "/std/monster_race";

void create(void) {
   ::create();
   set_race_short_desc("A bio weapon");
   set_race_long_desc("A bio engineered assassin, deadly, beautiful, silent.");
   base_stat_minimum["str"] = 20;
   base_stat_minimum["con"] = 20;
   base_stat_minimum["dex"] = 20;
   base_stat_minimum["int"] = 20;
   base_stat_minimum["wis"] = 20;
   base_stat_minimum["cha"] = 20;

   base_stat_maximum["str"] = 40;
   base_stat_maximum["con"] = 40;
   base_stat_maximum["dex"] = 40;
   base_stat_maximum["int"] = 40;
   base_stat_maximum["wis"] = 40;
   base_stat_maximum["cha"] = 40;
}
