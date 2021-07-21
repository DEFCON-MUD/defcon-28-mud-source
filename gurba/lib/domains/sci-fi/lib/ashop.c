string do_short(void) {
  string str;
  str = "Armour Shop";
  return str;
}

string do_long(void) {
	return "Wow this is a special armour shop, it even has decent armour or something. Type list for a list of stuff from the autobot.";
}

int do_ashop(int arg) {
	object autobot;
	autobot = this_environment()->present("Autobot");
	if (autobot) {
		autobot->destruct();
        }
	switch(arg) {
		case 0:
			this_environment()->set_objects("/domains/core/monsters/abot_1_2.c");
			return 1;
                case 1:
                        this_environment()->set_objects("/domains/core/monsters/abot_3_4.c");
                        return 1;
                case 2:
                        this_environment()->set_objects("/domains/core/monsters/abot_5_6.c");
                        return 1;
                case 3:
                        this_environment()->set_objects("/domains/core/monsters/abot_7_8.c");
                        return 1;
                case 4:
                        this_environment()->set_objects("/domains/core/monsters/abot_9_10.c");
                        return 1;
                case 5:
                        this_environment()->set_objects("/domains/core/monsters/abot_11_12.c");
                        return 1;
                case 6:
                        this_environment()->set_objects("/domains/core/monsters/abot_13_14.c");
                        return 1;
                case 7:
                        this_environment()->set_objects("/domains/core/monsters/abot_15_16.c");
                        return 1;
                case 8:
                        this_environment()->set_objects("/domains/core/monsters/abot_17_18.c");
                        return 1;
                case 9:
                        this_environment()->set_objects("/domains/core/monsters/abot_19_20.c");
                        return 1;
                case 10:
                        this_environment()->set_objects("/domains/core/monsters/abot_1_2.c");
                        return 1;
		default:
			this_environment()->set_objects("/domains/core/monsters/abot_1_2.c");
			return 1;

	}
	return 1;

}
