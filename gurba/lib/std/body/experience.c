int level, experience;

int ready_for_next_level(void) {
   int tmpexp;

   tmpexp = level * level * 2000;

   if (experience > tmpexp) {
      return 1;
   }
   return 0;
}

string query_level_title(int level) {
   switch (level) {
      case 1:
         return "%^EXT_196%^Clone%^RESET%^";
         break;
      case 2:
         return "%^EXT_202%^Recruit%^RESET%^";
         break;
      case 3:
         return "%^EXT_208%^Cadet%^RESET%^";
         break;
      case 4:
         return "%^EXT_214%^Intern%^RESET%^";
         break;
      case 5:
         return "%^EXT_220%^Apprentice%^RESET%^";
         break;
      case 6:
         return "%^EXT_226%^Probationary Employee%^RESET%^";
         break;
      case 7:
         return "%^EXT_195%^Junior Employee%^RESET%^";
         break;
      case 8:
         return "%^EXT_189%^Employee%^RESET%^";
         break;
      case 9:
         return "%^EXT_183%^Supervisor%^RESET%^";
         break;
      case 10:
         return "%^EXT_177%^Foreman%^RESET%^";
         break;
      case 11:
         return "%^EXT_171%^Boss%^RESET%^";
         break;
      case 12:
         return "%^EXT_165%^Overseer%^RESET%^";
         break;
      case 13:
         return "%^EXT_129%^Monitor%^RESET%^";
         break;
      case 14:
         return "%^EXT_93%^Gaffer%^RESET%^";
         break;
      case 15:
         return "%^EXT_57%^Junior Manager%^RESET%^";
         break;
      case 16:
         return "%^EXT_21%^Manager%^RESET%^";
         break;
      case 17:
         return "%^EXT_27%^Senior Manager%^RESET%^";
         break;
      case 18:
         return "%^EXT_33%^Director%^RESET%^";
         break;
      case 19:
         return "%^EXT_39%^Managing Director%^RESET%^";
         break;
      default:
         return "%^EXT_45%^Vice President%^RESET%^";
         break;
   }
}

void set_level(int lvl) {
   object obj;
   int tmpexp;
   obj = this_object();
   if (obj->is_player()) {
      obj->initialize_stat_dependant_variables();
   }
   switch (lvl) {
     case 1:
       tmpexp = 0;
       break;
     case 2:
       tmpexp = 2000;
       break;
     default:
       tmpexp = ((lvl - 1) * (lvl - 1)) * 2000;
       break;
   }
   level = lvl;
   obj->set_title("$N the " + query_level_title(level));
   obj->set_expr(tmpexp);
   obj->set_hp(obj->query_max_hp());
   obj->set_end(obj->query_max_end());
   obj->set_mana(obj->query_max_mana());
   obj->set_internal_max_weight((15 + this_object()->query_base_stat("str")) * 100);
}

void reset_title(void) {
   object obj;
   int lvl;
   obj = this_object();
   lvl = obj->query_level();
   obj->set_title("$N the " + query_level_title(level));
}

void increase_level(void) {
   object obj;
   obj = this_object();
   level += 1;
   if (obj->is_player()) {
      obj->initialize_stat_dependant_variables();
   }
   obj->set_title("$N " + query_level_title(level));
   obj->set_hp(obj->query_max_hp());
   obj->set_end(obj->query_max_end());
   obj->set_mana(obj->query_max_mana());
   obj->set_internal_max_weight((15 + this_object()->query_base_stat("str")) * 100);
   CHANNEL_D->chan_send_string("announce", "", this_object()->query_name() +" has advanced to " + obj->query_level_title(level), 1);
}

void increase_expr(int expr) {
   if (expr < 0) {
      expr = expr * -1;
   }
   experience += expr;
   if (experience < 0) {
      experience = 0;
   }
}

void decrease_expr(int expr) {
   if (expr > 0) {
      expr = expr * -1;
   }
   experience -= expr;
   if (experience < 0) {
      experience = 0;
   }
}

void set_expr(int expr) {
   experience = expr;
   if (experience < 0) {
      experience = 0;
   }
}

int query_expr(void) {
   return (experience);
}

int query_level(void) {
   return (level);
}
