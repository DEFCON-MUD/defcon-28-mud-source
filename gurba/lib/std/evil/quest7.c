#include "/domains/core/domain.h"
inherit "/std/menu";

#define TO this_object()

static string do_fmenu(void);
static int menu_action_quit(void);


int do_flag15(string arg) {
  if (this_player()->query_q7_tracker() == 15) {
    write("It appears as if the company has been up to some very bad things...find old tom the miner and ask him about evidence.");
    return 1;
  } else {
    write("I'm Sorry you don't have access to that");
    return 1;
  }
}

int do_respawn(string arg) {
  if (arg == "button") {
    this_environment()->setup();
    this_player()->do_look(this_environment());
    return 1;
  } else {
    return 0;
  }
}

int do_sandworm(void) {
 object player, sandworm;
 int q7track;

 player = this_player();
 q7track = player->query_q7_tracker();
 if (q7track == 63) {
   sandworm = clone_object(DIR+"/monsters/sandworm.c");
   sandworm->setup();
   sandworm->move(this_player()->query_environment());
   sandworm->attack(player);
   return 1;
 } else {
   return 0;
 }
}


int do_wallet(void) {
  int q7tracker;
  object player, wallet, pwallet;
  player = this_player();
  q7tracker = player->query_q7_tracker();
  pwallet = player->present("wallet");
  if (q7tracker == 3) {
    if (!pwallet) {
      write("you found a wallet");
      wallet = clone_object(DIR+"/objects/wallet.c");
      if (wallet) {
        wallet->move(player);
        wallet->setup();
        return 1;
      }
    }
  }
  return 0;
}

int do_airlock(string arg) {
  object player, obj, *inv;
  string pname;
  int q7track, i;

  player = this_player();
  pname = player->query_name();
  q7track = player->query_q7_tracker();

  if (q7track == 128) {
    if (arg == "airlock") {
        player->set_deathproof(0);
        write("%^YELLOW%^EvilMogs Agent %^MAGENTA%^tells you: your chose poorly......%^RESET%^");
        player->set_q7_tracker(255);
        write("%^YELLOW%^EvilMogs Agent %^MAGENTA%^tells you: your body will never be found...%^RESET%^");
        write("%^YELLOW%^EvilMogs Agent %^MAGENTA%^tells you: we aren't monsters however....the sketchy doctor can fix you up.%^RESET%^");
        write("%^YELLOW%^EvilMogs Agent %^MAGENTA%^tells you: next time you will choose wisely....%^RESET%^");
         player->move("/domains/core/rooms/city/x-50y-80z0-dead.c");
         player->die();
         player->move("/domains/core/rooms/city/x-10y-40z0.c");
         CHANNEL_D->chan_send_string("announce", "", pname +" was assisted out the airlock", 1);
         write("Your flag is " + FLAG_D->query_flag("EVIL") + "\n");
         this_player()->add_completed_quest("Evil");
         this_player()->set_q7_tracker(255);
         CHANNEL_D->chan_send_string("announce", "", this_player()->query_name() +" has completed the evil quest", 1);
         return 1;
    } else {
      write("If you really want you can '%^RED%^leave airlock%^RESET%^'");
      return 1;
    }
  }

  if (arg == "airlock") {
    write("As you exit the airlock your body begins to disolve...Everything goes black and the last thing you can remember is screaming in pain as your body is eaten away by the acid rain.");
         player->move("/domains/core/rooms/city/x-50y-80z0-dead.c");
         player->die();
         player->move("/domains/core/rooms/city/x-10y-40z0.c");
         player->set_dead(0);
         player->set_level(1);
         player->set_expr(0);
         CHANNEL_D->chan_send_string("announce", "", pname +" was assisted out the airlock", 1);

    if (player->query_deathproof() == 1) {
      player->set_deathproof(0);
      write("%^RED%^I'm sorry your body could not be recovered, you are no longer deathproof....");
    }
    return 1;
  } else {
    write("If you really want you can '%^RED%^leave airlock%^RESET%^'");
    return 1;
  }
}

static int menu_action_quit(void) {
   write("Ok.");
   return 1;
}

static string do_fmenu(void) {
  mixed *menu;
  int q7track;
  object player;
  player = this_player();
  q7track = player->query_q7_tracker();
  menu = ( { } );
   if (q7track == 7) {
     menu += ({
      ({
         "1", "Access Control", nil, make_fcall(TO, "menu_action_1")
      })
     });
   }
   if (q7track == 31) {
     menu += ({
      ({
         "1", "Bribery", nil, make_fcall(TO, "menu_action_2")
      })
     });
   }
   if (q7track == 63) {
     menu += ({
      ({
         "1", "Greed", nil, make_fcall(TO, "menu_action_3")
      })
     });
   }
   if (q7track == 127) {
     menu += ({
      ({
         "1", "Details", nil, make_fcall(TO, "menu_action_4")
      })
     });
   }
   menu += ({
      ({
         "q", "quit menu", nil, make_fcall(TO, "menu_action_quit")
      })
   });

   do_menu("Company Access:", menu);
   return " ";
}

int do_touch(string arg) {
   if (arg == "padd") {
      do_fmenu();
      return 1;
   } else {
      return 0;
   } 
}

int menu_action_1(void) {
  write("You company access card has had its access upgraded...you may now access Grey's computer");
  this_player()->set_q7_tracker(15);
  return 1;
}

int menu_action_2(void) {
  write("It appears as if evilmog controls everything...\n");
  write("His agent can be found in the zombie bar....\n");
  return 1;
}

int menu_action_3(void) {
  write("The access code can be found in the sandworm pits.....");
  return 1;
}

int menu_action_4(void) {
   write("Ok so here's the deal most of the company is on the take, and the company is wholy owned by the church of wifi....\n");
   write("You have a choice, you can either go with the flow and work for the church or you can exit the airlock and find another colony...\n");
   write("To make this choice you must use the access code of good or evil.");
   return 1;
}

int do_access(string arg) {
   if (arg == "good") {
     if (this_player()->query_q7_tracker() == 127) {
       write("Ok so you chose good....Please escort yourself to the airlock");
       this_player()->set_q7_tracker(128);
       return 1;
     } else {
       write("The access code is incorrect....");
       return 1;
     }
   }
  if (arg == "evil") {
     if (this_player()->query_q7_tracker() == 127) {
         write("%^YELLOW%^EvilMogs Agent %^MAGENTA%^tells you: your chose wisely......\n%^RESET%^");
         this_player()->set_q7_tracker(255);
         write("Your flag is " + FLAG_D->query_flag("EVIL") + "\n");
         this_player()->add_completed_quest("Evil");
         this_player()->set_q7_tracker(255);
         CHANNEL_D->chan_send_string("announce", "", this_player()->query_name() +" has completed the evil quest", 1);
         return 1;
     } else {
         write("The access code is incorrect....");
         return 1;
     }
   }
  write("The access code is incorrect, try %^MAGENTA%^access%^GREEN%^ code%^RESET%^ where code is an access code issued to you....");
  return 1;
}

