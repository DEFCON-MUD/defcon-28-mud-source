#define TO this_object()

int do_list(string arg) {
  int acost, bcost;
  object player;
  string message;

  player = this_player();

  acost = 1000000;
  bcost = 100000;

  write("-----------------------------------------------------------------\n");
  write("| %^REVERSE%^Sketchy Skill Upgrades%^RESET%^                                        |\n");
  write("-----------------------------------------------------------------\n");
  write("  %^MAGENTA%^ Mining B %^RESET%^\t Grants Acccess to East Mine\t\t%^GREEN%^100000%^RESET%^");
  write("  %^MAGENTA%^ Mining A %^RESET%^\t Grants Acccess to South Mine\t\t%^GREEN%^1000000%^RESET%^");
  write("-----------------------------------------------------------------\n");
  return 1;
}

int do_upgrade(string arg) {
  int szof, pcredits, acost, bcost;
  mixed *args;
  string player_rank, rank, career;
  args = explode(arg, " ");
  szof = sizeof(args);
  acost = 1000000;
  bcost = 100000;
  if ( szof > 1) {
    sscanf(arg, "%s %s", career, rank);
    if (strlen(rank) > 1) {
      sscanf(arg, "%s %s", rank, career);
    }
    player_rank = this_player()->get_career_rank(career);
    pcredits = this_player()->query_total_money();
    if (lowercase(rank) == "a" && lowercase(career) == "mining" && pcredits > acost && lowercase(player_rank) != "a") {
      this_player()->add_money("credit", -acost);
      this_player()->set_career(lowercase(career), uppercase(rank));
      write("You have been upgraded to " + career + " rank " + uppercase(rank));
      return 1;
    }
    if (lowercase(rank) == "b" && lowercase(career) == "mining" && pcredits > bcost && lowercase(player_rank) != "b") {
      this_player()->add_money("credit", -bcost);
      this_player()->set_career(lowercase(career), uppercase(rank));
      write("You have been upgraded to " + career + " rank " + uppercase(rank));
      return 1;
    }
    if (lowercase(rank) == "d" && lowercase(career) == "mining" && pcredits > acost) {
      this_player()->set_career(lowercase(career), uppercase("c"));
      write("You have been reset to level C for rank " + rank + ", tough luck then...");
      return 1;
    }
    if (pcredits < acost && lowercase(rank) == "a" && lowercase(career) == "mining") {
      write("I'm sorry, you need atleast " + acost + " credits to purchase that pass");
      return 1;
    }
    if (pcredits < bcost && lowercase(rank) == "b" && lowercase(career) == "mining") {
      write("I'm sorry, you need atleast " + bcost + " credits to purchase that pass");
      return 1;
    }
  } else {
    write("%^HWHITE%^Type: %^MAGENTA%^upgrade %^RESET%^%^GREEN%^career%^RESET%^ %^CYAN%^rank%^RESET%^");
    write("%^HWHITE%^Example:%^RESET%^ upgrade mining A");
    return 1;
  }
}
