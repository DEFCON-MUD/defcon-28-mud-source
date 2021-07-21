inherit "/std/object";

void setup(void) {
  set_short("a map");
  set_long(this_player()->query_environment()->file_name());
  set_id("map");
   set_gettable(1);
   set_weight(1);
   /* This isn't a special rock... */
   set_value(0);
}
