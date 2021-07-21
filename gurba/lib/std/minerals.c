int do_sellminerals(string arg) {
   string *mineral_names;
   string str, tick, name;
   float amount, price;
   int player_money, total_money, total, player_minerals, maxi, i;
   object player;
   sscanf(arg, "%f %s", amount, tick);
   if (amount < 1.00) {
    return 0;
   }
   mineral_names = this_player()->query_minerals();
   maxi = sizeof(mineral_names);
   for (i = 0; i < maxi; i++) {
    name = mineral_names[i];
    if (name = tick) {
      price = STOCK_D->query_mineral_price(tick);
      total = ftoi(price * amount);
      player = this_player();
      player_minerals = this_player()->query_mineral_amount(tick);
      if (player_minerals >= ftoi(amount)) {
       player->add_money("credit", total);
       player->decrease_mineral_amount(tick, ftoi(amount));
       write("%^GREEN%^You have sold %^CYAN%^" + ftoi(amount) + " %^HWHITE%^%^BOLD%^" + tick + "%^GREEN%^ for %^CYAN%^" + total + "%^GREEN%^ credits%^RESET%^");
      } else {
        write("%^RED%^You don't have enough minerals for that!%^RESET%^");
      }
   } else {
        write("%^RED%^I'm sorry I can't find a ticker with that name, case matters\n%^GREEN%^Syntax: %^RESET%^redeem amount Mineral\n%^GREEN%^Example: %^RESET%^redeem 300 Aluminum");
   }
   return 1;
 }
}

int do_purchaseminerals(string arg) {
   string *mineral_names;
   string str, tick, name;
   float amount, price;
   int player_money, total_money, total, maxi, i;
   object player;
   sscanf(arg, "%f %s", amount, tick);
   if (amount < 1.00) {
    return 0;
   }
   mineral_names = this_player()->query_minerals();
   maxi = sizeof(mineral_names);
   for (i = 0; i < maxi; i++) {
    name = mineral_names[i];
    if (name = tick) {
     player = this_player();
     price = STOCK_D->query_mineral_price(tick);
     total = ftoi(price * amount);
     player_money = player->query_total_money();
     if (player_money > total) {
       player->add_money("credit", -total);
       player->increase_mineral_amount(tick, ftoi(amount));
       write("%^GREEN%^You have purchased %^CYAN%^" + ftoi(amount) + " %^HWHITE%^%^BOLD%^" + tick + "%^RESET%^GREEN%^ for %^CYAN%^" + total + "%^GREEN%^ credits%^RESET%^");
     }
     write("Total: " + total);
     return 1;
   } else {
     write("%^RED%^I'm sorry I can't find a ticker with that mineral, case matters%^RESET%^");
     write("%^GREEN%^Syntax:%^RESET%^ purchase amount Mineral");
     write("%^GREEN%^Example:%^RESET%^ purchase 300 Aluminum");
     return 1;
   }
 }
}


int do_playerminerals(string arg) {
   string *mineral_names, *lines, *header;
   string name;
   int i, n, maxi, maxh, mineral_size;
   float mineral_price, mineral_amount, diff;
   mineral_names = this_player()->query_minerals();

   if (mineral_names) {
     header = allocate(5);
     header[0] = "--------------------------------------------------------------";
     header[1] = "%^REVERSE%^Holdings Report:%^RESET%^";
     header[2] = "--------------------------------------------------------------";
     header[3] = "Mineral\t\t\tPRICE\tAMOUNT\t\tTOTAL";
     header[4] = "--------------------------------------------------------------";
     maxi = sizeof(mineral_names);
     lines = allocate(maxi);
     for (i = 0; i < maxi; i++) {
        name = mineral_names[i];
        diff = STOCK_D->query_mineral_diff(name);
        mineral_price = STOCK_D->query_mineral_price(name);
        mineral_amount = this_player()->query_mineral_amount_float(name);
        lines[i] = "";
      if (diff > 0.00) {
         lines[i] += "%^GREEN%^";
      }
      if (diff < 0.00) {
         lines[i] += "%^RED%^";
      }
        lines[i] += name;
        mineral_size = strlen(name);
        for (n = 0; n < (20 - mineral_size); n++) {
          lines[i] += " ";
        }
        lines[i] += "\t" + mineral_price;
        lines[i] += "\t" + mineral_amount;
        lines[i] += "\t\t" + (mineral_amount * mineral_price);
        lines[i] += "%^RESET%^";
     }

     this_player()->more(header+lines);
     return 1;
   } else {
     write("You have no mineral holdings");
     return 1;
   }
}


int do_minerals(string arg) {
   string *mineral_names, *lines, *header;
   string name;
   float diff;
   int i, n, maxi, maxh, mineral_size;
   write("--------------------------------------------------------------");
   write(" %^REVERSE%^Current Market Prices:%^RESET%^");
   write("--------------------------------------------------------------");
   write(" Mineral\t\t\t\tPRICE\t\tDIFF");
   write("--------------------------------------------------------------");
   mineral_names = STOCK_D->query_minerals();
   maxi = sizeof(mineral_names);
   lines = allocate(maxi);

   for (i = 0; i < maxi; i++) {
      name = mineral_names[i];
      diff = STOCK_D->query_mineral_diff(name);
      lines[i] = "";
      if (diff > 0.00) {
         lines[i] += "%^GREEN%^";
      }
      if (diff < 0.00) {
         lines[i] += "%^RED%^";
      }
      lines[i] += " " + name;
      mineral_size = strlen(name);
      for (n = 0; n < (30 - mineral_size); n++) {
        lines[i] += " ";
      }
      lines[i] += "\t\t";
      lines[i] += STOCK_D->query_mineral_price(name);
      lines[i] += "\t\t";
      lines[i] += diff;
      lines[i] += "%^RESET%^";
      write(lines[i]);
   }
   return 1;
}
