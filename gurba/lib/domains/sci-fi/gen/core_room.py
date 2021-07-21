import argparse

parser = argparse.ArgumentParser()
parser.add_argument('--name', help='room name', required=True)
parser.add_argument('--short', help='short desc', required=True)
parser.add_argument('--scolor', help='short desc color', required=False)
parser.add_argument('--long', help='long desc', required=True)
parser.add_argument('--lcolor', help='long desc color', required=False)
parser.add_argument('--area', help='area', required=False)
parser.add_argument('--north', help='units for north exit', required=False)
parser.add_argument('--anorth', help='area for north exit', required=False)
parser.add_argument('--south', help='units south exit', required=False)
parser.add_argument('--asouth', help='area for south exit', required=False)
parser.add_argument('--east', help='units for east exit', required=False)
parser.add_argument('--aeast', help='area for east exit', required=False)
parser.add_argument('--west', help='units for west exit', required=False)
parser.add_argument('--awest', help='area for west exit', required=False)
parser.add_argument('--northeast', help='units for northeast exit', required=False)
parser.add_argument('--anortheast', help='area for northeast exit', required=False)
parser.add_argument('--northwest', help='units for northwest exit', required=False)
parser.add_argument('--anorthwest', help='area for northwest exit', required=False)
parser.add_argument('--southeast', help='units for southeast exit', required=False)
parser.add_argument('--asoutheast', help='area for southeast exit', required=False)
parser.add_argument('--southwest', help='units for southwest exit', required=False)
parser.add_argument('--asouthwest', help='area for southwest exit', required=False)
parser.add_argument('--up', help='units for up exit', required=False)
parser.add_argument('--aup', help='area for up exit', required=False)
parser.add_argument('--down', help='units for down exit', required=False)
parser.add_argument('--adown', help='area for down exit', required=False)
parser.add_argument('--hnorth', help='hidden path to north exit', required=False)
parser.add_argument('--hsouth', help='hidden path to south exit', required=False)
parser.add_argument('--heast', help='hidden path to east exit', required=False)
parser.add_argument('--hwest', help='hidden path to west exit', required=False)
parser.add_argument('--hnortheast', help='hidden path to northeast exit', required=False)
parser.add_argument('--hnorthwest', help='hidden path to northwest exit', required=False)
parser.add_argument('--hsoutheast', help='hidden path to southeast exit', required=False)
parser.add_argument('--hsouthwest', help='hidden path to southwest exit', required=False)
parser.add_argument('--hup', help='hidden path to up exit', required=False)
parser.add_argument('--hdown', help='hidden path to down exit', required=False)
parser.add_argument('--panel', help='hidden path to panel', required=False)
parser.add_argument('--vent', help='hidden path to vent', required=False)
parser.add_argument('--pipe', help='hidden path to pipe', required=False)
parser.add_argument('--hole', help='hidden path to hole', required=False)
parser.add_argument('--pushwall', help='push wall exit', required=False)

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
parser.add_argument('--obj5', help='path to obj5', required=False)
parser.add_argument('--obj6', help='path to obj6', required=False)

parser.add_argument('--mon1', help='path to monster 1', required=False)
parser.add_argument('--mon2', help='path to monster 2', required=False)
parser.add_argument('--mon3', help='path to monster 3', required=False)
parser.add_argument('--mon4', help='path to monster 4', required=False)
parser.add_argument('--mon5', help='path to monster 5', required=False)
parser.add_argument('--mon6', help='path to monster 6', required=False)
parser.add_argument('--mon7', help='path to monster 7', required=False)
parser.add_argument('--mon8', help='path to monster 8', required=False)
parser.add_argument('--mon9', help='path to monster 9', required=False)
parser.add_argument('--mon10', help='path to monster 10', required=False)
parser.add_argument('--mon11', help='path to monster 11', required=False)
parser.add_argument('--mon12', help='path to monster 12', required=False)

parser.add_argument('--door', help='door exit', required=False)
parser.add_argument('--doorkey', help='key to open door', required=False)
parser.add_argument('--doorlocked', help='set to 1 to lock door', required=False)

parser.add_argument('--hr', help='set to 1 to enable advancement functions', required=False)

args = parser.parse_args()

coords = args.name.replace("x", "").replace("y", ",").replace("z", ",").split(",")
x_coord = coords[0]
y_coord = coords[1]
z_coord = coords[2]
x_int = int(coords[0])
y_int = int(coords[1])
z_int = int(coords[2])

print args.name

if args.area is None:
    args.area = "core"

syspath = "../rooms/"
roomfile = open(syspath + args.area + "/" + args.name + ".c", "w")
# print args.syspath + args.name + ".c"


roomfile.write('inherit "/std/room";\n')
if args.hr:
  roomfile.write('inherit "/std/evil/advance";\n')
roomfile.write('#include "../../domain.h" \n')



roomfile.write('\nvoid setup( void ) {\n')
roomfile.write('  #include "area.h"\n\n')
roomfile.write('  set_property("x", ' + x_coord + ');\n')
roomfile.write('  set_property("y", ' + y_coord + ');\n')
roomfile.write('  set_property("z", ' + z_coord + ');\n')

