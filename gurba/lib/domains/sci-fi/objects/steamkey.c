
inherit "/std/object";
inherit "std/modules/m_undroppable";

void setup(void) {
   set_id("steamkey");
   add_id("key");
   add_id("steam");
   add_id("steam key");
   set_short("A steam key");
   set_long("A steam panel access key, somehow through magic physics and stuff it deals with the steam, don't ask me its a plothole and it magicall works, if you don't like it take it up with EvilMog and his lazy coding.");
   set_gettable(1);
   set_undroppable(1);
   set_value(8);
   set_weight(2);
}
