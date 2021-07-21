inherit M_COMMAND;
inherit "/std/minerals";

void setup_alsos() {
   add_also("player", "stocks");
}

static void main(string str) {
   if (!alsos) {
      setup_alsos();
   }

   if (this_player()->is_dead()) {
      write("You can not do that when your are not among the living.\n");
      return;
   }

   do_playerminerals("haha");
}
