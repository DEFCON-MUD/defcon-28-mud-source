void restore_me(void);
void save_me(void);
#define DATAFILE "/daemons/data/evil/vnum_d.o"

mapping vnums;
mapping anums;
int current, acurrent;

void create(void) {

	vnums = ([ ]);
	anums = ([ ]);

	if (file_exists(DATAFILE)) {
		restore_me();
	} else {
		vnums = ([ ]);
		acurrent = 1;
		current = 1;
		save_me();
	}

}

static void restore_me(void) {
	if (!file_exists(DATAFILE)) {
		vnums = ([ ]);
		anums = ([ ]);
		save_me();
	}
	unguarded("restore_object", DATAFILE);
}

static void save_me(void) {
	unguarded("save_object", DATAFILE);
}

int reset_me(void) {
	vnums = ([ ]);
	anums = ([ ]);
	save_me();
}

int vnum(void) {
	int vnum;
	string path;
	path = explode(this_environment()->file_name(), ".")[0];
	if (!vnums[path]) {
		vnums[path] = current;
		current = current + 1;
		vnum = vnums[path];
		save_me();
	} else {
		vnum = vnums[path];
	}
	return vnum;
}

int vnum_lookup(string path) {
	/* NOTE THIS ADDS .C */
	int vnum;
	string tmp_path;
	tmp_path = explode(path, ".")[0];
	if (!vnums[tmp_path]) {
		vnums[tmp_path] = current;
		current = current + 1;
		vnum = vnums[tmp_path];
		save_me();
	} else {
		vnum = vnums[tmp_path];
	}
	return vnum;
}

string *query_vnums(void) {
   return map_indices(vnums);
}

int anum(void) {
	int anum;
	string *areas;
	string area;
	areas = this_player()->query_environment()->query_areas();
	if (sizeof(areas) < 1) {
		area = "unknown";
	} else {
		area = areas[0];
	}
	if (!anums[area]) {
		anums[area] = acurrent;
		acurrent = acurrent + 1;
		anum = anums[area];
		save_me();
	} else {
		anum = anums[area];
	}
	return anum;
}

string *query_anums(void) {
   return map_indices(anums);
}
