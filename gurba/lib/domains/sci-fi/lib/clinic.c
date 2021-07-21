string do_short(void) {
  string str;
  str = "Sketchy Clinic";
  return str;
}

string do_long(void) {
	return "This appears to be some sort of sketchy clinic. The tiles haven't been cleaned in ages and the floor is covered in blood.\n\nType '%^MAGENTA%^list%^HCYAN%^' to get a list of services.";
}

int do_clinic(int arg) {
	return 1;
}
