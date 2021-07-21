import argparse

parser = argparse.ArgumentParser()
parser.add_argument('--name', help='room name', required=True)
parser.add_argument('--domain', help='path to domain include ../domain.h', required=True)
parser.add_argument('--syspath', help='system path to drop files', required=True)
parser.add_argument('--short', help='short desc', required=True)
parser.add_argument('--scolor', help='short desc color', required=False)
parser.add_argument('--long', help='long desc', required=True)
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
parser.add_argument('--item1', help='item1 name', required=False)
parser.add_argument('--item1desc', help='item1 desc', required=False)
parser.add_argument('--item2', help='item1 name', required=False)
parser.add_argument('--item2desc', help='item1 desc', required=False)
parser.add_argument('--item3', help='item1 name', required=False)
parser.add_argument('--item3desc', help='item1 desc', required=False)
parser.add_argument('--item4', help='item1 name', required=False)
parser.add_argument('--item4desc', help='item1 desc', required=False)
parser.add_argument('--obj1', help='path to obj1', required=False)
parser.add_argument('--obj2', help='path to obj2', required=False)
parser.add_argument('--obj3', help='path to obj3', required=False)
parser.add_argument('--obj4', help='path to obj4', required=False)

args = parser.parse_args()

roomfile = open(args.syspath + args.name + ".c", "w")
print args.syspath + args.name + ".c"

roomfile.write('inherit "/std/room";\n\n')
roomfile.write('#include "' + args.domain + '"\n\n')

roomfile.write('void setup( void ) {\n')
roomfile.write('  add_area( "' + args.area + '" );\n')
if args.scolor is None:
    roomfile.write('  set_short( "' + args.short + '" );\n')
else:
    roomfile.write('  set_short( "%^' + args.scolor + '%^' + args.short + '%^RESET%^" );\n')
if args.lcolor is None:
    roomfile.write('  set_long( "' + args.long + '" );\n\n')
else:
    roomfile.write('  set_long( "%^' + args.lcolor + '%^' + args.long + '%^RESET%^" );\n\n')

# item code here
if args.item1 is not None:
    if args.item1desc is not None:
        roomfile.write('  add_item("' + args.item1 + '", "' + args.item1desc + '");\n')
if args.item2 is not None:
    if args.item2desc is not None:
        roomfile.write('  add_item("' + args.item2 + '", "' + args.item2desc + '");\n')
if args.item3 is not None:
    if args.item3desc is not None:
        roomfile.write('  add_item("' + args.item3 + '", "' + args.item3desc + '");\n')
if args.item4 is not None:
    if args.item4desc is not None:
        roomfile.write('  add_item("' + args.item4 + '", "' + args.item4desc + '");\n')

# exits code here
exits = []
if args.north is not None:
    exits.append(["north", args.north])
if args.south is not None:
    exits.append(["south", args.south])
if args.east is not None:
    exits.append(["east", args.east])
if args.west is not None:
    exits.append(["west", args.west])
if args.northeast is not None:
    exits.append(["northeast", args.northeast])
if args.northwest is not None:
    exits.append(["northwest", args.northwest])
if args.southeast is not None:
    exits.append(["southeast", args.southeast])
if args.southwest is not None:
    exits.append(["southwest", args.southwest])
if args.up is not None:
    exits.append(["up", args.up])
if args.down is not None:
    exits.append(["down", args.down])

objects = []
if args.obj1 is not None:
    objects.append([args.obj1])
if args.obj2 is not None:
    objects.append([args.obj2])
if args.obj3 is not None:
    objects.append([args.obj3])
if args.obj4 is not None:
    objects.append([args.obj4])

if objects:
    roomfile.write('\n  set_objects( ([\n')
    objcount = len(objects)
    objnum = 0
    for roomobject in objects:
        objnum += 1
        if objcount == objnum:
          roomfile.write(' DIR+"/obj/' + roomobject[0] + '.c"\n')
        else:
          roomfile.write(' DIR+"/obj/' + roomobject[0] + '.c",\n')
    roomfile.write('  );\n\n')

if exits:
    roomfile.write(' set_exits( ([\n')
    exitcount = len(exits)
    exitnum = 0
    for roomexit in exits:
        exitnum += 1
        if exitcount == exitnum:
          roomfile.write('  "' + roomexit[0] + '" : ' + 'DIR+"/room/' + roomexit[1] + '.c"\n')
        else:
          roomfile.write('  "' + roomexit[0] + '" : ' + 'DIR+"/room/' + roomexit[1] + '.c",\n')

# end code here
roomfile.write('  ]) );\n')
roomfile.write('}\n')

roomfile.close
