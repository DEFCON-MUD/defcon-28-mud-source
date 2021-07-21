
inherit "/std/object";

void setup(void) {
   set_id("lockpick");
   add_id("pick");
   add_id("lockpick");
   add_id("lock");
   set_short("A lockpick");
   set_long("A lockpick. type pick to use it");
   set_gettable(1);
   set_value(1);
   set_weight(2);
}


