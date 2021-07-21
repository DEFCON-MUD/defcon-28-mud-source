inherit "/std/room";

#define FILE + "/domains/required/rooms/start.c"

void setup(void) {

   add_area("required");

   set_short("Afterlife");
   set_long("Somehow you have wound up in the afterlife, either you died, or you encountered a rift in reality, either way you are very much dead.\n\nYou can get your body back, but I must warn you, when you exit from here you will be reset to level 1.");

   set_exits(([
      "out" : "#rebirth",
   ]));
}

void rebirth(void) {
   object obj;

   if (this_player()->is_dead()) {
      this_player()->set_start_room("/domains/required/rooms/void.c");
      write("You cannot return to the land of the living until you get your body back.");
      this_object()->tell_room(this_player(), this_player()->query_Name() +
         " tries to return to the mortal realm but fails " +
         "because they are dead.");
      return;
   } else {
      obj = find_object(FILE);
      if (!obj) {
         obj = compile_object(FILE);
         if (!obj) {
            write("Error in loading destination.\n");
            return;
         }
         obj->setup();
         obj->setup_mudlib();
      }
      if (this_player()->move(obj)) {
         write("You crash into the ground below as you are ejected from the Afterlife.");
         this_object()->tell_room(this_player(),
         this_player()->query_Name() + " crashes down into the earth having been ejected from the Afterlife.\n");
         this_player()->do_look(this_environment());
         this_player()->set_start_room(FILE);
      }
   }
   return;
}
