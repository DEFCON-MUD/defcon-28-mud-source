inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Usage: time [-h] [-s]" });
   lines += ({ "" });
   lines += ({ "Show what time it is, in mud time." });
   lines += ({ "" });
   lines += ({ "Options:" });
   lines += ({ "\t-h\tHelp, this usage message." });
   lines += ({ "\t-s\tShow the short version of game time." });
   lines += ({ "Examples:" });
   lines += ({ "\ttime" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "score");

   add_also("wiz", "date");
   add_also("wiz", "scan");
   add_also("wiz", "status");
}

static void main(string str) {
   int day;
   string txt, datetxt, *days, *hours, *years;

   if (!alsos) {
      setup_alsos();
   }

   if (!empty_str(str)) {
      if ((str == "-s") || (str == "-S")) {
         write(TIME_D->query_time());
      } else {
         this_player()->more(usage());
      }
      return;
   }

   write("It is " + TIME_D->query_time());
}
