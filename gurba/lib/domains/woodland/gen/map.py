from random import *

genpath="/home/git/gurba/lib/domains/woodland/gen"
roompath="/home/git/gurba/lib/domains/woodland/rooms"
mobpath="/home/git/gurba/lib/domains/woodland/npc"
incdir=""
area="woodland"

room_array = []
dimensions = ["12", "16"]
mob_array = ["squirrel", "rabbit", "beaver", "bear", "porcupine", "skunk", "chipmunk", "mouse", "raccoon", "chickadee", "wolf", "fox", "badger", "grouse", "mole", "unicorn", "coyote"]
room_mobs = []
level_range = [1, 4]

fh = open(genpath + '/exits')

seed(random())

for line in fh:
    exits = line.rstrip().split(":")[1].split(",")
    roomname = line.rstrip().split(":")[0]
    translated = []
    co_ords = roomname.split("_")
    map_x = co_ords[0]
    map_y = co_ords[1]
    for exit in exits:
      if exit == "w":
        translated.append(["west",str(int(map_x) - 1) + "_" + str(map_y)])
      if exit == "e":
        translated.append(["east",str(int(map_x) + 1) + "_" + str(map_y)])
      if exit == "n":
        translated.append(["north",str(map_x) + "_" + str(int(map_y) - 1)])
      if exit == "s":
        translated.append(["south",str(map_x) + "_" + str(int(map_y) + 1)])
      if exit == "nw":
        translated.append(["northwest",str(int(map_x) - 1) + "_" + str(int(map_y) - 1)])
      if exit == "ne":
        translated.append(["northeast",str(int(map_x) + 1) + "_" + str(int(map_y) - 1)])
      if exit == "sw":
        translated.append(["southwest",str(int(map_x) - 1) + "_" + str(int(map_y) + 1)])
      if exit == "se":
        translated.append(["southeast",str(int(map_x) + 1) + "_" + str(int(map_y) + 1)])
    room_array.append([roomname, translated])
    seed(randint(0, 16))
    seed(randint(0, 16))
    if randint(0, 2) == randint(0, 2):
      if len(mob_array) > 0:
        mobindex = randint(0, (len(mob_array) - 1))
        mobname = mob_array[mobindex]
        mob_array.remove(mobname)
        room_mobs.append([roomname, mobname])

fh.close()

mob_count = -1
for mob in room_mobs:
  mob_count = mob_count + 1
  gender=["male", "female"]
  mobfile = open(mobpath + "/" + mob[1] + ".c", "w")
  mobfile.write('inherit "/std/monster";\n')
  mobfile.write('#include "../domain.h" \n\n')
  mobfile.write('void setup( void ) {\n')
  mobfile.write('   set_name("' + mob[1] + '");\n')
  mobfile.write('   set_short("A ' + mob[1] + '");\n')
  mobfile.write('   set_long("A ' + mob[1] + '");\n')
  mobfile.write('   set_gender("' + gender[randint(0,1)] + '");\n')
  mobfile.write('   set_race("' + mob[1] + '");\n')
  seed(randint(0, 16))
  seed(randint(0, 16))
  moblevel = randint(level_range[0], level_range[1])
  mobfile.write('   set_hit_skill("combat/unarmed");\n')
  mobfile.write('   set_skill("combat/unarmed", ' + str(20 * moblevel) + ');\n')
  mobfile.write('   set_skill("combat/defense", ' + str(20 * moblevel) + ');\n')
  mobfile.write('   set_level(' + str(moblevel) + ');\n')
  mobfile.write('}\n\n')
  mobfile.write('void monster_died(void) {\n')
  mobfile.write('  object usr;\n')
  mobfile.write('  int *wlf;\n')
  mobfile.write('  int results;\n')
  mobfile.write('  usr = this_player();\n')
  mobfile.write('  if (usr->is_completed_quest("Woodland")) {\n')
  mobfile.write('    return;\n')
  mobfile.write('  }\n')
  mobfile.write('  wlf = usr->get_woodland_kills();\n')
  mobfile.write('  if(!wlf) {\n')
  mobfile.write('    wlf = (( { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ));\n')
  mobfile.write('  }\n')
  mobfile.write('  if(wlf[' + str(mob_count) + '] != 1) {\n')
  mobfile.write('    wlf[' + str(mob_count) + '] = 1;\n')
  mobfile.write('    results = wlf[0] + wlf[1] + wlf[2] + wlf[3] + wlf[4] + wlf[5] + wlf[6] + wlf[7] + wlf[8] + wlf[9] + wlf[10] + wlf[11] + wlf[12] + wlf[13] + wlf[14] + wlf[15] + wlf[16];\n')
  mobfile.write('    usr->set_woodland_kills(wlf);\n')
  mobfile.write('  }\n')
  mobfile.write('}')
  mobfile.close()


for rn in room_array:
  roomname = rn[0]
  exit_array = rn[1]
  room_moblist = [s for s in room_mobs if roomname in s]
  if room_moblist:
    print (room_moblist)
  coords = roomname.split("_")
  rshort = "Woodland"
  rlong = "This is sprawling woodland, trees can be seen everywhere while critters can be heard in the distance. "
  if room_moblist:
    rlong = rlong + "Animal prints can be seen on the ground."
  roomfile = open(roompath + "/" + roomname + ".c", "w")
  roomfile.write('inherit "/std/room";\n\n')
  roomfile.write('#include "../domain.h" \n\n')
  roomfile.write('void setup( void ) {\n\n')
  roomfile.write('  #include "area.h"\n')
  roomfile.write('  add_area("woodland");\n')
  roomfile.write('  set_domainname("%^GREEN%^Woodland %^RED%^Critter %^GREEN%^Christmas%^RESET%^");\n')
  roomfile.write('  set_coords(({ ' + coords[0] + ', ' + coords[1] + ' }));\n')
  roomfile.write('  set_dimensions(({ ' + dimensions[0] + ', ' + dimensions[1] + ' }));\n\n')
  # add room desc plus color code eventually
  roomfile.write('  set_short( "' + rshort + '" );\n')
  roomfile.write('  set_long( "' + rlong + '" );\n\n')

  if room_moblist:
    mobnum = 0
    mobcount = len(room_moblist)
    roomfile.write('  add_item("prints", "animal prints, perhaps you should %^MAGENTA%^search%^RESET%^here");')
    roomfile.write('  set_objects(\n')
    for mob in room_moblist:
      mobnum += 1
      if mobcount == mobnum:
        roomfile.write('    DIR+"/npc/' + mob[1] + '.c"\n')
      else:
        roomfile.write('    DIR+"/npc/' + mob[1] + '.c",\n')
    roomfile.write('  );\n')

  if exit_array:
    roomfile.write(' set_exits( ([\n')
    exitcount = len(exit_array)
    exitnum = 0
    for rexit in exit_array:
      exitnum += 1
    #  print roomname + " " + rexit[0] + " " + rexit[1]
      if exitcount == exitnum:
        roomfile.write('  "' + rexit[0] + '" : ' + 'DIR+"/rooms/' + rexit[1] + '.c"\n')
      else:
        roomfile.write('  "' + rexit[0] + '" : ' + 'DIR+"/rooms/' + rexit[1] + '.c",\n')
    roomfile.write('  ]) );\n\n')

    # end code here
  roomfile.write('}\n\n')
    # do search code to find mob
  if room_moblist:
    roomfile.write('int do_search(void) {\n')
    roomfile.write('   this_environment()->setup();')
    roomfile.write('   write("An animal appears out of the woodwork");')
    roomfile.write('   return 1;\n}\n')
    roomfile.close

