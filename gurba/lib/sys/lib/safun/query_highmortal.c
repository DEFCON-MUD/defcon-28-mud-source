nomask int query_highmortal(mixed player) {
   int p;
   int plvl;

   if (objectp(player)) {
      if (!player <-PLAYER_OB && !player <-USER_OB) {
         return 0;
      }
      plvl = player->query_level();
   } else {
      argcheck(stringp(player), 1, "player object or string");
   }

   if (plvl > 19) {
     return 1;
   }

   return 0;
}
