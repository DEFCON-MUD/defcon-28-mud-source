import argparse
import random

floors = ['stone', 'jade', 'marble', 'obsidian', 'limestone', 'quartz', 'basalt']
walls = ['slime', 'blood', 'oil', 'mud', 'dust', 'liquid']
colors = ['red', 'green', 'purple', 'blue', 'orange', 'iridium']
mobs = ['dirtycow.c', 'heartbleed.c', 'ms17-010', 'rowhammer', 'ms08-067', 'wpad']
ldesc = "The floors and walls appear to be made of " + (
    random.choice(floors)) + " while the roof appears to be dripping some kind of " + (
            random.choice(colors)) + " liquid.  The floors and wall also appear to be covered in some kind of " + (
            random.choice(walls)) + "."

parser = argparse.ArgumentParser()
parser.add_argument('--name', help='room name', required=True)
parser.add_argument('--domain', help='path to domain include ../domain.h', required=True)
parser.add_argument('--syspath', help='system path to drop files', required=True)
parser.add_argument('--short', help='short desc', required=True)
parser.add_argument('--scolor', help='short desc color', required=False)
parser.add_argument('--dexits', help='exit description', required=False)
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

roomfile = open(args.syspath + args.name + ".c", "w")
print args.syspath + args.name + ".c"
coords = args.name.split('-')
x_coord = coords[0]
y_coord = coords[1]

roomfile.write('inherit "/std/room";\n\n')
roomfile.write('#include "' + args.domain + '"\n\n')

roomfile.write('void setup( void ) {\n')
roomfile.write('  add_area( "' + args.area + '" );\n')
if args.scolor is None:
    roomfile.write('  set_short( "' + args.short + '" );\n')
else:
    roomfile.write('  set_short( "%^' + args.scolor + '%^' + args.short + '%^RESET%^" );\n')

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

if exit_list:
    roomfile.write('\\n\\n' + str(args.dexits) + " ")
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
