import argparse

parser = argparse.ArgumentParser()
parser.add_argument('--name', help='npc name', required=True)
parser.add_argument('--label', help='npc label', required=False)
parser.add_argument('--level', help='level', required=True)
parser.add_argument('--short', help='short desc', required=True)
parser.add_argument('--scolor', help='short desc color', required=False)
parser.add_argument('--long', help='long desc', required=True)
parser.add_argument('--lcolor', help='long desc color', required=False)
parser.add_argument('--gender', help='gender', required=True)
parser.add_argument('--aggro', help='sets aggressive', required=False)
parser.add_argument('--id1', help='additional id', required=False)
parser.add_argument('--id2', help='additional id', required=False)
parser.add_argument('--id3', help='additional id', required=False)
parser.add_argument('--id4', help='additional id', required=False)
parser.add_argument('--id5', help='additional id', required=False)
parser.add_argument('--id6', help='additional id', required=False)
parser.add_argument('--obj1', help='objects to hold', required=False)
parser.add_argument('--obj2', help='objects to hold', required=False)
parser.add_argument('--obj3', help='objects to hold', required=False)
parser.add_argument('--obj4', help='objects to hold', required=False)
parser.add_argument('--obj5', help='objects to hold', required=False)
parser.add_argument('--obj6', help='objects to hold', required=False)


syspath = "../monsters/"
domain = "../domain.h"

args = parser.parse_args()

print args.name
mob_race = "human"
mob_level = str(args.level)
mob_gender = str(args.level)
mob_skill = str(int(mob_level) * 5)

npcfile = open(syspath + args.name + ".c", "w")

npcfile.write('inherit "/std/monster";\n\n')
npcfile.write('#include "' + domain + '"\n\n')

npcfile.write('void setup(void) {\n')
if args.label is None:
    npcfile.write('  set_name("' + args.name + '");\n')
if args.label is not None:
    npcfile.write('  set_name("' + args.label + '");\n')
# npcfile.write('  add_adj("' + mob_race + '");\n')
if args.id1:
    npcfile.write('add_id("' + args.id1 + '");\n')
if args.id2:
    npcfile.write('add_id("' + args.id2 + '");\n')
if args.id3:
    npcfile.write('add_id("' + args.id3 + '");\n')
if args.id4:
    npcfile.write('add_id("' + args.id4 + '");\n')
if args.id5:
    npcfile.write('add_id("' + args.id5 + '");\n')
if args.id6:
    npcfile.write('add_id("' + args.id6 + '");\n')

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

if objects:
    npcfile.write('\n  set_objects( \n')

    objcount = len(objects)
    objnum = 0

    for monobject in objects:
        objnum += 1
        if objcount == objnum:
            npcfile.write(' DIR+"/objects/' + monobject[0] + '.c"\n')
        else:
            npcfile.write(' DIR+"/objects/' + monobject[0] + '.c", \n')
    npcfile.write(');\n')


if args.scolor is None:
    npcfile.write('  set_short( "' + args.short + '" );\n')
else:
    npcfile.write('  set_short( "%^' + args.scolor + '%^' + args.short + '%^RESET%^" );\n')

if args.lcolor is None:
    npcfile.write('  set_long( "' + args.long + '" );\n\n')
else:
    npcfile.write('  set_long( "%^' + args.lcolor + '%^' + args.long + '%^RESET%^" );\n\n')

npcfile.write('  set_gender("' + args.gender + '");\n')
npcfile.write('  set_race("' + mob_race + '");\n\n')
npcfile.write('  set_level(' + str(args.level) + ');\n\n')
npcfile.write('  set_hit_skill("' + "combat/unarmed" + '");\n')
npcfile.write('  set_skill("' + "combat/unarmed" + '", ' + mob_skill + ');\n')
npcfile.write('  set_skill("' + "combat/defense" + '", ' + mob_skill + ');\n')
if args.aggro is not None:
    npcfile.write('set_aggressive (1);\n')

# end code here
npcfile.write('}\n')

npcfile.close
