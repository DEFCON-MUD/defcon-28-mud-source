string do_short(void) {
  string str;
  str = "Office";
  return str;
}

string do_long(void) {
	switch(random(4)) {
  		case 1:
			return "This is a normal looking office, it even has the cheap carpet that most offices have. There is nothing otherwise remarkable about this room";
		case 2:
			return "This office is very basic. Everything from the furniture to the carpets look like it was stolen from a rental company.";
		case 3:
			return "How many ways can I describe a office, this one isn't original and according to my crystal ball the next one won't be either. Thank you for playing.";
		case 4:
			return "At first I had a dream that I was a bird and I soared towards the sky. I then flew towards the ground and imagined I was a tree, my roots grew and I became firmly grounded. I then imagined I was an office building. People came to work inside of me. People eventually lost their sense of self and the dreams died..............";
	  	default:
			return "This is a normal looking office, it even has the cheap carpet that most offices have. There is nothing otherwise remarkable about this room";
	}
}

int do_office(int arg) {
  return 1;
}
