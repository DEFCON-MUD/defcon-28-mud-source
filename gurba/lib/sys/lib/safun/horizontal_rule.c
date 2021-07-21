string horizontal_rule(object "/sys/obj/player" player, string str) {
   int width, i;
   string retval;

   width = this_player()->query_width();
   if (width > 80) {
     width = 80;
   }

   for (retval = "", i = 0; i < width; i += strlen(str) ) {
      retval += str;
   }

   return retval;
}

