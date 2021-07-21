#include "../domain.h"

inherit "/std/weapon";

void setup(void) {
  set_id("bottle of smirnoff ice");
  add_adj("warm");
  add_ids("ice", "bottle", "smirnoff");

  set_short("A well heated bottle of smirnoff ice");
  set_long("A still steaming bottle of smirnoff ice. It's clear someone " +
    "has plans for this, and someone isn't going to enjoy it.");

  set_eatable(1);
  set_gettable(1);
  set_value(10);
  set_weight(2);

  set_min_damage(3);
  set_max_damage(20);
  set_hit_bonus(5);

  set_weapon_skill("combat/blunt/small");
  set_wield_type("single");
  set_wield_message("$N $vgrab $p $o.");
  set_unwield_message("$N $vput away $o. Out of sight out of mind.");

  set_weapon_actions(({ "club", "bash", "crush", "crack" }));
}

void ice_target(object tgt) {
  int hp_amount, end_amount;

  switch(random(3)) {
    case 0:
      hp_amount = tgt->query_max_hp();
      end_amount = tgt->query_max_end();

      write("In an act of absolute defiance; You proudly take a knee and " +
        "slam back the steaming bottle of smirnoff in one go without " +
        "hesitation.");
      tgt->query_environment()->tell_room(tgt,
        tgt->query_Name() + " presents a steaming hot smirnoff " +
        "bottle to everyone in room before confidently taking a knee and " +
        "slamming that atrocious beverage down. They've clearly been " +
        "practicing for this.");
      break;
    case 1:
      hp_amount = random(tgt->query_max_hp() / 2);
      end_amount = 0;

      write("The bottle has gone luke warm. You're able to get it down " +
        "after several very rough gulps.");
      tgt->query_environment()->tell_room(tgt,
        tgt->query_Name() + " looks glumly at a bottle of " +
        "smirnoff. They've probably been putting this off for a while but " +
        "have finally worked themselves up to drinking it. After several " +
        "uncomfortable chugs they get it down.");
      break;
    default:
      write("You gag as the foul liquid approaches your mouth and fail to " +
        "take a drink");
      tgt->query_environment()->tell_room(tgt,
        tgt->query_Name() + " attempts to drink a smirnoff. They " +
        "gag as it approaches their mouth and they give up on the attempt.");

      return;
  }

  tgt->increase_hp(hp_amount);
  tgt->increase_end(end_amount);
  this_object()->destruct();
}

int do_eat(void) {
  ice_target(this_player());
  return 1;
}
