int do_sellstock(string arg) {
   string str, tick;
   float amount, price;
   int player_money, total_money, total, player_stocks;
   object player;
   sscanf(arg, "%f %s", amount, tick);
  if (amount < 1.00) {
    return 0;
  }
   if (STOCK_D->is_stock(tick)) {
      price = STOCK_D->query_stock_price(tick);
      total = ftoi(price * amount);
      player = this_player();
      player_stocks = this_player()->query_stock_amount(tick);
/* EVILMOG TODO */
      if (player_stocks >= ftoi(amount)) {
       player->add_money("credit", total);
       player->decrease_stock_amount(tick, ftoi(amount));
       write("%^GREEN%^You have sold %^CYAN%^" + ftoi(amount) + " %^HWHITE%^%^BOLD%^" + tick + "%^GREEN%^ for %^CYAN%^" + total + "%^GREEN%^ credits%^RESET%^");
      } else {
        write("%^RED%^You don't have enough stock for that!%^RESET%^");
      }
   } else {
        write("%^RED%^I'm sorry I can't find a ticker with that name, try all uppercase\n%^GREEN%^Syntax: %^RESET%^redeem amount TICK\n%^GREEN%^Example: %^RESET%^redeem 300 MOG");
   }
   return 1;
}

int do_purchasestock(string arg) {
   string str, tick;
   float amount, price;
   int player_money, total_money, total;
   object player;
   sscanf(arg, "%f %s", amount, tick);
   if (amount < 1.00) {
    return 0;
   }
   if (STOCK_D->is_stock(tick)) {
     player = this_player();
     price = STOCK_D->query_stock_price(tick);
     total = ftoi(price * amount);
     player_money = player->query_total_money();
     if (player_money > total) {
       player->add_money("credit", -total);
       player->increase_stock_amount(tick, ftoi(amount));
       write("%^GREEN%^You have purchased %^CYAN%^" + ftoi(amount) + " %^HWHITE%^%^BOLD%^" + tick + "%^RESET%^GREEN%^ for %^CYAN%^" + total + "%^GREEN%^ credits%^RESET%^");
     }
     write("Total: " + total);
     return 1;
   } else {
     write("%^RED%^I'm sorry I can't find a ticker with that name, try all uppercase%^RESET%^");
     write("%^GREEN%^Syntax:%^RESET%^ purchase amount TICK");
     write("%^GREEN%^Example:%^RESET%^ purchase 300 MOG");
     return 1;
   }
}

int do_playerstocks(string arg) {
   string *stock_names, *lines, *header;
   string ticker, name;
   int i, n, maxi, maxh, stock_size;
   float stock_price, stock_amount, diff;
   stock_names = this_player()->query_stocks();

   if (stock_names) {
     header = allocate(5);
     header[0] = "--------------------------------------------------------------";
     header[1] = " %^REVERSE%^Holdings Report:%^RESET%^";
     header[2] = "--------------------------------------------------------------";
     header[3] = " TICK\tNAME\t\t\t\tPRICE\tAMOUNT\tTOTAL";
     header[4] = "--------------------------------------------------------------";
     maxi = sizeof(stock_names);
     lines = allocate(maxi);
     for (i = 0; i < maxi; i++) {
        ticker = stock_names[i];
        diff = STOCK_D->query_stock_diff(ticker);
        name = STOCK_D->query_stock_name(ticker);
        stock_price = STOCK_D->query_stock_price(ticker);
        stock_amount = this_player()->query_stock_amount_float(ticker);
        lines[i] = "";
        if (diff > 0.00) {
           lines[i] += "%^GREEN%^";
        }
        if (diff < 0.00) {
           lines[i] += "%^RED%^";
        }
        lines[i] += " " + ticker + "\t" + name;
        stock_size = strlen(name);
        for (n = 0; n < (24 - stock_size); n++) {
          lines[i] += " ";
        }
        lines[i] += "\t" + stock_price;
        lines[i] += "\t" + stock_amount;
        lines[i] += "\t" + (stock_amount * stock_price);
     }
     this_player()->more(header+lines);
   }
   return 1;
}

int do_stocks(string arg) {
   string *stock_names, *lines, *header;
   float diff;
   string ticker, name;
   int i, n, maxi, maxh, stock_size;
   header = allocate(5);
   header[0] = "--------------------------------------------------------------";
   header[1] = " %^REVERSE%^Current Market Prices:%^RESET%^";
   header[2] = "--------------------------------------------------------------";
   header[3] = " TICK\tNAME\t\t\t\tPRICE\t\tDIFF";
   header[4] = "--------------------------------------------------------------";
   stock_names = STOCK_D->query_stocks();
   maxi = sizeof(stock_names);
   lines = allocate(maxi);

   for (i = 0; i < maxi; i++) {
      ticker = stock_names[i];
      name = STOCK_D->query_stock_name(ticker);
      diff = STOCK_D->query_stock_diff(ticker);
      lines[i] = "";
      if (diff > 0.00) {
         lines[i] += "%^GREEN%^";
      }
      if (diff < 0.00) {
         lines[i] += "%^RED%^";
      }
      lines[i] += " " + ticker + "\t" + name;
      stock_size = strlen(name);
      for (n = 0; n < (30 - stock_size); n++) {
        lines[i] += " ";
      }
      lines[i] += "\t";
      lines[i] += STOCK_D->query_stock_price(stock_names[i]);
      lines[i] += "\t\t";
      lines[i] += diff;
      lines[i] += "%^RESET%^";
   }
   this_player()->more(header+lines);
   return 1;
}

