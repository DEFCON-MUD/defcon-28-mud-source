/* Definition of the hacker race */
inherit "/std/race";

void create(void) {
   ::create();

   set_race_short_desc("Hackers are a cut above, special in every way..");
   set_race_long_desc("Hackers are dark loving creatures, they rarely venture out and are" +
                      "extremely mischievous. They are special in every way.");
   set_language("english");

   base_stat_minimum["str"] = 10;
   base_stat_minimum["con"] = 10;
   base_stat_minimum["dex"] = 10;
   base_stat_minimum["int"] = 10;
   base_stat_minimum["wis"] = 10;
   base_stat_minimum["cha"] = 10;

   base_stat_maximum["str"] = 33;
   base_stat_maximum["con"] = 33;
   base_stat_maximum["dex"] = 33;
   base_stat_maximum["int"] = 33;
   base_stat_maximum["wis"] = 33;
   base_stat_maximum["cha"] = 33;

}
