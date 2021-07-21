inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
 set_objects( DIR+"/objects/wiz_potion.c");
 set_exits( ([
  "up" : DIR+"/rooms/9-h.c"
  ]) );
  set_long( "The floors and walls appear to be made of marble while the roof appears to be dripping some kind of green liquid.  The floors and wall also appear to be covered in some kind of oil. A red button is on the wall.%^RESET%^");
   add_item("red button",
      "A giant red BUTTON!\nIt is glowing and says PRESS ME!");
     add_item("button", "A giant red BUTTON!\nIt is glowing and says PRESS ME!");
   add_action("do_push", "push");
   add_action("do_push", "press");
}

int do_push(string arg) {
   if (arg == "button") {
      object obj;

      write("You push the button and out of nowhere a new wiz potion appears.\n");

      obj = clone_object(DIR+"/objects/wiz_potion.c");
      obj->setup();
      obj->move(this_player()->query_environment());
      return 1;
   } else {
      return 0;
   }
}
