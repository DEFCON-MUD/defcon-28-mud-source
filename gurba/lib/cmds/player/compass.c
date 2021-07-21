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
   lines += ({ "\tcompass" });

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
   add_also("player", "map");
}

/* 'who' command Originally by Fudge Improved by Cerihan 3/15/09 */
static void main(string str) {
   object *usr;
   string *out;
   string lines;
   string d_lines;
   mixed x;
   mixed y;
   mixed z;
   int c_x;
   int c_y;
   mixed dome_size;
   int map_x;
   int map_y;
   mixed loop_x;
   mixed loop_y;
   int mapstop;
   mixed adj_r;
   mixed adj_t;

   if (!alsos) {
      setup_alsos();
   }


   x = this_environment()->property("x");
   y = this_environment()->property("y");
   z = this_environment()->property("z");

   if (!(this_environment()->property("x"))) {
     if (!(this_environment()->property("y"))) {
        if (this_environment()->property("z") != 0) {
          write("The compass does not work here, try %^GREEN%^map%^RESET%^ instead.");
          return;
        }
     }
   }
   if (!this_environment()->property("c_x")) {
     c_x = 0;
   } else {
     c_x = this_environment()->property("c_x");
   }
   if (!this_environment()->property("c_y")) {
     c_y = 0;
   } else {
     c_y = this_environment()->property("c_y");
   }
   if (!this_environment()->property("size")) {
     dome_size = 11;
   } else {
     dome_size = this_environment()->property("size");
   }
   lines="A nearby panel displays your location within the dome:\n\n";
   for (loop_y = c_y + (dome_size*10); loop_y > (c_y - ((dome_size + 1)*10)); loop_y=loop_y - 10) {
       for (loop_x = c_x - (dome_size*10); loop_x < (c_x + ((dome_size + 1)*10)); loop_x=loop_x + 10) {
         mapstop=1;
         if ( y == loop_y ) {
           if (x == loop_x ) {
             lines += "%^RED%^*%^RESET%^";
             mapstop = 2;
           }
         }

         if (loop_x == c_x && mapstop == 1) {
           if (loop_y == c_y) {
              lines += "+";
              mapstop = 2;
           }
         }

         if (loop_y == c_y && mapstop == 1) {
            lines += "-";
            mapstop = 2;
         }
         if (loop_x == c_x && mapstop == 1) {
            lines += "|";
            mapstop = 2;
         }
         if (mapstop == 1) {
              adj_t = ((loop_x - c_x) * (loop_x - c_x)) + ((loop_y - c_y) * (loop_y - c_y));
              adj_r = (dome_size * 10) * (dome_size * 10);
              if (adj_t < adj_r) {
            /* x and y must satisfy (x - center_x)^2 + (y - center_y)^2 < radius^2 */
              lines += ".";
         } else {
              lines += " ";
         }
            mapstop = 2;
         }
       }
   if (loop_y == c_y + (dome_size*10)) {
     lines += "   Coordinates: x=%^MAGENTA%^"+x+"%^RESET%^, y=%^MAGENTA%^" + y +"%^RESET%^, z=%^MAGENTA%^" + z + "%^RESET%^\n";
   } else if (loop_y == c_y + (dome_size*10) - 10) {
     lines += "   %^RED%^*%^RESET%^ = You are here\n";
   } else {
     lines += "\n";
   }
   }
   write(lines);
}
