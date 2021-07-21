inherit "/std/room";

void setup(void) {
   add_area("required");

   set_domainname("EvilMogs Funland");

   set_short("A large open field");
   set_long("You are in a large open field.  To the north you see a large " +
      "dead tree with some sort of sign on it. \n\n%^RED%^*%^YELLOW%^*%^RESET%^%^RED%^* %^HRED%^WARNING: %^RESET%^Permadeath is active in this game, you can buy death insurance. Right now the game is configured to drop you to level 1 on death.");
   add_action("fuck", "fuck");

   add_object( "/domains/dungeon/objects/sign.c", 9);
   set_exits(([
      "north" : "/domains/newbie/rooms/tree",
      "down" : "#do_core2"
   ]));
}

void fuck(void) {
  this_player()->increment_death();
  return 1;
}

void do_core3(void) {
    object player;
    player = this_player();
    player->set_start_room("/domains/core/rooms/city/x40y-90z0.c");
    player->move("/domains/core/rooms/city/x40y-90z0.c");
    player->do_look(player->query_environment());
    player->save_me();
    write("\n\nYou wakeup disoriented and confused.....\n\n");
}

void do_core2(void) {
    object player;
    player = this_player();
    write("%^EXT_89%^A %^EXT_125%^t%^EXT_161%^r%^EXT_197%^a%^EXT_198%^n%^EXT_199%^q %^EXT_200%^d%^EXT_201%^a%^EXT_165%^r%^EXT_129%^t %^EXT_93%^h%^EXT_57%^i%^EXT_21%^t%^EXT_27%^s %^EXT_33%^y%^EXT_39%^o%^EXT_51%^u%^EXT_50%^r %^EXT_49%^n%^EXT_48%^e%^EXT_47%^c%^EXT_46%^k %^EXT_82%^a%^EXT_118%^n%^EXT_154%^d %^EXT_190%^y%^EXT_226%^o%^EXT_220%^u %^EXT_214%^p%^EXT_202%^a%^EXT_203%^s%^EXT_204%^s %^EXT_205%^o%^EXT_206%^u%^EXT_207%^t%^EXT_171%^.%^EXT_135%^.%^EXT_63%^.%^EXT_27%^.%^EXT_26%^.%^EXT_25%^.%^RESET%^\n\n");
    player->move("/domains/required/rooms/transport");
    call_out("do_core3", 45);
}

void do_core(void) {
  object player;
  player = this_player();
  if (query_newbie(this_player()) == 0) {
    write("Congratulations you have passed new Agent training and have qualified " + 
      "for assignment to the Company mining colony, Hermes-571G system.\n\n");
    call_out("do_core2", 10);
  } else {
    write("I am sorry you must complete woodland and newbie in order to advance to core.");
  }
}


