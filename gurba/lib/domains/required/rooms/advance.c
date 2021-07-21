inherit "/std/room";
inherit "/std/evil/advance";

void setup(void) {
   add_area("required");

   set_short("Advancement Room");
   set_long("This is an advancement room. It is a very dull and empty room. Somehow EvilMog has sucked all the joy out of advancing.\n\nTo advance a level type %^MAGENTA%^advance%^RESET%^ and if you are found worthy you will advance.\nTo complete the ticket quest type %^MAGENTA%^claim%^RESET%^ and if you have all the keys it will be yours.\nTo get a list of quests type %^MAGENTA%^quests%^RESET%^.\nTo re-roll your stats type %^MAGENTA%^recast%^RESET%^.");

   add_action("do_advance", "advance");
   add_action("do_quest", "claim");
   add_action("do_quests", "quests");
   add_action("do_recast", "recast");

   set_exits(([
      "east" : "/domains/newbie/rooms/tree.c",
   ]));

}
