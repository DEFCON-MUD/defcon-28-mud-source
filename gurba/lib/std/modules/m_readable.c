/* Created by Fudge */

static string readable_text;
static string readable_text_mxp;

void set_message(string message) {
   readable_text = message;
}

void set_message_mxp(string message) {
   readable_text_mxp = message;
}

string query_message(void) {
   if (this_player()->query_mxp() == 1 && readable_text_mxp) {
     return readable_text_mxp;
   } else {
     return readable_text;
   }
}

int is_readable(void) {
   return 1;
}

int can_read(object who) {
   return 1;
}

int do_read(object who) {
   string msg;

   msg = query_message();

   if (msg[0] == '#') {
      msg = call_other(this_object(), msg[1..]);
   }
   write(msg);
   return 1;
}
