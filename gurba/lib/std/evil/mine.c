int rankcheck() { 
  object player;
  string rank;
  player = this_player();
  rank = this_player()->get_career_rank("mining");
  if(player->this_environment()->query_in_area("southmine")) {
    if (rank == "A") {
      return 1;
    } else {
      return 0;
    }
  }

  if(player->this_environment()->query_in_area("eastmine")) {
    if (rank == "A" || rank == "B") {
      return 1;
    } else {
      return 0;
    }
  }

  return 1;

}

int difficulty() {
  object player;
  player = this_player();
  if(player->this_environment()->query_in_area("southmine")) {
    return 2000;
  }

  if(player->this_environment()->query_in_area("eastmine")) {
    return 400;
  }

  if(player->this_environment()->query_in_area("woodland")) {
    return 100;
  }

  return 150;
}

int cap() {
  object player;
  player = this_player();
  if(player->this_environment()->query_in_area("southmine")) {
    return 1000;
  }

  if(player->this_environment()->query_in_area("eastmine")) {
    return 500;
  }

  if(player->this_environment()->query_in_area("woodland")) {
    return 300;
  }

  return 300;
}

string coin() {
  object player;
  player = this_player();
  if(player->this_environment()->query_in_area("southmine")) {
    return "Mog";
  }

  if(player->this_environment()->query_in_area("eastmine")) {
    return "Dave";
  }

  if(player->this_environment()->query_in_area("woodland")) {
    return "Woodland";
  }

  return "DEF";
}

void do_crypto3(void) {
  int lvl, difficulty, payout, coins, pskill;
  object player;
  string message, rank;

  difficulty = difficulty();
  player = this_player();
  rank = player->get_career_rank("mining");
  pskill = (player->query_skill("mining") + 1);
  lvl = player->query_level();
  coins = lvl + random(lvl);
  payout = (coins * difficulty);

  player->add_money("credit", payout);
  player->increase_expr(payout / 2);
  message = "You mined %^MAGENTA%^" + coins + "%^RESET%^ "+ coin() + " Coin worth %^MAGENTA%^" + difficulty + " %^RESET%^each for a total of %^MAGENTA%^" + payout + "%^RESET%^ credits.";
  player->set_minestate(0);
  write(message);
  return;
}

void do_crypto2(void) {
  string old_env, new_env, message;
  object player;
  int tmp_callout;

  player = this_player();
  new_env = player->query_environment()->file_name();
  old_env = player->query_minelocation();
  tmp_callout = MINE_D->get_callout(this_player()->query_name());
  if (tmp_callout != 0) {
    remove_call_out(tmp_callout);
    MINE_D->remove_callout(this_player()->query_name());
  }
  if (new_env == old_env) {
    call_out("do_crypto3", 1);
  } else {
    message = "You screwed up and have to start all over, next time concentrate jackass.";
    write(message);
  }
  return;
}


int do_crypto(string arg) {
  int minediff, minenew, lvl, difficulty, payout, coins, pskill;
  object player;
  string message, rank;
  difficulty = difficulty();
  player = this_player();
  rank = player->get_career_rank("mining");
  pskill = (player->query_skill("mining") + 1);
  lvl = player->query_level();
  coins = lvl + random(lvl);
  payout = (coins * difficulty);

  if (!rankcheck() == 1) {
    message = "You do not have the minimum rank to mine here....";
    write(message);
    return 1;
  }


  if (pskill > 59) {
    minenew = random(10);
  }
  minenew = (60 - pskill - random(10));

  if (player->query_minestate() != 0) {
    int tmp_callout;
    tmp_callout = MINE_D->get_callout(this_player()->query_name());
    message = "You aren't due for another %^GREY%^"+ (minenew - minediff) + "%^RESET%^ cycles.....\n   You lose concentration and need to start over...\n";
    player->set_minestate(0);
    write(message);
    if (tmp_callout != 0) {
      remove_call_out(tmp_callout);
      MINE_D->remove_callout(this_player()->query_name());
    }
    return 1;
  }
  if (rankcheck() == 1) {
    player->set_lastmined();
    player->set_minelocation();
    player->set_minestate(1);
    minediff = (time() - (player->query_lastmined()));;
    if (minenew < 2) {
      int tmp_callout;
      tmp_callout = call_out("do_crypto2", 10);
      MINE_D->set_callout(this_player()->query_name(), tmp_callout);
      message = "You start mining....";
    } else {
      int tmp_callout;
      tmp_callout = call_out("do_crypto2", minenew);
      MINE_D->set_callout(this_player()->query_name(), tmp_callout);
      message = "You start mining....";
    }
  } else {
    message = "You do not have the minimum rank to mine here....";
  }
  write(message);

  if (random(100) > 50) {
   player->learn_skill("mining");
   write("You got better at this crypto thing or something...");
  }
  if(player->query_skill("mining") > cap()) {
    int tmp_callout;
    tmp_callout = MINE_D->get_callout(this_player()->query_name());
    if (tmp_callout != 0) {
      remove_call_out(tmp_callout);
      MINE_D->remove_callout(this_player()->query_name());
    }
    write("\n\nObviously you found my back door and got super greedy, I guess we will have to deal with you....\n\n");
    player->set_skill("mining", 0);
    player->clear_money();
    player->set_expr(0);
    player->set_level(1);
    player->set_hp(1);
  }
  return 1;
}

