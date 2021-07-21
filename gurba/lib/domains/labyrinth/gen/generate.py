from random import *
import random

genpath="/home/git/gurba/lib/domains/labyrinth/gen"
syspath = "/home/git/gurba/lib/domains/labyrinth/rooms"
mobpath="/home/git/gurba/lib/domains/labyrinth/npc"
roompath="/home/git/gurba/lib/domains/labyrinth/rooms"
incdir=""
area="labyrinth"

room_array = []
dimensions = ["10", "10"]

mob_array = ["coder","analyst","droid","politician", "agent", "salesdroid", "glorzo", "Gl0Rz0", "auditor", "dba", "monkey", "banker", "technician", "goon", "enforcer", "stoner", "teacher", "professor"]
room_mobs = []
level_range = [6, 14]

floors = ['stone', 'jade', 'marble', 'obsidian', 'limestone', 'quartz', 'basalt']
walls = ['slime', 'blood', 'oil', 'mud', 'dust', 'liquid']
colors = ['red', 'green', 'purple', 'blue', 'orange', 'iridium']

l_desc_option_list_1a = ['broad', 'narrow', 'wide', 'cramped']
l_desc_option_list_1b = ['corridor', 'hallway', 'tunnel']
l_desc_option_list_1c = ['red', 'green', 'purple', 'blue', 'orange', 'iridium']
l_desc_option_list_1d = ['gunk', 'sludge', 'muck', 'crud', 'crap', 'radioactive waste', 'crappy sales material', 'random junk evilmog thought up', 'glorzo', 'pile of put kevin back stickers', 'pile of GPU\'s that burned so bright they went radioactive']
l_desc_option_list_1e = ['area', 'hellhole', 'stink-pit', 'sty', 'dump', 'pit']
l_desc_option_list_1f = [1, 2, 3, 4, 5, 6, 7, 8]
s_desc_option = [1, 2, 3]


fh = open(genpath + '/labyrinth_gen.txt')

for line in fh:
  exits = line.rstrip().split(":")[1].split(",")
  tmp_roomname = line.rstrip().split(":")[0]
  coords = [ tmp_roomname.split(",")[0], tmp_roomname.split(",")[1], tmp_roomname.split(",")[2] ]
  roomname = coords[0] + "_" + coords[1] + "_" + coords[2]
  translated = []
  map_x = coords[0]
  map_y = coords[1]
  map_z = coords[2]
  for exit in exits:
    if exit == "w":
      translated.append(["west",str(int(map_x) - 1) + "_" + str(map_y) + "_" + str(map_z)])
    if exit == "e":
      translated.append(["east",str(int(map_x) + 1) + "_" + str(map_y) + "_" + str(map_z)])
    if exit == "n":
      translated.append(["north",str(map_x) + "_" + str(int(map_y) - 1) + "_" + str(map_z)])
    if exit == "s":
      translated.append(["south",str(map_x) + "_" + str(int(map_y) + 1) + "_" + str(map_z)])
    if exit == "nw":
      translated.append(["northwest",str(int(map_x) - 1) + "_" + str(int(map_y) - 1) + "_" + str(map_z)])
    if exit == "ne":
      translated.append(["northeast",str(int(map_x) + 1) + "_" + str(int(map_y) - 1) + "_" + str(map_z)])
    if exit == "sw":
      translated.append(["southwest",str(int(map_x) - 1) + "_" + str(int(map_y) + 1) + "_" + str(map_z)])
    if exit == "se":
      translated.append(["southeast",str(int(map_x) + 1) + "_" + str(int(map_y) + 1) + "_" + str(map_z)])
    if exit == "u":
      translated.append(["up",str(map_x) + "_" + str(map_y) + "_" + str(int(map_z) + 1)])
    if exit == "d":
      translated.append(["down",str(map_y) + "_" + str(map_y) + "_" + str(int(map_z) - 1)])
    room_array.append([roomname, translated])
  random.seed()
  random.seed()
  random.seed()
  mobname = random.choice(mob_array)
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
  random.seed()
  moblevel = randint(level_range[0], level_range[1])
  mobfile.write('   set_hit_skill("combat/unarmed");\n')
  mobfile.write('   set_skill("combat/unarmed", ' + str(20 * moblevel) + ');\n')
  mobfile.write('   set_skill("combat/defense", ' + str(20 * moblevel) + ');\n')
  mobfile.write('   set_level(' + str(moblevel) + ');\n')
  mobfile.write('}\n\n')
  mobfile.close()

