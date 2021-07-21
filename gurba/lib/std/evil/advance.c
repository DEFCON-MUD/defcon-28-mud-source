int do_advance(string arg) {
  int plvl;
  object player, token;
  player = this_player();
  plvl = player->query_level();

  if (!player->ready_for_next_level()) {
    write("You don't have enough experience to advance yet...");
    return 1;
  }

  if ((plvl < 20)) {
    player->increase_level();
    player->initialize_stat_dependant_variables();
    return 1;
  }

  
  write("You have hit the level cap...\n");
  return 1;
}

int do_quest(string arg) {
  object player;
  string flag, TICKET;
  int key_count;
  int *key_tracker; /* tracks 8 keys from quest */

  TICKET = FLAG_D->query_flag("TICKET");
  flag = TICKET;
  player = this_player();
  key_tracker = player->get_key_tracker();
  if (!key_tracker) {
    key_tracker = (( { 0, 0, 0, 0, 0, 0, 0, 0 } ));
  }
  key_count = key_tracker[0] + key_tracker[1] + key_tracker[2] + key_tracker[3] + key_tracker[4] + key_tracker[5] + key_tracker[6] + key_tracker[7];
  write("keycount: " + key_count);
  if (key_count == 8) {
    if (!player->is_completed_quest("Ticket") == 1) {
      write("Congrats you completed the ticket quest.\n");
      write(flag +"\n");
      player->add_completed_quest("Ticket");
      CHANNEL_D->chan_send_string("announce", "", player->query_name() +" has completed the ticket quest", 1);
    } else {
      write("Congrats you completed the ticket quest.\n");
      write(flag +"\n");
    }
    return 1;
  } else {
    write("You do not have all the keys, in order to complete the quest\nyou must find all of the keys:\n\n");
    if(key_tracker[0] != 1) {
      write("\tKey 1 - City\n");
    }
    if(key_tracker[1] != 1) {
      write("\tKey 2 - North\n");
    }
    if(key_tracker[2] != 1) {
      write("\tKey 3 - East\n");
    }
    if(key_tracker[3] != 1) {
      write("\tKey 4 - Prison\n");
    }
    if(key_tracker[4] != 1) {
      write("\tKey 5 - Nympho\n");
    }
    if(key_tracker[5] != 1) {
      write("\tKey 6 - City\n");
    }
    if(key_tracker[6] != 1) {
      write("\tKey 7 - Dungeon\n");
    }
    if(key_tracker[7] != 1) {
      write("\tKey 8 - Dungeon\n\n");
    }

    write("\n\n");

    return 1;
  }

  return 0;
}

int do_quests(mixed args) {
  object player;

  player = this_player();
  if (args == "") {
    write("-----------------------------------------------------------------\n");
    write("| %^GREEN%^Active Quests%^RESET%^                                                 |\n");
    write("-----------------------------------------------------------------\n");
    if(!player->is_completed_quest("NewbieVille")) {
      write("| %^MAGENTA%^Newbie%^RESET%^       - North From Start\n");
    }
    if(!player->is_completed_quest("Pottles")) {
      write("| %^MAGENTA%^Pottles%^RESET%^      - Find Pottles in the Sewer\n");
    }
    if(!player->is_completed_quest("Wizard")) {
      write("| %^MAGENTA%^Wizard%^RESET%^       - Find the wizard potion in the dungeon deep below the sewer\n");
    }
    if(!player->is_completed_quest("Sewer")) {
      write("| %^MAGENTA%^Sewer%^RESET%^        - Find and slay the sewer monster\n");
    }
    if(!player->is_completed_quest("Ticket")) {
      write("| %^MAGENTA%^Ticket%^RESET%^       - Go to the advancement room and find the tokens\n");
    }
    if(!player->is_completed_quest("Parrot")) {
      write("| %^MAGENTA%^Parrot%^RESET%^       - Find the mean parrot in the sewer beneath the labyrinth\n");
    }
    if(!player->is_completed_quest("Evil")) {
      write("| %^MAGENTA%^Evil%^RESET%^         - Find kendall and ask him about rats\n");
    }
    if(!player->is_completed_quest("Woodland")) {
      write("| %^MAGENTA%^Woodland%^RESET%^     - Kill all the creature types in woodland");
    }
    write("-----------------------------------------------------------------\n");
  }
  return 1;
}

int do_recast(string arg) {
  object obj;
  obj = this_player();
  if(arg == "confirm") {
    this_player()->initialize_stats();
    write("%^REVERSE%^You have been regenerated...%^RESET%^\n\n");
     write("Strength:" + obj->query_stat("str"));
     write("Intelligence: " + obj->query_stat("int"));
     write("Wisdom: " + obj->query_stat("wis"));
     write("Dexterity: " + obj->query_stat("dex"));
     write("Constitution: " + obj->query_stat("con"));
     write("Charisma: " + obj->query_stat("cha"));
     write( "\n");
    this_player()->increment_death();
    return 1;
  }

  write("Please type %^GREEN%^recast confirm%^RESET%^ to confirm your intention to regenerate. This will re-roll your stats. Also you will lose a life.");
  return 1;

}

string do_hrsign(void) {
  string desc;
  desc = "%^HMAGENTA%^advance %^RESET%^- Graduate to the next level\n";
  desc += "%^HGREEN%^quests %^RESET%^- View a list of quests\n";
  desc += "%^HBLUE%^claim %^RESET%^- Claim your destiny\n";
  desc += "%^YELLOW%^recast %^RESET%^- Re-Roll your stats\n";
  return desc;
}
