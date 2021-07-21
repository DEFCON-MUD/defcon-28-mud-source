static int heal_rate, heal_amount, heal_time;
int player_age;
int stunned;
int paralysed;

#define YEAR 31536000
#define DAY 86400
#define HOUR 3600
#define MIN 60

void set_heal_rate(int rate) {
   heal_rate = rate;
}

int query_heal_rate(void) {
   return heal_rate;
}

void set_heal_step(int amt) {
   heal_amount = amt;
}

int query_heal_step(void) {
   return heal_amount;
}

int query_paralysed(void) {
   return paralysed;
}

int query_stunned(void) {
   return stunned;
}

void set_paralysed(int duration) {
   paralysed = duration;
}

void set_stunned(int duration) {
   stunned = duration;
}

void reduce_stunned() {
   stunned--;
   if (stunned < 0) {
      stunned = 0;
   }
}

void reduce_paralysed() {
   paralysed--;
   if (paralysed < 0) {
      paralysed = 0;
   }
}

void event_heart_beat(void) {
   if (this_object()->query_hp() < 1) {
      if (this_object()->is_dead() && this_object()->is_player()) {
         heal_time++;
         if (heal_time > heal_rate) {
            heal_time = 0;
            this_object()->message("You are dead... your body is being cloned... standby...\n");
         }
      } else {
         this_object()->die();
         return;
      }
   } else {
      if (!this_object()->is_player()) {
         /* allow monsters to talk, cast spells etc... */
         this_object()->do_extra_actions();

         heal_time++;
         if (heal_time > heal_rate) {
            heal_time = 0;

            if (this_object()->query_hp() < this_object()->query_max_hp()) {
               this_object()->increase_hp(random(heal_amount) + 1);
            }
            if (this_object()->query_mana() < this_object()->query_max_mana()) {
               this_object()->increase_mana(random(heal_amount) + 1);
            }
            if (this_object()->query_end() < this_object()->query_max_end()) {
               this_object()->increase_end(random(2 * heal_amount) + 1);
            }
         }
      } else {
         heal_time++;
         if (heal_time > heal_rate) {
            heal_time = 0;

            
            /* Players do need to rest to heal hp and mana */
            if (1 == 1) { /* disable is_resting */
               if (this_object()->query_hp() < this_object()->query_max_hp()) {
                  this_object()->increase_hp(random(heal_amount) + 1);
               }
               if (this_object()->query_mana() <
                  this_object()->query_max_mana()) {
                  this_object()->increase_mana(random(heal_amount) + 1);
               }
            }

            if (this_object()->query_end() < this_object()->query_max_end()) {
               this_object()->increase_end(random(2 * heal_amount) + 1);
            }
         }
      }

      reduce_stunned();
      reduce_paralysed();

      /* Check here to see is we are in combat, if so, continue battle */
      if (!query_paralysed() && !query_stunned() &&
         this_object()->is_fighting() > 0) {
         this_object()->do_fight();
      } else {
         if (!query_paralysed() &&
            function_object("event_wander", this_object())) {
            call_other(this_object(), "event_wander");
         }
      }
   }

   /* A player ages when not idle */
   if (this_object()->is_player()) {
      if (this_object()->query_idle() < 60) {
         player_age += HEART_BEAT_INTERVAL;
         if (query_mortal(this_object())) {
            TOP_SCORE_D->save(this_object());
         }
      }
   }
}

string query_age(void) {
   string ret, tmp;
   int years, days, hours, mins, secs;

   secs = player_age;
   ret = " ";
   while (secs > YEAR) {
      years += 1;
      secs -= YEAR;
   }
   while (secs > DAY) {
      days += 1;
      secs -= DAY;
   }

   while (secs > HOUR) {
      hours += 1;
      secs -= HOUR;
   }
   while (secs > MIN) {
      mins += 1;
      secs -= MIN;
   }

   if (years > 0) {
      if (years == 1) {
         tmp = " year ";
      } else {
         tmp = " years ";
      }
      ret += years + tmp;
   }
   if (days > 0) {
      if (days == 1) {
         tmp = " day ";
      } else {
         tmp = " days ";
      }
      ret += days + tmp;
   }
   if (hours > 0) {
      if (hours == 1) {
         tmp = " hr ";
      } else {
         tmp = " hrs ";
      }
      ret += hours + tmp;
   }
   if (mins > 0) {
      if (mins == 1) {
         tmp = " min ";
      } else {
         tmp = " mins ";
      }
      ret += mins + tmp;
   }
   if (secs > 0) {
      if (secs == 1) {
         tmp = " sec ";
      } else {
         tmp = " secs ";
      }
      ret += secs + tmp;
   }

   return ret;
}

