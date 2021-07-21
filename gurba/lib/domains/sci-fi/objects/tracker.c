
inherit "/std/object";
inherit "/std/modules/m_undroppable";

void setup(void) {
   set_id("tracker");
   set_short("A tracker");
   set_long("This is an access card tracker, it tracks lost access cards. Type track to get started.");
   set_gettable(1);
   set_undroppable(1);
   set_value(8);
   set_weight(2);

   add_action("track_secard", "track");

}

int track_secard(string str) {
   mixed x;
   mixed y;
   mixed z;
   x = this_environment()->property("x");
   y = this_environment()->property("y");
   z = this_environment()->property("z");
   /* x40y-50z-10.c */
   if (z > -10) {
     write("The secard is below you.\n");
     return 1;
   }
   if (z < -10) {
     write("The secard is above you.\n");
     return 1;
   }
   if (x < 40) {
     write("The secard is to your east.\n");
     return 1;
   }
   if (x > 40) {
     write("The secard is to your west.\n");
     return 1;
   }
   /* x40y-50z-10.c */
   if (y > -50) {
     write("The secard is to your south.\n");
     return 1;
   }
   if (y < -50) {
     write("The secard is to your north.\n");
     return 1;
   }
  if (y = -50) {
     if (x = 40) {
       if (z = -10) {
         write("The secard should be here.\n");
         return 1;
       }
     }
  }
}