for rn in room_array:
  roomname = rn[0]
  exit_array = rn[1]
  room_moblist = [s for s in room_mobs if roomname in s]
  if room_moblist:
    print (room_moblist)
  coords = roomname.split("_")
  map_x = coords[0]
  map_y = coords[1]
  map_z = coords[2]
  random.seed()
  rshort = random.choice(s_desc_option)
  if rshort == 1:
    s_desc = 'Labyrinth'
  if rshort == 2:
    s_desc = 'Hallway'
  if rshort == 3:
    s_desc = 'Passage'
  random.seed()
  l_option_1f = random.choice(l_desc_option_list_1f)
  if l_option_1f == 1:
    l_desc_option_f = 'The air is rather stagnant'
  if l_option_1f == 2:
    l_desc_option_f = 'Musty air that doesn\'t seem to have been ventilated for a while brushes up against you as you move around here'
  if l_option_1f == 3:
    l_desc_option_f = 'To add to that, the smell here isn\'t exactly perfumy either'
  if l_option_1f == 4:
    l_desc_option_f = 'It smells like a hacker convention in here'
  if l_option_1f == 5:
    l_desc_option_f = 'The smell is outright dreadful'
  if l_option_1f == 6:
    l_desc_option_f = 'It smells like a combination of diesel fuel, dirt and decay'
  if l_option_1f == 7:
    l_desc_option_f = 'The air smells like it hasn\'t been cycled in a while, you are getting dizzy'
  if l_option_1f == 8:
    l_desc_option_f = 'The smell.....that musty smell.....nothing else quite smells like that.....it smells like.......DEFCON'
  random.seed()
  ldesc = "This is a " + random.choice(l_desc_option_list_1a) + " "
  random.seed()
  ldesc += random.choice(l_desc_option_list_1b) + ", illuminated only by the "
  random.seed()
  ldesc += random.choice(l_desc_option_list_1c) + " glow of the "
  random.seed()
  ldesc += random.choice(l_desc_option_list_1d) + " in this "
  random.seed()
  ldesc += random.choice(l_desc_option_list_1e) + ". The walls and floors are covered with "
  random.seed()
  ldesc += random.choice(walls) + ". " + l_desc_option_f + ".%^RESET%^"
  random.seed()
  roomfile = open(roompath + "/" + roomname + ".c", "w")
  roomfile.write('inherit "/std/room";\n\n')
  roomfile.write('#include "../domain.h" \n\n')
  roomfile.write('void setup( void ) {\n\n')
  roomfile.write('  #include "area.h"\n')
  roomfile.write('  add_area("labyrinth");\n')
  roomfile.write('  set_domainname("labyrinth");\n')
  roomfile.write('  set_coords(({ ' + coords[0] + ', ' + coords[1] + ', ' + coords[2] + ' }));\n')
  roomfile.write('  set_dimensions(({ ' + dimensions[0] + ', ' + dimensions[1] + ' }));\n\n')
  roomfile.write('  set_short( "' + s_desc + '" );\n')
  roomfile.write('  set_long( "' + ldesc + '" );\n\n')
  if room_moblist:
    mobnum = 0
    mobcount = len(room_moblist)
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
      if exitcount == exitnum:
        roomfile.write('  "' + rexit[0] + '" : ' + 'DIR+"/rooms/' + rexit[1] + '.c"\n  ]) );\n\n}\n\n')
        roomfile.close()
      else:
        roomfile.write('  "' + rexit[0] + '" : ' + 'DIR+"/rooms/' + rexit[1] + '.c",\n')



