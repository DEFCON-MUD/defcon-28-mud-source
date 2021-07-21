inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Usage: score [-h] [-q] [PLAYER]" });
   lines += ({ "" });
   lines += ({ "Gives you basic stats about player PLAYER." });
   lines += ({ "If no player is given give your stats." });
   lines += ({ "" });
   lines += ({ "Options:" });
   lines += ({ "\t-h\tHelp, this usage message." });
   lines += ({ "Examples:" });
   lines += ({ "\tscore" });
   lines += ({ "\tscore sirdude" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "hp");
   add_also("player", "inventory");
   add_also("player", "junk");
   add_also("player", "levels");
   add_also("player", "skills");
   add_also("player", "top");

   add_also("wiz", "status");
}

static void main(string str) {
   int mh, h, expr, level, quest, mm, m, me, e, ac, i, mw, w, next_xp, dp, easymode;
   mixed *money;
   object obj;
   string age, *l, follower;

   if (!alsos) {
      setup_alsos();
   }

   quest = 0;
   if (str == "-q") {
      str = "";
      quest = 1;
   } else if (sscanf(str, "-q %s", str)) {
      quest = 1;
   } else if (sscanf(str, "-%s", str)) {
      this_player()->more(usage());
      return;
   }

   if (!empty_str(str)) {
      if (query_wizard(this_player())) {
         obj = USER_D->find_player(str);
         if (!obj) {
            write("Unable to find player: " + str + "\n");
            return;
         }
      } else {
         this_player()->more(usage());
         return;
      }
   } else {
      obj = this_player();
   }
   dp = obj->query_deathproof();
   money = obj->query_all_coins();
   mh = obj->query_max_hp();
   h = obj->query_hp();
   mm = obj->query_max_mana();
   m = obj->query_mana();
   me = obj->query_max_end();
   e = obj->query_end();
   expr = obj->query_expr();
   ac = obj->query_defense();
   level = obj->query_level();
   age = obj->query_age();
   w = this_player()->query_internal_weight();
   mw = this_player()->query_internal_max_weight();
   next_xp = level * level * 2000;

   l = ({ "%^YELLOW%^Employee record%^RESET%^" });
   l += ({ "%^HWHITE%^=-=-=-=-=-=-=-=%^RESET%^" });
   l += ({ "%^GREEN%^Name:%^RESET%^ " + obj->query_name() });
   l += ({ "%^GREEN%^Age:%^RESET%^" + age });
   l += ({ "%^GREEN%^Rank:%^RESET%^ " + obj->query_level_title(level) });
   l += ({ "%^GREEN%^Gender:%^RESET%^ " + obj->query_gender() });
   l += ({ "%^GREEN%^Species:%^RESET%^ " + obj->query_race() });
   l += ({ "%^GREEN%^Status:%^RESET%^ " + obj->query_status()});
   if (dp == 1) {
     l += ({ "%^GREEN%^Deathproof%^RESET%^: YES%^RESET%^\n" });
   } else {
     l += ({ "%^GREEN%^Deathproof%^RESET%^: %^RED%^NO%^RESET%^\n" });
   }
   l += ({ "%^YELLOW%^Stats%^" });
   l += ({ "%^HWHITE%^=-=-=%^RESET%^" });
   l += ({ "%^GREEN%^Strength    :%^RESET%^  " + obj->query_stat("str") +
      "\t\t" + "%^GREEN%^Hit points :%^RESET%^   " + h + "/" + mh + "  (" +
      percentage(h, mh) + "%)" });
   l += ({ "%^GREEN%^Intelligence:%^RESET%^  " + obj->query_stat("int") +
      "\t\t" + "%^GREEN%^Mana       :%^RESET%^   " + m + "/" + mm + "  (" +
      percentage(m, mm) + "%)" });
   l += ({ "%^GREEN%^Wisdom      :%^RESET%^  " + obj->query_stat("wis") +
      "\t\t" + "%^GREEN%^Endurance  :%^RESET%^   " + e + "/" + me  + "  (" +
      percentage(e, me) + "%)" });
   l += ({ "%^GREEN%^Dexterity   :%^RESET%^  " + obj->query_stat("dex") +
      "\t\t" + "%^GREEN%^Armor class:%^RESET%^   " + ac });
   l += ({ "%^GREEN%^Constitution:%^RESET%^  " + obj->query_stat("con") +
      "\t\t" + "%^GREEN%^Level      :%^RESET%^   " + level });
   l += ({ "%^GREEN%^Charisma    :%^RESET%^  " + obj->query_stat("cha") +
      "\t\t" + "%^GREEN%^Experience :%^RESET%^   " + add_comma("" + expr) });
   l += ({ "%^GREEN%^Encumberance:%^RESET%^  " + w + "/" + mw + " (" +
      percentage(w, mw) + "%)\t" + "%^GREEN%^Next Level :%^RESET%^   " +
      add_comma("" + next_xp)
      });

   l += ({ "%^GREEN%^Kills:%^RESET%^ " + add_comma("" + obj->query_kills()) + " " +
      "\t\t\t%^GREEN%^Killed:%^RESET%^ " + add_comma("" + obj->query_killed()) });

   for (i = 0; i < sizeof(money); i++) {
      l += ({ "%^GREEN%^" + capitalize(money[i][0]) + "s:%^RESET%^ " +
         add_comma("" + money[i][1]) });
   }

   if (quest) {
      string *quests;
      int j, k;

      l += ({ "%^GREEN%^Quests Completed:%^RESET%^" });
      quests = this_player()->query_quests_completed();
      if (quests) {
         k = sizeof(quests);
         for (j = 0; j < k; j++) {
            l += ({ "\t" + quests[j] });
         }
      }
   }

   follower = this_player()->query_follower();
   if (follower != "") {
      l += ({ "" });
      l += ({ "You are followinging: " + follower });
   }

   this_player()->more(l);

   return;
}
