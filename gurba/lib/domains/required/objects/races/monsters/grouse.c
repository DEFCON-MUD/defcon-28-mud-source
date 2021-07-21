inherit "/std/monster_race";

void create(void) {
   ::create();
   set_race_short_desc("A grouse...");
   set_race_long_desc("This is a grouse.");
   base_stat_maximum["str"] = 30;
   base_stat_maximum["con"] = 20;
   base_stat_maximum["dex"] = 30;
   base_stat_maximum["int"] = 20;
   base_stat_maximum["wis"] = 20;
   base_stat_maximum["cha"] = 20;
}
