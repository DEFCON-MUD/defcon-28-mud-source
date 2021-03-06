/* 
Gurbalib uses an include file for some local configurable
options. You'll have to #define things in here to override
the defaults.

When an option is not defined in this file, the default for that option 
will be used.

You should at least modify the first 3 entries. 
*/

/* What you want your mud to be called (avoid spaces) */
#define MUD_NAME  "DEFCON MUD"

/* Name for your mud on Intermud (avoid spaces) */
#define IMUD_NAME "DEFCON MUD"

/* To define your email address: */
#define ADMIN_EMAIL             "EvilMog@somewhereclassified.com"

/* Website for the mud if you have one, if not comment this out */
/* #define WEBSITE "https://github.com/sirdude/gurbalib" */

/* To set the linkdeadth timeout in seconds (after this time, linkdead
	players will be disconnected) */
#define LINKDEAD_TIMEOUT        600

/* This defines where players start when they login: */
#define STARTING_ROOM           "/domains/required/rooms/start"

/* The void */
#define VOID "/domains/required/rooms/void"

/* The max stack depth */
#define MAX_DEPTH               512

/* This defines how many ticks can be used before an out of ticks
   error occurs. */
#define MAX_TICKS               2000000

/* When set to 0, the world will not be persistent, and clean_up and reset
   are used. If set to 1, clean_up and reset are not called  */
#define WORLD_PERSIST           0

/* enable state dumping of the  the world so that we can reload from
   a cold boot */
#define SYS_PERSIST	1

/* Enable ansi colors */
#define SYS_COLOR	1

/* The time between calls to event_clean_up, ignored if WORLD_PERSIST = 1*/
#define CLEAN_UP_INTERVAL       3600

/* The time between calls to event_reset, ignored if WORLD_PERSIST = 1 */
#define RESET_INTERVAL          5

/* The time between state dumps, ignored if SYS_PERSIST = 0  */
#define DUMP_INTERVAL           3600

/* Number of micro_beats per second.  The larger this number the shorter the
   length of time between each micro_beat.  Larger numbers here can have a
   negative impact on performance and affect accuracy of time approximations,
   such as second, minute etc. */
#define MICROS_PER_SECOND  5

/* The time, in seconds, between heart beats */
#define HEART_BEAT_INTERVAL     2

/* If the following is defined, all FTP functionality will be disabled */
#define DISABLE_FTP 1

/* If the following is defined, anonymous FTP will be disabled */
#define DISABLE_ANON_FTP 1

/* If the following is defined, the INTERMUD Daemon will not be started */
#define DISABLE_IMUD 0

/* If the following is defined, room descriptions will show each object
   individually instead of collating objects with identical short descs.
*/
#define LONG_ROOM_INV 1

/* Default terminal width */
#define DEFAULT_WIDTH           80

/* Location of wizards directory */
#define WIZ_DIR "/wiz"

/* Location of the races */
#define RACE_DIR "/domains/required/objects/races"

/* Location for addon domains */
#define DOMAINS_DIR "/domains"

/* privileges in this list will always be matched */
#define SECURITY_NO_CHECK  ({ "*", "nobody" })

/* privileges in this list will never be matched */
#define SECURITY_NO_ACCESS ({ "-", "?" })

#define SYS_BANNED_NAMES ({ "kernel", "system", "wizard", "network", "game", "nobody", "defcon", "admin", "root" })

/* Define this to automatically promote users to a wizard when they 
	create an account */
/* #define ALL_USERS_WIZ 1 */

/* Mud Server Status Protocol variables, see sys/lib/user.c for where this
	is used */
#define MSSP_FAMILY "LPMud"
#define MSSP_STATUS "LIVE" /* "ALPHA", "CLOSED BETA", "OPEN BETA", "LIVE" */
#define MSSP_INTERMUD "I3"
#define MSSP_ANSI "1"
#define MSSP_MCCP "0"
#define MSSP_PAY_TO_PLAY "0"
#define MSSP_PAY_FOR_PERKS "1"

/* DEBUGGING OPTIONS: Enable these to debug various issues  You probably do
   not want to do this in a live mud */
#define DEBUG_PARSE 0
#define DEBUG_BOOT 0
/* #define DEBUG_RECOMPILE 1 */
/* #define DEBUG_COMPILER_D 1 */
/* #define DEBUG_CONNECTION 1 */
/* #define DEBUG_PRIVS 1 */
/* uncomment the line below to get a lot of debug output.. */
/* #define DEBUG_STACK_SECURITY 1 */
/* uncomment the line below to get even more debug output.. */
/* #define DEBUG_STACK_SECURITY_DEEP 1 */
#define DO_STATS 1
