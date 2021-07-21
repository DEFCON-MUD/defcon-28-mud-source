inherit "/std/monster";
void setup(void) {
   set_name("city manager");
   add_adj("manager");
   add_adj("perky");
   set_short("Local Bureaucrat");
   set_long("The one who's really in charge, but no one knows it");
   set_gender( "female" );
   set_race("elf");
   set_level(3);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 50);
   set_skill("combat/defense", 100);
}