if args.hr:
    roomfile.write('\n  add_action("do_advance", "advance");\n')
    roomfile.write('  add_action("do_quest", "claim");\n')
    roomfile.write('  add_action("do_quests", "quests");\n')
    roomfile.write('  add_item("sign", do_hrsign());\n')
    roomfile.write('  add_action("do_recast", "recast");\n\n')
if args.doorlocked:
    roomfile.write('  door_closed = 1;\n  locked = 1;\n')
if args.doorkey:
    roomfile.write('  key = "' + args.doorkey + '";\n')
roomfile.write('  add_area( "' + args.area + '" );\n')
if args.door:
    roomfile.write('  add_block("'+args.door+'");')
if args.scolor is None:
    roomfile.write('\n  set_short( "' + args.short + '" );\n')
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
hexits = []


if args.north is not None:
    new_yint = y_int + int(int(args.north) * 10)
    if args.anorth is not None:
        exits.append(["north", args.anorth + "/x" + x_coord + "y" + str(new_yint) + "z" + z_coord])
    else:
        exits.append(["north", args.area + "/x" + x_coord + "y" + str(new_yint) + "z" + z_coord])
if args.south is not None:
    new_yint = y_int - int(int(args.south) * 10)
    if args.asouth is not None:
        exits.append(["south", args.asouth + "/x" + x_coord + "y" + str(new_yint) + "z" + z_coord])
    else:
        exits.append(["south", args.area + "/x" + x_coord + "y" + str(new_yint) + "z" + z_coord])
if args.east is not None:
    new_xint = x_int + int(int(args.east) * 10)
    if args.aeast is not None:
        exits.append(["east", args.aeast + "/x" + str(new_xint) + "y" + y_coord + "z" + z_coord])
    else:
        exits.append(["east", args.area + "/x" + str(new_xint) + "y" + y_coord + "z" + z_coord])
if args.west is not None:
    new_xint = x_int - int(int(args.west) * 10)
    if args.awest is not None:
        exits.append(["west", args.awest + "/x" + str(new_xint) + "y" + y_coord + "z" + z_coord])
    else:
        exits.append(["west", args.area + "/x" + str(new_xint) + "y" + y_coord + "z" + z_coord])
if args.northeast is not None:
    new_yint = y_int + int(int(args.northeast) * 10)
    new_xint = x_int + int(int(args.northeast) * 10)
    if args.anortheast is not None:
        exits.append(["northeast", args.anortheast + "/x" + str(new_xint) + "y" + str(new_yint) + "z" + z_coord])
    else:
        exits.append(["northeast", args.area + "/x" + str(new_xint) + "y" + str(new_yint) + "z" + z_coord])
if args.northwest is not None:
    new_yint = y_int + int(int(args.northwest) * 10)
    new_xint = x_int - int(int(args.northwest) * 10)
    if args.anorthwest is not None:
        exits.append(["northwest", args.anorthwest + "/x" + str(new_xint) + "y" + str(new_yint) + "z" + z_coord])
    else:
        exits.append(["northwest", args.area + "/x" + str(new_xint) + "y" + str(new_yint) + "z" + z_coord])
if args.southeast is not None:
    new_yint = y_int - int(int(args.southeast) * 10)
    new_xint = x_int + int(int(args.southeast) * 10)
    if args.asoutheast is not None:
        exits.append(["southeast", args.asoutheast + "/x" + str(new_xint) + "y" + str(new_yint) + "z" + z_coord])
    else:
        exits.append(["southeast", args.area + "/x" + str(new_xint) + "y" + str(new_yint) + "z" + z_coord])
if args.southwest is not None:
    new_yint = y_int - int(int(args.southwest) * 10)
    new_xint = x_int - int(int(args.southwest) * 10)
    if args.asouthwest is not None:
        exits.append(["southwest", args.asouthwest + "/x" + str(new_xint) + "y" + str(new_yint) + "z" + z_coord])
    else:
        exits.append(["southwest", args.area + "/x" + str(new_xint) + "y" + str(new_yint) + "z" + z_coord])
if args.up is not None:
    new_zint = z_int + int(int(args.up) * 10)
    if args.aup is not None:
        exits.append(["up", args.aup + "/x" + x_coord + "y" + y_coord + "z" + str(new_zint)])
    else:
        exits.append(["up", args.area + "/x" + x_coord + "y" + y_coord + "z" + str(new_zint)])
if args.down is not None:
    new_zint = z_int - int(int(args.down) * 10)
    if args.adown is not None:
        exits.append(["down", args.adown + "/x" + x_coord + "y" + y_coord + "z" + str(new_zint)])
    else:
        exits.append(["down", args.area + "/x" + x_coord + "y" + y_coord + "z" + str(new_zint)])

# hidden exits
if args.hnorth is not None:
    new_yint = y_int + int(int(args.hnorth) * 10)
    hexits.append(["north", args.area + "/x" + x_coord + "y" + str(new_yint) + "z" + z_coord])
