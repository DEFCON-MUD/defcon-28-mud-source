import argparse
import random

syspath = "/Users/evilmog/git/gurba/lib/domains/sewer/rooms/"
domain = "../domain.h"

floors = ['stone', 'jade', 'marble', 'obsidian', 'limestone', 'quartz', 'basalt']
walls = ['slime', 'blood', 'oil', 'mud', 'dust', 'liquid']
colors = ['red', 'green', 'purple', 'blue', 'orange', 'iridium']
mobs = ["average_eel_6", "average_ferret_6", "average_lizard_6", "average_parrot_6", "average_rat_6", "average_snake_6",
        "mediocre_alligator_4", "mediocre_eel_4", "mediocre_ferret_4", "mediocre_lizard_4", "mediocre_parrot_4",
        "mediocre_snake_4", "meh_eel_3", "meh_ferret_3", "meh_mouse_3", "meh_parrot_3", "meh_rat_3", "meh_snake_3",
        "newbie_alligator_2", "newbie_eel_2", "newbie_ferret_2", "newbie_lizard_2", "newbie_rat_2", "newbie_snake_2",
        "newbie_worm_2", "strong_eel_7", "strong_ferret_7", "strong_lizard_7", "strong_mouse_7", "strong_snake_7",
        "strong_worm_7", "sub-average_eel_5", "sub-average_ferret_5", "sub-average_lizard_5", "sub-average_mouse_5",
        "sub-average_parrot_5", "sub-average_rat_5", "sub-average_worm_5", "uninitiated_alligator_1",
        "uninitiated_eel_1", "uninitiated_ferret_1", "uninitiated_lizard_1", "uninitiated_parrot_1",
        "uninitiated_rat_1", "uninitiated_snake_1"]

l_desc_option_list_1a = ['broad', 'narrow', 'wide', 'cramped']
l_desc_option_list_1b = ['corridor', 'hallway', 'tunnel']
l_desc_option_list_1c = ['redish', 'red', 'greenish', 'green', 'purple', 'orange', 'iridium']
l_desc_option_list_1d = ['sediment', 'muck', 'gunk']
l_desc_option_list_1e = ['area', 'hellhole', 'stink-pit']
l_desc_option_list_1f = [1, 2, 3, 4, 5]
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
print l_option_1f
ldesc = "This is a " + random.choice(l_desc_option_list_1a) + " " + random.choice(
    l_desc_option_list_1b) + ", illuminated only by the " + random.choice(
    l_desc_option_list_1c) + " glow of the " + random.choice(l_desc_option_list_1d) + " in this " + random.choice(
    l_desc_option_list_1e) + ". The walls and floors are covered with " + random.choice(
    walls) + ". " + l_desc_option_f + ".%^RESET%^"

parser = argparse.ArgumentParser()
parser.add_argument('--name', help='room name', required=True)
# parser.add_argument('--domain', help='path to domain include ../domain.h', required=True)
# parser.add_argument('--syspath', help='system path to drop files', required=True)
# parser.add_argument('--short', help='short desc', required=True)
parser.add_argument('--scolor', help='short desc color', required=False)
# parser.add_argument('--dexits', help='exit description', required=False)
parser.add_argument('--lcolor', help='long desc color', required=False)
parser.add_argument('--area', help='area', required=True)
parser.add_argument('--north', help='path to north exit', required=False)
parser.add_argument('--south', help='path to south exit', required=False)
parser.add_argument('--east', help='path to east exit', required=False)
parser.add_argument('--west', help='path to west exit', required=False)
parser.add_argument('--northeast', help='path to northeast exit', required=False)
parser.add_argument('--northwest', help='path to northwest exit', required=False)
parser.add_argument('--southeast', help='path to southeast exit', required=False)
parser.add_argument('--southwest', help='path to southwest exit', required=False)
parser.add_argument('--up', help='path to up exit', required=False)
parser.add_argument('--down', help='path to down exit', required=False)

args = parser.parse_args()

