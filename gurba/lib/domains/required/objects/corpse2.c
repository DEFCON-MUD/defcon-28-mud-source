inherit "/std/container";

static string orig_name;


void setup(void) { }

void create(void) {
   ::create();

   if (clone_num() != 0) {
      
   }
   set_id("corpse");
   set_short("A foul smelling corpse");
   set_long("It looks just as awful as it smells.");
}

void set_name(string name) {
   orig_name = name;
   set_short("The corpse of " + name);
}
