void restore_me(void);
void save_me(void);
#define DATAFILE "/daemons/data/stock_d.o"

mapping stocks;
mapping stocks_old;
mapping stock_names;
mapping minerals;
mapping minerals_old;

void create(void) {

   stocks = ([ ]);
   stocks_old = ([ ]);
   stock_names = ([ ]);
   minerals = ([ ]);
   minerals_old =([ ]);


   if (file_exists(DATAFILE)) {
      restore_me();
   } else {
      /* Create a default list if we do not already have one. */
      /* STOCKS */
      stock_names["FML"] = "Firefox Machine Learning";
      stocks_old["FML"] = 11.05;
      stocks["FML"] = 11.05;
      stock_names["COM"] = "Company";
      stocks["COM"] = 198.75;
      stocks_old["COM"] = 198.45;
      stock_names["MOG"] = "Evil Mog Enterprises";
      stocks["MOG"] = 120.95;
      stocks_old["MOG"] = 120.35;

      /* Minerals */
      minerals["Aluminum"] = 11.70;
      minerals_old["Aluminum"] = 11.65;
      minerals["Aluminum-titanium"] = 60.90;
      minerals_old["Aluminum-titanium"] = 61.25;
      minerals["Bauxite"] = 1.75;
      minerals_old["Bauxite"] = 1.70;
      minerals["Chromium"] = 6.65;
      minerals_old["Chromium"] = 6.65;
      minerals["Cobalt"] = 4.25;
      minerals_old["Cobalt"] = 4.15;
      minerals["Copper"] = 21.60;
      minerals_old["Copper"] = 21.60;
      minerals["Corezite"] = 138.10;
      minerals_old["Corezite"] = 138.10;
      minerals["Gold"] = 26.05;
      minerals_old["Gold"] = 25.95;
      minerals["Iron"] = 16.60;
      minerals_old["Iron"] = 16.55;
      minerals["Iron-nickel"] = 49.55;
      minerals_old["Iron-nickel"] = 49.60;
      minerals["Iron-tungsten"] = 64.65;
      minerals_old["Iron-tungsten"] = 64.25;
      minerals["Magnesium"] = 17.30;
      minerals_old["Magnesium"] = 17.40;
      minerals["Manganese"] = 14.40;
      minerals_old["Manganese"] = 14.55;
      minerals["Mithril"] = 92.35;
      minerals_old["Mithril"] = 92.30;
      minerals["Mithril-titanium"] = 152.75;
      minerals_old["Mithril-titanium"] = 152.90;
      minerals["Nickel"] = 23.25;
      minerals_old["Nickel"] = 23.20;
      minerals["Platinum"] = 24.35;
      minerals_old["Platinum"] = 24.20;
      minerals["Plutonium"] = 61.45;
      minerals_old["Plutonium"] = 61.25;
      minerals["Quartz"] = 17.45;
      minerals_old["Quartz"] = 17.50;
      minerals["Silica"] = 24.20;
      minerals_old["Silica"] = 24.15;
      minerals["Silicon"] = 8.75;
      minerals_old["Silicon"] = 87.70;
      minerals["Silver"] = 18.75;
      minerals_old["Silver"] = 18.80;
      minerals["Steel"] = 12.70;
      minerals_old["Steel"] = 12.60;
      minerals["Tantalum"] = 39.80;
      minerals_old["Tantalum"] = 39.85;
      minerals["Titanium"] = 44.65;
      minerals_old["Titanium"] = 44.55;
      minerals["Tungsten"] = 45.65;
      minerals_old["Tungsten"] = 45.65;
      minerals["Uranium"] = 49.45;
      minerals_old["Uranium"] = 49.40;
      minerals["Yttrium"] = 27.25;
      minerals_old["Yttrium"] = 27.20;
      save_me();
   }
}

static void restore_me(void) {
   unguarded("restore_object", DATAFILE);

}

static void save_me(void) {
   unguarded("save_object", DATAFILE);
}

void add_stock(string stock, float price) {
   stocks[stock] = price;
   save_me();
}

void add_minerals(string mineral, float price) {
   minerals[mineral] = price;
   save_me();
}

void set_stock_name(string stock, string name) {
  stock_names[stock] = name;
  save_me();
}

float query_stock_price(string stock) {
   float price;
   price = stocks[stock];
   return price;
}

float query_mineral_price(string mineral) {
   float price;
   price = minerals[mineral];
   return price;
}

float query_stock_diff(string stock) {
   float diff;
   float old;
   float price;
   old = stocks_old[stock];
   price = stocks[stock];
   diff = (price - old);
   diff = diff * 100.00;
   diff = round(diff);
   diff = diff / 100.00;
   return diff;
}

float query_mineral_diff(string mineral) {
   float diff;
   float old;
   float price;
   old = minerals_old[mineral];
   price = minerals[mineral];
   diff = (price - old);
   diff = diff * 100.00;
   diff = round(diff);
   diff = diff / 100.00;
   return diff;
}

int is_stock(string stock) {
   if (stocks[stock]) {
      return 1;
   }

   return 0;
}

int is_mineral(string mineral) {
   if (minerals[mineral]) {
      return 1;
   }

   return 0;
}

void remove_stock(string stock) {
   stocks[stock] = nil;
   save_me();
}

void set_stock_price(string stock, float price) {
   stocks_old[stock] = stocks[stock];
   stocks[stock] = price;
   save_me();
}

void set_mineral_price(string mineral, float price) {
   minerals_old[mineral] = minerals[mineral];
   minerals[mineral] = mineral;
   save_me();
}

void increase_stock_price(string stock, float change) {
  stocks_old[stock] = stocks[stock];
  stocks[stock] = stocks[stock] + change;
  save_me();
}

void increase_mineral_price(string mineral, float change) {
  minerals_old[mineral] = minerals[mineral];
  minerals[mineral] = minerals[mineral] + change;
  save_me();
}

void decrease_stock_price(string stock, float change) {
  stocks_old[stock] = stocks[stock];
  stocks[stock] = stocks[stock] - change;
  save_me();
}

void decrease_mineral_price(string mineral, float change) {
  minerals_old[mineral] = minerals[mineral];
  minerals[mineral] = minerals[mineral] - change;
  save_me();
}

string query_stock_name(string stock) {
   if (stock_names[stock]) {
     return (stock_names[stock]);
   }
    return "unknown";
}

void remove_all_stocks(void) {
   stocks = ([]);
   save_me();
}

void remove_all_minerals(void) {
   minerals = ([]);
   save_me();
}

string *query_stocks(void) {
   return map_indices(stocks);
}

string *query_minerals(void) {
   return map_indices(minerals);
}
