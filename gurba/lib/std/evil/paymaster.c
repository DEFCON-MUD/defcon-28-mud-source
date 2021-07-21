inherit "/std/modules/m_triggers";

private int contains(string needle, string hay) {
   return sscanf(hay, "%*s" + needle + "%*s") == 2;
}

void handle_say(string str) {
   string a, b, message;
   int paynew, paydiff, lvl;
   object player;

   sscanf(str, "%s %s", a, b);
   if ( a == this_object()->query_name()) {
      return;
   }

   if (sscanf(str, "%s says: %s\n", a, b) != 2) {
      return;
   }
   str = lowercase(b);
   player = USER_D->find_player(a);
   if (contains("pay me", str) || contains("pay", str) ||
      contains("credits", str)) {
      paydiff = (time() - (player->query_lastpaid()));
      paynew = 60 + random(30);

      message = "say You aren't due for another %^GREY%^"+ (90 - paydiff) + "%^RESET%^ cycles.....";
      if (paydiff > paynew) {
        player->set_lastpaid();
        lvl = player->query_level();
        player->add_money("credit", (lvl * 1000));
        message = "say it appears I owe you " + (lvl * 1000); + "Credits.";
      }
   }
   if (contains("shut up", str)) {
      message = "say Why do you want me to shut up ?";
   }
   if (!message) {
      message = "shrug";
   }
   respond(message);
}

void outside_message(string str) {
   /* XXX some from these can be spoofed with player emotes... */
   if (this_object()->is_fighting()) {
      return;
   }

   str = ANSI_D->strip_colors(str);

   handle_say(str);

}



int do_payroll(object who) {
  mixed lastpay;
  mixed curtime;
}

int pay_me(string str) {
  do_payroll(this_player());
  return 0;
}

