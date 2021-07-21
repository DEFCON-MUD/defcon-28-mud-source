nomask int query_newbie(mixed player) {
   int p;
   int plvl;
   int woodland;
   int newbie;

   if (objectp(player)) {
      if (!player <-PLAYER_OB && !player <-USER_OB) {
         return 0;
      }
      plvl = player->query_level();
   } else {
      argcheck(stringp(player), 1, "player object or string");
   }

   if (player->is_completed_quest("NewbieVille") == 1) {
      newbie = 1;
   }
   if (player->is_completed_quest("Woodland") == 1) {
      woodland = 1;
   }

   if (newbie == 1) {
      if (woodland == 1) {
         return 0;
      } else {
         return 1;
      }
   } else {
      return 1;
   }
   return 1;

}