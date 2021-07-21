int coins; /* Players money on them */
int bank; /* Players money in the bank */
mapping stocks; /* Players total stock holdings */
mapping minerals; /* Players mineral holdings */

mixed *query_all_coins(void) {
   string *currencies;
   int value, i, num, worth;
   mixed *c;

   c = ({ });

   value = coins;

   currencies = MONEY_D->query_currencies();

   for (i = sizeof(currencies) -1; i >= 0; i--) {
      worth = MONEY_D->query_value(currencies[i]);
      if (value > 0) {
         num = value / worth;
         value = value - (num * worth);
      } else {
          num = 0;
      }
      c += ({ ({ currencies[i], num }) });
   }
   return c;
}

int clear_money(void) {
   coins = 0;
}

int remove_all_stocks(void) {
   stocks = ([ ]);
}

int remove_all_minerals(void) {
   minerals = ([ ]);
}

void set_stock_amount(string stock, int amount) {
   stocks[stock] = amount;
}

void set_mineral_amount(string mineral, int amount) {
   minerals[mineral] = amount;
}

string *query_stocks(void) {
  if (!stocks) {
    stocks = ([ ]);
  }
  return map_indices(stocks);
}

string *query_minerals(void) {
  if (!minerals) {
    minerals = ([ ]);
  }
  return map_indices(minerals);

}

int query_stock_amount(string stock) {
   if (stocks) {
     if (stocks[stock]) {
        return stocks[stock];
     } else {
        return 0;
     }
   } else {
     remove_all_stocks();
     return 0;
   }
}

int query_mineral_amount(string mineral) {
  if (minerals) {
     if (minerals[mineral]) {
          return minerals[mineral];
     } else {
          return 0;
     }
  } else {
     remove_all_minerals();
     return 0;
  }
}

float query_mineral_amount_float(string mineral) {
  string str;
  float flt;
  if (minerals) {
     if (minerals[mineral]) {
          str = minerals[mineral] + ".00";
          flt = atof(str);
          return flt;
     } else {
          return 0.00;
     }
  } else {
     remove_all_minerals();
     return 0.00;
  }
}

float query_stock_amount_float(string stock) {
  string str;
  float flt;
  if (stocks) {
     if (stocks[stock]) {
          str = stocks[stock] + ".00";
          flt = atof(str);
          return flt;
     } else {
          return 0.00;
     }
  } else {
     remove_all_stocks();
     return 0.00;
  }
}

void increase_stock_amount(string stock, int change) {
   int old;
   old = query_stock_amount(stock);
   set_stock_amount(stock, (old + change));
}

void increase_mineral_amount(string mineral, int change) {
   int old;
   old = query_mineral_amount(mineral);
   set_mineral_amount(mineral, (old + change));
}

void decrease_stock_amount(string stock, int change) {
   int old;
   old = query_stock_amount(stock);
   set_stock_amount(stock, (old - change));
}

void decrease_mineral_amount(string mineral, int change) {
   int old;
   old = query_mineral_amount(mineral);
   set_mineral_amount(mineral, (old - change));
}

int add_money(string type, int amount) {
   int value;

   value = MONEY_D->query_value(type);

   value = value * amount;
   value = coins + value;
   if (value >= 0) {
      coins = value;
      return 1;
   }
   return 0;
}

int query_total_money(void) {
   return coins;
}

int query_bank(void) {
   return bank;
}

int withdraw(int x) {
   if (bank >= x) {
      bank -= x;
      coins += x;
      return 1;
   }
   return 0;
}

int deposit(int x) {
   if (coins >= x) {
      coins -= x;
      bank += x;
      return 1;
   }
   return 0;
}