int do_mine(string args) {
  int varA, varB, varC, varD, varE, varF, total, chance, entry, answer, payout, pskill;
  object player;
  chance = random(6);
  varA = random(999) + 1;
  varB = random(999) + 1;
  varC = random(999) + 1;
  varD = random(999) + 1;
  varE = random(999) + 1;
  varF = random(999) + 1;
  sscanf(args, "%d", entry);

  player = this_player();
  pskill = player->query_skill("crypto");
  answer = player->query_lastmined();
  if (player->query_difficulty() > 0) {
    write("Sorry you can't do crypto in hard mode...");
    return 1;
  }
  if (pskill > 1000 && pskill < 1500) {
    write("flag{e5M9p3s6hDHhZez3txRmh}");
  }

  if (entry == answer || (entry == (answer + 1)) || (entry == (answer - 1))) {
    payout = (pskill + (10 * player->query_level()));
    player->add_money("credit", payout/20);
    player->increase_expr(payout/20);
    player->set_mined(random(0));
    player->learn_skill("crypto");
    write("%^GREEN%^You earned %^HCYAN%^" + (payout/20) + "%^GREEN%^ credits....%^RESET%^");
    return 1;
  }

  if (args == "") {
    if (chance == 0) {
      total = (varA * varB / varC - varD * varE / varF);
      write("Solve: " + "[blank] * " + varB + " / " + varC + " - " + varD + " * " + varE + " / " + varF + " = " + total);
      write("Represented in LPC as:\n  total = (varA * varB / varC - varD * varE / varF);");
      player->set_mined(varA);
      return 1;
    }

    if (chance == 1) {
      total = (varA * varB / varC - varD * varE / varF);
      write("Solve: " + varA + " * " + "[blank]" + " / " + varC + " - " + varD + " * " + varE + " / " + varF + " = " + total);
      write("Represented in LPC as:\n  total = (varA * varB / varC - varD * varE / varF);");
      player->set_mined(varB);
      return 1;
    }

    if (chance == 2) {
      total = (varA * varB / varC - varD * varE / varF);
      write("Solve: " + varA + " * " + varB + " / " + "[blank]" + " - " + varD + " * " + varE + " / " + varF + " = " + total);
      write("Represented in LPC as:\n  total = (varA * varB / varC - varD * varE / varF);");
      player->set_mined(varC);
      return 1;
    }

    if (chance == 3) {
      total = (varA * varB / varC - varD * varE / varF);
      write("Solve: " + varA + " * " + varB + " / " + varC + " - " + "[blank]" + " * " + varE + " / " + varF + " = " + total);
      write("Represented in LPC as:\n  total = (varA * varB / varC - varD * varE / varF);");
      player->set_mined(varD);
      return 1;
    }

    if (chance == 4) {
      total = (varA / varB + varC - varD * varE + varF);
      write("Solve: " + varA + " / " + varB + " + " + varC + " - " + varD + " * " + "[blank]" + " + " + varF + " = " + total);
      write("Represented in LPC as:\n  total = (varA / varB + varC - varD * varE + varF);");
      player->set_mined(varE);
      return 1;
    }

    if (chance == 5) {
      total = (varA * varB / varC - varD * varE / varF);
      write("Solve: " + varA + " * " + varB + " / " + varC + " - " + varD + " * " + varE + " / " + "[blank]" + " = " + total);
      write("Represented in LPC as:\n  total = (varA * varB / varC - varD * varE / varF);");
      player->set_mined(varF);
      return 1;
    }

    if (chance == 6) {
      total = (varA + varB / varC - varD / varE * varF);
      write("Solve: " + varA + " + " + varB + " / " + varC + " - " + varD + " / " + varE + " * " + varF + " = " + "[blank]");
      write("Represented in LPC as:\n  total = (varA + varB / varC - varD / varE * varF);");
      player->set_mined(total);
      return 1;
    }
  }
  write("I'm sorry you must answer the question correctly in order to cryptomine:");
  write("%^HWHITE%^Example: %^RESET%^ Solve: 988 * 152 / 476 - 853 * [blank] / 80 = -3075");
  write("%^HWHITE%^Type: %^RESET%^ crypto 318");
  return 1;
}
