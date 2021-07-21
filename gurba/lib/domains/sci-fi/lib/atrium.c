string do_short(void) {
  string str;
  str = "Atrium";
  return str;
}

string do_long(void) {
	switch(random(10)) {
  		case 1:
  			return "This park is very lush but looks to be overgrown, as if the gardening drones have abandoned this place. Vines and creepers are all over and random plants seem to be growing out of every crevice. It is also extremely humid as if somebody hacked into the climate controls.";
  		case 2:
  			return "The floor here is covered in some kind of alien grass and there are various plants all over the place. This park is in serious need of a weeding as invasive plant species are all over the place.";
  		case 3:
  			return "The grass here is extremely green and the trees are tall and overgrown. It is extremely humid in here as if somebody hacked the climate control system. Really I don't know its an overgrown atrium, imagine some sort of overgrown mess, something might eat you.";
  		case 4:
  			return "This is a nice lush park, calm and soothing, with the odd radioactive plant that will probably kill you, no big deal.";
  		case 5:
  			return "This really is a terrible park, its like the droids are on strike, the grass is overgrown, climate control went to hell.";
  		case 6:
  			return "This park just seems to go on and on, almost as if its cheap filler for some sort of demonic quest thought up by overlord EvilMog. This area shows no originality and its probably just here to mess with you.";
  		case 7:
  			return "Random plants of all kinds seem to be haphazardly planted here, the grass is overgrown and the bugs are all over here. It looks like somebody trashed the park and then spilled a bunch of random seeds wherever they could.";
  		case 8:
  			return "Ok its blatently apparent that evilmog is running out of material, he needs coffee badly. This park extends out everywhere, grass is green, plants are overgrown, climate is humid because well it just is.";
  		case 9:
  			return "This is some sort of atrium. Things are growing everywhere and its hard to tell where the support structures stop and the plants begin. You are pretty sure something is watching you.";
  		case 10:
  			return "This is an example of yet more filler text while you scan for keywords looking for the next quest item. You and I both know you don't care about the lush lawn or the majestic trees. Or the unicorn which shall henceforth be known as buttercup being rode by her valiant rider obsie or as some may call her the black death.";
	  	default:
	  		return "EvilMog put an errorcheck in because he doesn't understand the LPC random function and fails to account for a result of zero or other matches to his case statements. So here we are.\n\nBefore you is a lush atrium. You can hear a fountian in the distance. You smell the flowers, the sweet spring smell of flowers blooming. Plants grow over every available space.";
				}
}

int do_atrium(int arg) {
  return 1;
}