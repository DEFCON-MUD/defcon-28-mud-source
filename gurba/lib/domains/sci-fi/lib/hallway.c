string do_short(void) {
  string str;
  str = "Hallway";
  return str;
}

string do_long(void) {
	switch(random(11)) {
  		case 1:
  	  		return "This is yet another nondescript hallway, lets be honest evilmog is a lazy bastard and really doesn't want to describe a hallway so lets just pretend he did.";
  		case 2:
  	  		return "Whatever, you know this is a hallway, there are many others like it but this one is mine.";
  		case 3:
  			return "This is a super janky hallway, it was cobbled together with twine and duct tape, the walls appear to be cardboard, the floors look like construction paper. Oh wait nevermind thats the new yoshi for the switch, either way this hallway, much like that game look like the creator went to large efforts to make the creation look crappy.";
  		case 4:
  			return "I'm all out snark, I'm so lost without you, I know you were wrong believing for so long......\n\nOh wait this is a hallway, I think, or something.";
  		case 5:
  			return "This is a hallway, it connects a bunch of shops, the floor is nondescript and the walls look like cheap drywall painted with low quality paint. This room much like the rest of the AI/NextGen/BlockChain Hype is largely irrelevant.";
  		case 6:
  			return "This is a hallway. The floor looks much like the rest of this hallway, unimaginative and boring.";
  		case 7:
  			return "This is yet another hallway in the quadrant of snark. There are floors, walls, and possibly even directions.";
  		case 8:
  			return "This is yet another hallway in the journey to enlightenment, consider that it is not the room that changes but instead it is your perception of the room that changes.";
  		case 9:
  			return "This is yet another hallway, EvilMog is bored as hell making these. One of these days he's going to invite the DEFCON Furs crew to redecorate.";
  		case 10:
  			return "This is a hallway, its basically an exact duplicate of all the other hallways and no originality went into this room.";
  		case 11:
  			return "This is a hallway, it looks like any other hallway, highly generic and boring.";
  	default:
  	  return "This is a standard boring hallway, the floors are some sort of nondescript washable surface, the walls look like poorly painted drywall, its almost as if somebody slapped this together in a hurry.";
  }
}

int do_hallway(int arg) {
  return 1;
}
