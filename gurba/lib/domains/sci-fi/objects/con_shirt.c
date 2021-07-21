#include "../domain.h"

inherit "/std/armor";

int style;

void set_style(int variant);
void setup(void);

void set_style(int variant) {
  if (!variant) {
    style = random(5) + 1;
  } else {
    style = variant;
  }

  switch(style) {
    case 1:
      set_short("a derpcon t-shirt");
      set_long("World renown for it's legendary derpiness. This conference " +
        "t-shirt shows that you're a loyal attendee and proud of it.");
      add_adj("derpcon");
      break;
    case 2:
      set_short("an elastic-global-coin crypto t-shirt");
      set_long("Crypto is short for cryptocurrency! It's not gambling, it's "
        + "an investment! Yeah this t-shirt will tell all the haters!");
      add_adj("crypto");
      break;
    case 3:
      set_short("a meme t-shirt");
      set_long("CAT FROG RAINBOWS SUB-TEXT! This has got it all.");
      add_adj("meme");
      break;
    case 4:
      set_short("a respectable vendor t-shirt");
      set_long("Solid and stable, community cred, gives back. This company " +
        "is a rare breed. Of course you want to show your support by " +
        "wearing some of their swag.");
      add_adj("vendor");
      add_adj("respectable");
      break;
    case 5:
      set_short("a trevor forget t-shirt");
      set_long("That poor little cockroach never saw that sweet milky end " +
        "coming. We'll always remember you Trevor.");
      add_adj("trevor");
      break;
    default:
      set_short("a plain black t-shirt");
      set_long("A vendor was giving these out for some reason. There isn't " +
        "a logo on it though. Maybe they weren't paying attention?");
      add_adj("black");
      break;
  }
}

void setup(void) {
  set_id("conference t-shirt");
  add_ids("shirt", "tshirt", "t-shirt");

  set_style(style);
  set_gettable(1);

  set_slot("body");
  set_wear_message("$N $vput on $o.");
  set_remove_message("$N $vtake off $o.");

  set_ac(3);
  set_value(20);
  set_size(3);

  set_weight(2);
}
