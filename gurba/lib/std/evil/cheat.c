inherit "/std/room";
inherit "/std/menu";

static string do_fmenu(void);

int do_activate(string arg) {
  /* Give cryptic response */
  write("AUTH SEQ REJ\n");
  return 1;
}

int do_1000(string args) {
  object obj, player;
  player = this_player();
  CHANNEL_D->chan_send_string("announce", "", player->query_name() +" has received the sword of 1000 truths from the church", 1);
  obj = clone_object("/domains/core/objects/1000.c");
  if (obj) {
    obj->move(player);
    obj->setup();
  }
  return 1;
}

int do_automap(string args) {
  VNUM_D->reset_me();
  return 1;
}

int do_sword_menu(mixed arg) {
   object obj, player;
   int sword, pcredits, gcost, scost;
   scost = 1000;
   player=this_player();
   if (!arg) { 
      player->write("What damage do you want your sword to have?: ");
      player->input_to_object(this_object(), "do_sword_menu");
      return 1;
   }
   if (arg) {
      sscanf(arg, "%d", sword);
      pcredits = player->query_total_money();
      gcost = sword * scost;
      if (pcredits > gcost) {
        player->add_money("credit", -gcost);
        write("Thank you, that will be " + gcost + " credits.");
        write("Enjoy your shiny new sword.\n");
        obj = clone_object("/domains/core/objects/sword_template.c");
        obj->setup();
        obj->set_max_damage(sword);
        obj->set_long("A custom sword with a damage of: " + sword);
        obj->move(player);
      } else {
        write("Sorry you do not have enough credits, that will cost: " + gcost + "\n");
      }
     do_fmenu();
   }
  return 0;
}


static int menu_action_quit(void) {
   write("Ok.");
   return 1;
}

static string do_fmenu(void) {
  mixed *menu;
  object player;
  player = this_player();
  menu = ( { } );

  if (player->query_cheat() < 1) {
    write("Evil.Mog.Authenticate EvilMog glorzo");
  } else {
    player->taint();
  }

  if (player->query_cheat() > 0) {
   menu += ({
      ({
         "1", "level 5", nil, make_fcall(this_object(), "do_lvl5")
      })
   });
  }

  if (player->query_cheat() > 0) {
   menu += ({
      ({
         "2", "level 10", nil, make_fcall(this_object(), "do_lvl10")
      })
   });
  }

  if (player->query_cheat() > 0) {
   menu += ({
      ({
         "3", "level 15",  nil, make_fcall(this_object(), "do_lvl15")
      })
   });
  }

  if (player->query_cheat() > 0) {
   menu += ({
      ({
         "4", "level 20", nil, make_fcall(this_object(), "do_lvl20")
      })
   });
  }

  if (player->query_cheat() > 0) {
   menu += ({
      ({
         "5", "deathproof", "Status: " + player->query_deathproof(), make_fcall(this_object(), "do_immune")
      })
   });
  }

  if (player->query_cheat() > 0) {
  menu += ({
      ({
         "6", "Sword", "1000 credits * damage", make_fcall(this_object(), "do_sword_menu", nil)
      })
   });
  }

  if ((player->query_cheat() > 0) || (player->query_difficulty() > 0)) {
  menu += ({
      ({
         "7", "Sword of 1000 truths", nil, make_fcall(this_object(), "do_1000", nil)
      })
   });
  }

   menu += ({
      ({
         "q", "quit menu", nil, make_fcall(this_object(), "menu_action_quit")
      })
   });

   do_menu("Sketchy Services:", menu);
   return " ";
}

int do_lvl5(void) {
 /* Just random stuff */
  object player;
  player = this_player();
  player->set_level(5);
  write("%^GREEN%^Your level was reset to 5%^RESET%^");
  return 0;
}

int do_lvl10(void) {
 /* Just random stuff */
  object player;
  player = this_player();
  player->set_level(10);
  write("%^GREEN%^Your level was reset to 10%^RESET%^\n");
  return 0;
}

int do_lvl15(void) {
 /* Just random stuff */
  object player;
  player = this_player();
  player->set_level(15);
  write("%^GREEN%^Your level was reset to 15%^RESET%^\n");
  return 0;
}

int do_lvl20(void) {
 /* Just random stuff */
  object player;
  player = this_player();
  player->set_level(20);
  write("%^GREEN%^Your level was reset to 20%^RESET%^\n");
  return 0;
}

int do_immune(void) {
  object player;
  player = this_player();
  if (player->query_deathproof() == 1) {
    write("%^RED%^You are no longer deathproof%^RESET%^.\n");
    player->set_deathproof(0);
    return 0;
  }
  if (player->query_deathproof() == 0) {
    write("%^GREEN%^You are now deathproof%^RESET%^.\n");
    player->set_deathproof(1);
    return 0;
  }
  return 0;
}
