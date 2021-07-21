int do_immune(string arg) {
  object player;
  int plvl, pcost, pcredits, gcost;
  string message;

  player = this_player();
  plvl = player->query_level();
  gcost = 4000;
  pcost = (plvl * gcost);
  pcredits = player->query_total_money();
  if (player->query_deathproof() == 1) {
    write("You are already deathproof.");
    return 1;
  }
  if ((pcredits > pcost) || (pcredits == pcost)) {
    player->add_money("credit", -pcost);
    player->set_deathproof(1);
    write("You have been made %^BOLD%^%^RED%^deathproof%^RESET%^.");
    return 1;
  } else {
    write("You do not have enough credits");
    return 1;
  }
}

int do_list(string arg) {
  object player;
  int plvl, pcost, pcredits, gcost, tcost, lcost, curhp, maxhp, hpdiff, hcost, mxp;
  string message;

  player = this_player();
  mxp = player->query_mxp();
  plvl = player->query_level();
  curhp = player->query_hp();
  maxhp = player->query_max_hp();
  hpdiff = maxhp - curhp;
  gcost = 4000;
  lcost = 1000;
  hcost = hpdiff * 10;
  pcost = (plvl * gcost);
  tcost = (plvl * lcost);
  write("-----------------------------------------------------------------\n");
  write("| Evil Mogs %^GREEN%^S%^HGREEN%^k%^MAGENTA%^e%^YELLOW%^t%^GREY%^c%^HMAGENTA%^h%^ORANGE%^y %^HBLUE%^C%^HRED%^l%^RED%^i%^CYAN%^n%^HCYAN%^i%^HWHITE%^c %^RESET%^Services				|\n");
  write("-----------------------------------------------------------------\n");
  if (mxp != 1) {
    write("| %^MAGENTA%^immune%^RESET%^ Grants Immunity to Death Penalties\t%^GREEN%^" + pcost + "%^RESET%^\n");
    write("| %^MAGENTA%^heal%^RESET%^   Heals you to max health\t\t%^GREEN%^" + hcost  + "%^RESET%^\n");
  } else {
     write("| %^MXP_LSM%^%^MAGENTA%^<send href=\"immune\">immune</send>%^MXP_LLM%^%^RESET%^ Grants Immunity to Death Penalties %^GREEN%^\t" + pcost + "%^MXP_LLM%^%^RESET%^\n");
     write("| %^MXP_LSM%^%^MAGENTA%^<send href=\"heal\">heal</send>%^RESET%^   Heals you to max health\t\t%^GREEN%^" + hcost  + "%^MXP_LLM%^%^RESET%^\n");
  }
  write("-----------------------------------------------------------------\n");
  return 1;
}

int do_heal(string arg) {
  object player;
  int maxhp, curhp, pcost, pcredits, hpdiff;
  string message;

  player = this_player();
  curhp = player->query_hp();
  maxhp = player->query_max_hp();
  hpdiff = maxhp - curhp;
  pcost = hpdiff * 10;
  pcredits = player->query_total_money();
  if ((pcredits > pcost) || (pcredits == pcost)) {
    player->add_money("credit", -pcost);
    player->set_hp(maxhp);
    write("%^GREEN%^You have been healed.%^RESET%^");
    return 1;
  } else {
    write("%^RED%^You do not have enough credits.%^RESET%^");
    return 1;
  }
}