if args.hsouth is not None:
    new_yint = y_int - int(int(args.hsouth) * 10)
    hexits.append(["south", args.area + "/x" + x_coord + "y" + str(new_yint) + "z" + z_coord])
if args.heast is not None:
    new_xint = x_int + int(int(args.heast) * 10)
    hexits.append(["east", args.area + "/x" + str(new_xint) + "y" + y_coord + "z" + z_coord])
if args.hwest is not None:
    new_xint = x_int - int(int(args.hwest) * 10)
    hexits.append(["west", args.area + "/x" + str(new_xint) + "y" + y_coord + "z" + z_coord])
if args.hnortheast is not None:
    new_yint = y_int + int(int(args.hnortheast) * 10)
    new_xint = x_int + int(int(args.hnortheast) * 10)
    hexits.append(["northeast", args.area + "/x" + str(new_xint) + "y" + str(new_yint) + "z" + z_coord])
if args.hnorthwest is not None:
    new_yint = y_int + int(int(args.hnorthwest) * 10)
    new_xint = x_int - int(int(args.hnorthwest) * 10)
    hexits.append(["northwest", args.area + "/x" + str(new_xint) + "y" + str(new_yint) + "z" + z_coord])
if args.hsoutheast is not None:
    new_yint = y_int - int(int(args.hsoutheast) * 10)
    new_xint = x_int + int(int(args.hsoutheast) * 10)
    hexits.append(["southeast", args.area + "/x" + str(new_xint) + "y" + str(new_yint) + "z" + z_coord])
if args.hsouthwest is not None:
    new_yint = y_int - int(int(args.hsouthwest) * 10)
    new_xint = x_int - int(int(args.hsouthwest) * 10)
    hexits.append(["southwest", args.area + "/x" + str(new_xint) + "y" + str(new_yint) + "z" + z_coord])
if args.hup is not None:
    new_zint = z_int + int(int(args.hup) * 10)
    hexits.append(["up", args.area + "/x" + x_coord + "y" + y_coord + "z" + str(new_zint)])
if args.hdown is not None:
    new_zint = z_int - int(int(args.hdown) * 10)
    hexits.append(["down", args.area + "/x" + x_coord + "y" + y_coord + "z" + str(new_zint)])
if args.panel is not None:
    hexits.append(["panel", args.area + "/" + args.panel])
if args.vent is not None:
    hexits.append(["vent", args.area + "/" + args.vent])
if args.pipe is not None:
    hexits.append(["pipe", args.area + "/" + args.pipe])
if args.hole is not None:
    hexits.append(["hole", args.area + "/" + args.hole])
if args.pushwall is not None:
    hexits.append(["push wall", args.area + "/" + args.pushwall])

objects = []
if args.obj1 is not None:
    objects.append([args.obj1])
if args.obj2 is not None:
    objects.append([args.obj2])
if args.obj3 is not None:
    objects.append([args.obj3])
if args.obj4 is not None:
    objects.append([args.obj4])
if args.obj5 is not None:
    objects.append([args.obj5])
if args.obj6 is not None:
    objects.append([args.obj6])


monsters = []
if args.mon1 is not None:
    monsters.append([args.mon1])
if args.mon2 is not None:
    monsters.append([args.mon2])
if args.mon3 is not None:
    monsters.append([args.mon3])
if args.mon4 is not None:
    monsters.append([args.mon4])
if args.mon5 is not None:
    monsters.append([args.mon5])
if args.mon6 is not None:
    monsters.append([args.mon6])
if args.mon7 is not None:
    monsters.append([args.mon7])
if args.mon8 is not None:
    monsters.append([args.mon8])
if args.mon9 is not None:
    monsters.append([args.mon9])
if args.mon10 is not None:
    monsters.append([args.mon10])
if args.mon11 is not None:
    monsters.append([args.mon11])
if args.mon12 is not None:
    monsters.append([args.mon12])

if objects or monsters:
    roomfile.write('\n  set_objects( \n')

    objcount = len(objects) + len(monsters)
    objnum = 0

    for roomobject in objects:
        objnum += 1
        if objcount == objnum:
            roomfile.write(' DIR+"/objects/' + roomobject[0] + '.c"\n')
        else:
            roomfile.write(' DIR+"/objects/' + roomobject[0] + '.c", \n')
    for monobject in monsters:
        objnum +=1
        if objcount == objnum:
            roomfile.write(' DIR+"/monsters/' + monobject[0] + '.c"\n')
        else:
            roomfile.write(' DIR+"/monsters/' + monobject[0] + '.c", \n')
    roomfile.write(');\n')

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

if hexits:
    roomfile.write(' set_hidden_exits( ([\n')
    exitcount = len(exits)
    exitnum = 0
    for roomexit in hexits:
        exitnum += 1
        if exitcount == exitnum:
            roomfile.write('  "' + roomexit[0] + '" : ' + 'DIR+"/rooms/' + roomexit[1] + '.c"\n')
        else:
            roomfile.write('  "' + roomexit[0] + '" : ' + 'DIR+"/rooms/' + roomexit[1] + '.c",\n')
    roomfile.write('  ]) );\n')

# end code here


roomfile.write('}\n')

roomfile.close