int query_age_in_seconds(void) {
   return player_age;
}

void die2(void) {
   object player;
   player = this_object();
         write("You are feeling very disoriented and confused........");
         player->move(player->query_death_room());
         player->query_environment()->tell_room(player, 
         "A shimmering light envelopes " + player->query_name() + ".");
         if (player->query_deathproof() == 1) {
            write("%^GREEN%^%^BOLD%^You have been saved by the grace of EvilMog and are immune from penalties.%^RESET%^");
            player->set_deathproof(0);
            player->set_dead(0);
            player->set_hp(1);
            write("%^RED%^%^BOLD%^You are no longer deathproof!!!%^RESET%^");
            call_other(this_object(), "do_look", this_environment());
            player->increment_death();
         } else {
            write("%^BOLD%^%^RED%^Since you are not deathproof you have been reset to level 1 with no experience, maybe you should buy insurance.%^RESET%^");
            player->set_hp(1);
            player->set_dead(0);
            if (player->query_level() > 2) {
               player->set_level(1);
            }
            call_other(this_object(), "do_look", this_environment());
            player->increment_death();
         }

      return;
}

void die(void) {
   object killer, obj, *inv;
   int i;

   killer = this_object()->query_killer();
   if (killer) {
      if (killer->is_player()) {
         int klvl, plvl, ldiff, xp_bonus;
         klvl = killer->query_level();
         plvl = this_object()->query_level();
         ldiff = plvl - klvl;

         if (ldiff < 1) {
            ldiff = 0;
         }
         xp_bonus = (ldiff * 100);
         if (ldiff > 0) {
            killer->increase_expr(xp_bonus);
            killer->message("You have gained " + xp_bonus + "XP as a bonus");
         }
         set_this_player(killer);
      }

      killer->message("%^BOLD%^%^CYAN%^You killed " +
         this_object()->query_Name() + ".%^RESET%^");
   }

   this_object()->simple_action("$N $vfall to the ground...dead.");

   obj = clone_object(DOMAINS_DIR + "/required/objects/corpse");

   inv = this_object()->query_inventory();
   for (i = sizeof(inv) - 1; i >= 0; i--) {
      if (inv[i]->query_worn()) {
         this_object()->do_remove(inv[i]);
      }
      if (inv[i]->query_wielded()) {
         this_object()->do_unwield(inv[i]);
      }
      inv[i]->move(obj);
   }

   obj->set_name(this_object()->query_name());
   obj->move(this_object()->query_environment());

   if (this_object()->is_player()) {
      this_object()->set_dead(1);
      this_object()->move("/domains/required/rooms/transport.c");
      this_object()->message("You have died.");
      this_object()->clear_money();
      CHANNEL_D->chan_send_string("announce", "", this_object()->query_name() +" has died", 1);
      write("You are feeling very disoriented and confused........");
      this_object()->move(this_object()->query_death_room());
      this_object()->query_environment()->tell_room(this_object(), 
         "A shimmering light envelopes " + this_object()->query_name() + ".");
      if (this_object()->query_deathproof() == 1) {
         this_object()->message("%^GREEN%^%^BOLD%^You have been saved by the grace of EvilMog and are immune from penalties.%^RESET%^");
         this_object()->set_deathproof(0);
         this_object()->set_dead(0);
         this_object()->set_hp(1);
         this_object()->message("%^RED%^%^BOLD%^You are no longer deathproof!!!%^RESET%^");
         call_other(this_object(), "do_look", this_environment());
         this_object()->increment_death();
         } else {
            this_object()->message("%^BOLD%^%^RED%^Since you are not deathproof you have been reset to level 1 with no experience, maybe you should buy insurance.%^RESET%^");
            this_object()->set_hp(1);
            this_object()->set_dead(0);
            if (this_object()->query_level() > 2) {
               this_object()->set_level(1);
            }
            call_other(this_object(), "do_look", this_environment());
            this_object()->increment_death();
         }

      return;
   } else {
      if (this_object()<-"/std/monster") {
         this_object()->monster_died();
      }
      EVENT_D->unsubscribe_event("heart_beat");
      this_object()->destruct();
   }
}

void create(void) {
   if (clone_num() ) {
      EVENT_D->subscribe_event("heart_beat");
      heal_time = 0;
      heal_rate = 10;
      heal_amount = 2;
      if (!intp(player_age)) {
         player_age = 0;
      }
   }
}
