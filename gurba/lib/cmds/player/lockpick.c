inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Usage: lockpick [-h]" });
   lines += ({ "" });
   lines += ({ "Picks the lock of the room you are in" });
   lines += ({ "" });
   lines += ({ "Options:" });
   lines += ({ "\t-h\tHelp, this usage message." });
   lines += ({ "Examples:" });
   lines += ({ "\tlockpick" });

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

int has_lockpick() {
   object obj;

   obj = this_player()->present("lockpick");

   if (obj) {
      return 1;
   }
   return 0;
}

int pickable() {
  if (LOCK_D->is_locked(this_environment()->file_name())) {
    return 0;
  } else {
    return 1;
  }
}

static void main(string str) {

   if (!pickable()) {
     write("You fail to pick the lock.....\n");
   } else if (has_lockpick()) {
     write("You pick the lock.\n");
     this_player()->this_environment()->lockpick_door();
   } else {
     write("You have no lock picks.\n");
  }
}

