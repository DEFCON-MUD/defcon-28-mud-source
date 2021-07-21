void restore_me(void);
void save_me(void);
#define DATAFILE "/sys/daemons/data/flag_d.o"

mapping flags;
mapping flags_hard;

void create(void) {

   flags =([ ]);
   flags_hard = ([ ]);

      /* Create a default list if we do not already have one. */
    flags["MEDIOCREALIGATOR"] = "flag{xd9qzxjwmb27vykb74}";
    flags["MEDIOCRELIZARD"] = "flag{pa4gjqre3dm594ui2s}";
    flags["MEHFERRET"] = "flag{edtz6a79ywp9cjn6q9}";
    flags["MEHRAT"] = "flag{imgrc2grd9tra9ha4h}";
    flags["PARROT"] = "flag{jpg9pjifq28cifah8z}";
    flags["POTTLES"] = "flag{m3phjieajn6akzaxki}";
    flags["SEWERBOSS"] = "flag{vht8m3jr8btvk6afnk}";
    flags["TICKET"] = "flag{d2nyqrsacfq9jh235e}";
    flags["UNINITIATEDEEL"] = "flag{78emrnhkufkb3h8gcm}";
    flags["UNINITIATEDSNAKE"] = "flag{ha9qfc6z7gdstzdtqh}";
    flags["WIZARDPOTION"] = "flag{sa5sh54tqf36d4z2tn}";
    flags["EVIL"] = "flag{ax6mqav47825jpwz4x}";
    flags["WOODLAND"] = "flag{uyswkp9yivxhf6ubes}";

    flags_hard["MEDIOCREALIGATOR"] = "flag{8PAmtrxkhgFKEiMaVGZ}";
    flags_hard["MEDIOCRELIZARD"] = "flag{yAPBhdT5EWiEuRh6zxy}";
    flags_hard["MEHFERRET"] = "flag{PU3zV39Yb2PJqH6Yu3J}";
    flags_hard["MEHRAT"] = "flag{7CXwbxGXUi4NBZNCgXS}";
    flags_hard["PARROT"] = "flag{2G3Dms4tTVs8WvXPrhG}";
    flags_hard["POTTLES"] = "flag{Fpikjc9AbwFyaqtF9Ca}";
    flags_hard["SEWERBOSS"] = "flag{NQFxLwVYpcgpjt3cFAR}";
    flags_hard["TICKET"] = "flag{vzD7UN6DFqLMkSnkpEM}";
    flags_hard["UNINITIATEDEEL"] = "flag{FjeQcnEtg6qA9r7yw6c}";
    flags_hard["UNINITIATEDSNAKE"] = "flag{HWNfLesznrdZ4TgACWj}";
    flags_hard["WIZARDPOTION"] = "flag{Jnac4QDaBJbkDZC4iwR}";
    flags_hard["EVIL"] = "flag{qa3LPDwcCeyp4bYZViX}";
    flags_hard["WOODLAND"] = "flag{jXMuZ3p8q9HMN2SH6me}";

   
    save_me();
}
 
static void restore_me(void) {
   unguarded("restore_object", DATAFILE);

}

static void save_me(void) {
   unguarded("save_object", DATAFILE);
}

void set_flag(string flag, string str) {
  flags[flag] = str;
  save_me();
}

void set_flag_hard(string flag, string str) {
  flags_hard[flag] = str;
  save_me();
}

string query_flag(string str) {
   object player;
   string flag;
   player = this_player();
   if (player->cheater() == 1){
     flag = "flag{invalid}";
   } else if (this_player()->query_difficulty() > 0) {
    flag = flags_hard[str];
   } else {
     flag = flags[str];
   }
   return flag;
}


int is_flag(string flag) {
   if (flags[flag]) {
      return 1;
   } else if (flags_hard[flag]) {
      return 2;
   }

   return 0;
}

void remove_flags(string flag) {
   flags[flag] = nil;
   save_me();
}

void remove_flags_hard(string flag) {
   flags_hard[flag] = nil;
   save_me();
}

string *query_flags(void) {
   return map_indices(flags);
}

string *query_flags_hard(void) {
   return map_indices(flags_hard);
}

