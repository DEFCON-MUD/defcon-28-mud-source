inherit "/std/sign";

void setup(void) {
   set_id("sign");
   set_short("A sign");
   set_long("This is an average wooden sign, perhaps you should try reading it");
   set_message("Welcome to woodland critter christmas:\n\nYour mission is to exterminate one of every type of creature. Once you do you will complete the quest and unlock the next flag.\n\nOnce you have completed the quest type %^MAGENTA%^claim%^RESET%^ to claim your prize.\n\nDuring the quest you can check your status by the %^MAGENTA%^woodland%^RESET%^ command.\n");
   set_message_mxp("%^MXP_LSM%^Welcome to woodland critter christmas:\n\nYour mission is to exterminate one of every type of creature. Once you do you will complete the quest and unlock the next flag.\n\nOnce you have completed the quest type %^MAGENTA%^<send href=\"claim\">claim</send>%^RESET%^ to claim your prize.\n\nDuring the quest you can check your status by the %^MAGENTA%^<send href=\"woodland\">woodland</send>%^RESET%^ command.\n");
   set_gettable(0);
   set_weight(1);
   /* This isn't a special rock... */
   set_value(0);
   add_action("do_woodland", "woodland");
   add_action("do_claim", "claim");
}

int do_claim(string arg) {
  object usr;
  usr = this_player();
  if (usr->is_completed_quest("Woodland")) {
     write("Congrats you have completed the quest....\nYour flag is %^MAGENTA%^" + FLAG_D->query_flag("WOODLAND") + "%^RESET%^\n");
     return 1;
  } else {
     write("You have not completed the woodland critter quest.....\n");
     return 1;
  }
  return 1;
}

int do_woodland(string arg) {
 object usr;
 int *wlf;
 int results;
 string lines;
 results = 0;
 lines = "";
 usr = this_player();

 if (usr->is_completed_quest("Woodland")) {
   write("You have already completed the Woodland Quest....\n");
   return 1;
 }

 wlf = usr->get_woodland_kills();

 if (wlf) {
   results = wlf[0] + wlf[1] + wlf[2] + wlf[3] + wlf[4] + wlf[5] + wlf[6] + wlf[7] + wlf[8] + wlf[9] + wlf[10] + wlf[11] + wlf[12] + wlf[13] + wlf[14] + wlf[15] + wlf[16];
   lines += "You have killed a total of " + results + " woodland creatures out of 17.\n";
   write(lines);
   if (results == 17) {
     CHANNEL_D->chan_send_string("announce", "", usr->query_name() +" has completed the woodland critter quest", 1);
     usr->add_completed_quest("Woodland");
     usr->increase_expr(10000);
   }

   return 1;
 } else {
   usr->set_woodland_kills(( { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ));
   lines += "You have no progress, setting up your quest counter";
   write(lines);
   return 1;
 }
 return 1;

}
