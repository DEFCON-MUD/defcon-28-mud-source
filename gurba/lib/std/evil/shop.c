int do_order(string arg) {
  object player, obj;
  int lvl, plvl, pcredits, cost, pcost, mxp;
  string type;

  player = this_player();
  plvl = player->query_level();
  pcredits = player->query_total_money();
  pcost = 4000;
  mxp = player->query_mxp();

  if (plvl > 20) {
    plvl = 20;
  }
  if (plvl < 1) {
    plvl = 1;
  }
  if (!arg || arg == "") {
    write("%^ORANGE%^Welcome to the sketchy shop, you can order weapons and armour here. Weapons and armour are priced at a cost of %^HMAGENTA%^" + pcost + "%^ORANGE%^ credits per 'level', your level must be equal to or greater than the weapon or armour level to purchase.%^RESET%^");
    if (mxp == 1) {
      write("%^MXP_LSM%^<!EL Shop \'<send \"order &text; " + plvl + "\" prompt>\'>");
      write("%^CYAN%^orderable weapon types:\n%^RESET%^<Shop>sword</Shop>\n\n");
      write("%^CYAN%^orderable armour types:\n%^RESET%^<Shop>armour</Shop>\n<Shop>boots</Shop>\n<Shop>bracers</Shop>\n<Shop>faulds</Shop>\n<Shop>gloves</Shop>\n<Shop>gorget</Shop>\n<Shop>guantlets</Shop>\n<Shop>helmet</Shop>\n<Shop>plate</Shop>\n<Shop>ring</Shop>\n\n");
      write("%^HWHITE%^Syntax:%^MAGENTA%^ order %^GREEN%^type%^ORANGE%^ level%^RESET%^\n");
    } else {
      write("%^CYAN%^orderable weapon types:%^RESET%^ sword");
      write("%^CYAN%^orderable armour types:%^RESET%^ armour boots bracers faulds gloves gorget guantlets helmet plate ring");
      write("%^HWHITE%^Syntax:%^MAGENTA%^ order %^GREEN%^type%^ORANGE%^ level%^RESET%^\n");
    }
    return 1;
  }
  sscanf(arg, "%s %d", type, lvl);
  if (type == "" || lvl < 1) {
    return 0;
  }


  if (lvl > 20) {
    write("I'm sorry the maximum level you can order is 20");
    return 1;
  }
  cost = lvl * pcost;
  if (plvl < lvl) {
    write("You are not strong enough for that.....");
    return 1;
  }
  if (pcredits < cost) {
    write("You do not have enough credits for that.....");
    return 1;
  }
  if (file_exists("/domains/core/objects/shop/armour/" + type + lvl + ".c")) {
    if (player->query_race() == "fed") {
      if (lvl > 2) {
        write("I'm sorry the maximum armour you can purchase is 2 in hard mode");
        return 1;
      }
    }
    player->add_money("credit", -cost);
    obj = clone_object("/domains/core/objects/shop/armour/" + type + lvl + ".c");
    obj->setup();
    obj->move(player);
    write("You purchase a level " + lvl + " " + type + " for " + cost);
    return 1;
  } else if (file_exists("/domains/core/objects/shop/weapon/" + type + lvl + ".c")) {
    if (player->query_race() == "fed") {
      if (lvl > 2) {
        write("I'm sorry the maximum sword you can purchase is 2 in hard mode");
        return 1;
      }
    }
    player->add_money("credit", -cost);
    obj = clone_object("/domains/core/objects/shop/weapon/" + type + lvl + ".c");
    obj->setup();
    obj->move(player);
    write("You purchase a level " + lvl + " " + type + " for " + cost);
    return 1;
  } else {
    return 0;
  }
}
