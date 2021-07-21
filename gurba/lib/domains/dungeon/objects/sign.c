#include "../domain.h"

inherit "/std/sign";

void setup(void) {
   set_message("Area Guide:\n\n   North:   Newbie & Woodland");
   set_long("This is an average sign, you should try reading it");
   set_long_mxp("This is an average sign, you should try to %^MXP_LSM%^<send \"read sign\">read</send>%^MXP_LLM%^ it.");
}
