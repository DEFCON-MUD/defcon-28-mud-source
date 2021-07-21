inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Usage: compass [-h]" });
   lines += ({ "" });
   lines += ({ "Displays the co-ordinates of the room you are in" });
   lines += ({ "" });
   lines += ({ "Options:" });
   lines += ({ "\t-h\tHelp, this usage message." });
   lines += ({ "Examples:" });
   lines += ({ "\tmap" });

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
   add_also("player", "compass");
}

static void main(string str) {
 object *usr;
 int *coords, *dimensions, *map_start, *map_end;
 int x, y;
 string lines, domain_name;

 lines = "";

 if (!alsos) {
    setup_alsos();
 }

 coords = this_environment()->get_coords();
 dimensions = this_environment()->get_dimensions();
 domain_name = this_environment()->get_domainname();
 map_start = this_environment()->get_mapstart();
 map_end = (({ (map_start[0]+dimensions[0]), (map_start[1]+dimensions[1]) }));

 if (coords && dimensions[1]) {
   lines += "*";
   for (x = map_start[0]; x < map_end[0]; x++) {
       lines += "-";
   }
   lines += "*";
   lines += "\n";
   for (y = map_start[1]; y < map_end[1]; y++) {
     lines += "|";
     for (x = map_start[0]; x < map_end[0]; x++) {
       if(x == coords[0] && y == coords[1]) {
         lines += "%^RED%^*%^RESET%^";
       } else {
         lines += ".";
       }
     }
     if (y == map_start[1] && domain_name) {
       lines += "| ";
       lines += domain_name;
       lines += "\n";
     } else if (y == (map_start[1] + 1)) {
       lines += "| %^YELLOW%^X: %^RESET%^%^BOLD%^%^";
       lines += coords[0];
       lines += " %^RESET%^%^YELLOW%^Y:%^RESET%^%^BOLD%^ -";
       lines += coords[1];
       lines += "%^RESET%^\n";
     } else {
       lines += "|\n";
     }
   }
     lines += "*";
   for (y = map_start[1]; y < map_end[0]; y++) {
       lines += "-";
   }
   lines += "*";
   lines += "\n";
   write(lines);
 } else {
   write("Sorry map doesn't work here, try %^GREEN%^compass%^RESET%^ instead.");
 }
}
