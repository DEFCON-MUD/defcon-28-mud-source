inherit "/std/monster_race";

void create(void) {
   ::create();
   set_race_short_desc("A zombie...");
   set_race_long_desc("Guess what, its a zombie, evilmog is lazy, get used to it..");
   base_stat_minimum["str"] = 30;
   base_stat_minimum["con"] = 30;
   base_stat_minimum["dex"] = 30;
   base_stat_minimum["int"] = 30;
   base_stat_minimum["wis"] = 30;
   base_stat_minimum["cha"] = 30;

   base_stat_maximum["str"] = 30;
   base_stat_maximum["con"] = 30;
   base_stat_maximum["dex"] = 30;
   base_stat_maximum["int"] = 30;
   base_stat_maximum["wis"] = 30;
   base_stat_maximum["cha"] = 30;
}
