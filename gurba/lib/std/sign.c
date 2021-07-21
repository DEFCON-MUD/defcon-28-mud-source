/* Created by Fudge */

inherit "/std/object";
inherit "/std/modules/m_readable";

void create(void) {
   ::create();
   set_id("sign");
   set_short("A wooden sign");
   set_long("Your average wooden sign.  It has some writing on it.");
   set_long_mxp("You average wooden %^MXP_LSM%^<send \"read &text;\">sign</send>%^MXP_LLM%^.  It has some writing on it.");
   set_gettable(0);
}
