inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Usage: recall [-h]" });
   lines += ({ "" });
   lines += ({ "sends you back to start" });
   lines += ({ "" });
   lines += ({ "Options:" });
   lines += ({ "\t-h\tHelp, this usage message." });
   lines += ({ "Examples:" });
   lines += ({ "\trecall" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "look");
   add_also("wiz", "last");
   add_also("wiz", "locate");
   add_also("wiz", "mudlist");
   add_also("wiz", "possess");
   add_also("wiz", "rwho");
   add_also("wiz", "snoop");
   add_also("wiz", "where");
}

int do_recall(void) {
   object player;
   player = this_player();
   player->set_end(20);
   player->set_hp(5);
   player->set_mp(0);
   player->move(player->query_start_room());
   call_other(player, "do_look", this_environment());
}


static void main(string str) {
   write("You contact the company command center and request a recall....");
   call_out("do_recall", (random(10)));
 
}


