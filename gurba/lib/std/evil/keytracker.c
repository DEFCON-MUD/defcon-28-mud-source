int do_keytrack(int arg) {
  int * key_tracker; /* tracks 8 keys from quest */
  object player; /* tracks player*/
  player = this_player();
  key_tracker = player->get_key_tracker();
  if (!key_tracker) {
    key_tracker = (( { 0, 0, 0, 0, 0, 0, 0, 0 } ));
  }
   if (key_tracker[arg] == 0 ) {
      write("You push the button and your key tracker is updated\n");
      if (!key_tracker) {
        key_tracker = (( { 0, 0, 0, 0, 0, 0, 0, 0 } ));
      }
        key_tracker[arg] = 1;
        player->set_key_tracker(( { key_tracker[0], key_tracker[1], key_tracker[2], key_tracker[3], key_tracker[4], key_tracker[5], key_tracker[6], key_tracker[7] } ));
      return 1;
   } else {
      write("Your key tracker already has that token....\n");
      return 1;
   }
  return 0;
}
