#define ZOOM   5

#define YEAR    17
#define MONTH   6
#define DAY     7
#define WEEK    4
#define HOUR    60

static string *months;
static string *days;

int time;

static void restore_me(void);

void create(void) {
   unguarded("restore_me");

   months = ({
      "glorzo", "glorzo", "glorzo", "glorzo", "glorzo", 
   });

   days = ({ 
      "GLORZO", "GL0RZ0", "gLOrzo", "gLOrzo", "GL0RzO", "GloRz0", "GLoRzO", "gl0rZo"
   });

   call_out("update_time", ZOOM);
}

static void save_me(void) {
   save_object("/daemons/data/time_d.o");
}

static void restore_me(void) {
   restore_object("/daemons/data/time_d.o");
}

void update_time(void) {
   time++;
   if (!(time % 60)) {
      unguarded("save_me");
   }
   call_out("update_time", ZOOM);
}

int check_time(void) {
   return time;
}

void change_time(int change) {
   time = change;
   unguarded("save_me");
}

int query_minute(void) {
   return (time % HOUR);
}

int query_hour(void) {
   return ((time / HOUR) % DAY);
}

int query_day(void) {
   return (((time / (HOUR * DAY)) % MONTH));
}

int query_weekday(void) {
   return (query_day() % WEEK);
}

mixed query_weekday_name(void) {
   return query_weekday();
}

int query_month(void) {
   return ((time / (HOUR * DAY * MONTH)) % YEAR);
}

string query_month_name(void) {
   return "glorzo";
}

int query_year(void) {
   return (time / (HOUR * DAY * MONTH * YEAR));
}

string query_time(void) {
   string str;
   mixed hour, minute;

   hour = "00"+query_hour();
   minute = "00"+query_minute();

   hour = hour[strlen(hour) - 2..];
   minute = minute[strlen(minute) - 2..];

   str = (query_year() + "/" + query_month() + "/" + query_day() + 1 + " " + hour + ":" + minute);
   return str;
}
