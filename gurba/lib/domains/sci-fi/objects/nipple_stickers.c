#include "../domain.h"

inherit "/std/object";
inherit "/std/modules/m_readable";
inherit "/std/modules/m_wearable";

int style;

void after_unwear(object player, string cmd);
void after_wear(object player);
int do_flick(string target);
int do_read(object who);
void perform_flick(object owner);
void set_style(int variant);
void setup(void);

void after_unwear(object player, string cmd) {
  if (player) {
    player->decrease_hp(5);
  }
}

void after_wear(object player) {
  write("The pasties stick fast. They must have a good adhesive and will " +
    "likely be painful to remove...");
}

int do_flick(string target) {
  object obj;
  string adj, what;
  int num;

  if (!target || target == "") {
    return 0;
  }

  num = 1;

  if (sscanf(target, "all %s %s", adj, what) == 2) {
    if (this_object()->is_adj(adj) && this_object()->is_id(what)) {
      perform_flick(this_player());
      return 1;
    }
  } else if (sscanf(target, "all %s", what) == 1) {
    if (this_object()->is_id(what)) {
      perform_flick(this_player());
      return 1;
    }
  } else if (sscanf(target, "%s %s %d", adj, what, num) == 3 || sscanf(target, "%s %s", adj, what) == 2) {
    if (!this_object()->is_id(what)) {
      return 1;
    }

    obj = this_player()->find_adj_object_num(adj, what, num);
  } else if (sscanf(target, "%s %d", what, num) == 2 || sscanf(target, "%s", what, num)) {
    obj = this_player()->find_object_num(what, num);
  }

  if (!obj) {
    return 1;
  }

  if (clone_num(this_object()) == clone_num(obj)) {
    perform_flick(this_player());
    return 1;
  }

  return 1;
}

int do_read(object who) {
  string msg;
  msg = query_message();

  if (is_worn()) {
    write("You can't read the note while you're wearing them.");
  } else {
    write(msg);
  }

  return 1;
}

void perform_flick(object owner) {
  write("You flick each of the pasties in turn...");

  if (!owner) {
    return;
  }

  if (is_worn()) {
    owner->query_environment()->tell_room(owner,
      owner->query_Name() + " spends some time flicking some of " +
      "the pasties on their body.");
    write("   ...but nothing much seems to happen.");
  } else {
    owner->query_environment()->tell_room(owner,
      owner->query_Name() + " spends some time flicking a set of " +
      "pasties. They seem to shimmer a bit.");
    set_style(0);
    write("   ...and the pasties morph into a new style!");
  }
}

void set_style(int variant) {
  string desc;
  int old_style;

  if (!variant) {
    /* Ensure we actually change to a new style */
    old_style = style;
    while (style == old_style) {
      style = random(5) + 1;
    }
  } else {
    style = variant;
  }

  switch(style) {
    case 1:
      desc = "butterfly";
      set_adj(desc);
      set_banes(( { } ));
      break;
    case 2:
      desc = "hope";
      set_adj(desc);
      set_banes(( { "hope" } ));
      break;
    case 3:
      desc = "horse";
      set_adj(desc);
      set_banes(( { } ));
      break;
    case 4:
      desc = "Dave Kennedy";
      set_adj("dave", "kennedy");
      set_banes(( { } ));
      break;
    default:
      desc = "Pasties";
      set_adj("pasties");
      set_banes(( { } ));
      break;
  }

  set_short("A set of " + desc + " pasties");
  set_long("This is a set of enchanted " + desc + " pasties. There is a " +
    "small note on the sticky side.");
}

void setup(void) {
  set_id("set of pasties");
  add_ids("pastie", "pasties", "pasty");

  set_style(style);
  set_gettable(1);
  set_slot("apparel");

  set_wear_message("$N $vstick $o on.");
  set_remove_message("$N $vpeel $o off their body. It really smarts.");

  set_message("The small writing on the sticky side of the pasties " +
    "reads: Flick while free for a change of style. dW5pciB1YmNy");

  set_value(25);
  set_weight(0);

  add_action("do_flick", "flick");
}