s_desc_option = [1, 2, 3]
s_desc_choice = random.choice(s_desc_option)
if s_desc_choice == 1:
    s_desc = 'Sewer Passage - ' + args.name
if s_desc_choice == 2:
    s_desc = 'Access Tunnel - ' + args.name
if s_desc_choice == 3:
    s_desc = 'Passage - ' + args.name

roomfile = open(syspath + args.name + ".c", "w")
print syspath + args.name + ".c"
coords = args.name.split('-')
x_coord = coords[0]
y_coord = coords[1]

roomfile.write('inherit "/std/room";\n\n')
roomfile.write('#include "' + domain + '"\n\n')

roomfile.write('void setup( void ) {\n')
roomfile.write('  add_area( "' + args.area + '" );\n')
if args.scolor is None:
    roomfile.write('  set_short( "' + s_desc + '" );\n')
else:
    roomfile.write('  set_short( "%^' + args.scolor + '%^' + s_desc + '%^RESET%^" );\n')

# exits code here
exits = []
exit_list = []

if args.north is not None:
    print int(coords[0]) - 1
    exits.append(["north", str(int(coords[0]) - 1) + "-" + coords[1]])
    exit_list.append(["north"])
if args.south is not None:
    exits.append(["south", str(int(coords[0]) + 1) + "-" + coords[1]])
    exit_list.append(["south"])
if args.east is not None:
    exits.append(["east", coords[0] + "-" + chr(ord(coords[1]) + 1)])
    exit_list.append(["east"])
if args.west is not None:
    exits.append(["west", coords[0] + "-" + chr(ord(coords[1]) - 1)])
    exit_list.append(["west"])
if args.northeast is not None:
    exits.append(["northeast", str(int(coords[0]) - 1) + "-" + chr(ord(coords[1]) + 1)])
    exit_list.append(["northeast"])
if args.northwest is not None:
    exits.append(["northwest", str(int(coords[0]) - 1) + "-" + chr(ord(coords[1]) - 1)])
    exit_list.append(["northwest"])
if args.southeast is not None:
    exits.append(["southeast", str(int(coords[0]) + 1) + "-" + chr(ord(coords[1]) + 1)])
    exit_list.append(["southeast"])
if args.southwest is not None:
    exits.append(["southwest", str(int(coords[0]) + 1) + "-" + chr(ord(coords[1]) - 1)])
    exit_list.append(["southwest"])
if args.up is not None:
    exits.append(["up", args.up])
    exit_list.append(["up"])
if args.down is not None:
    exits.append(["down", args.down])
    exit_list.append(["down"])

roomfile.write('set_objects( DIR+"/monsters/' + random.choice(mobs) + '.c");\n')

if exits:
    roomfile.write(' set_exits( ([\n')
    exitcount = len(exits)
    exitnum = 0
    for roomexit in exits:
        exitnum += 1
        if exitcount == exitnum:
          roomfile.write('  "' + roomexit[0] + '" : ' + 'DIR+"/rooms/' + roomexit[1] + '.c"\n')
        else:
          roomfile.write('  "' + roomexit[0] + '" : ' + 'DIR+"/rooms/' + roomexit[1] + '.c",\n')

roomfile.write('  ]) );\n')

if args.lcolor is None:
    roomfile.write('  set_long( "' + ldesc)
else:
    roomfile.write('  set_long( "%^' + args.lcolor + '%^' + ldesc)

dexit_array = ['The sewer continues to the', 'Tunnels can be found to the', 'The horror continues to the',
               'You may be able to find escape to the']

if exit_list:
    roomfile.write('\\n\\n' + random.choice(dexit_array) + " ")
    exitcountl = len(exit_list)
    exitl_num = 0
    for exit_l in exit_list:
        exitl_num += 1
        if exitl_num == exitcountl:
            if exitcountl == 1:
                roomfile.write(exit_l[0] + ".%^RESET%^\");\n")
            else:
                roomfile.write("and " + exit_l[0] + ".%^RESET%^\");\n")
        else:
            roomfile.write(exit_l[0] + ", ")

print exit_list

# end code here
roomfile.write('}\n')

roomfile.close
