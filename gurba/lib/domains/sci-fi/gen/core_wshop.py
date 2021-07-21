import argparse

parser = argparse.ArgumentParser()
parser.add_argument('--name', help='npc label', required=True)
parser.add_argument('--start', help='start level of gear', required=True)
parser.add_argument('--end', help='end level of gear', required=True)

weapontypes = ["sword"]

syspath = "../monsters/"
domain = "../domain.h"

args = parser.parse_args()

mob_race = "robot"
mob_level = 40
mob_gender = "other"
mob_skill = str(int(mob_level) * 5)

npcfile = open(syspath + args.name + ".c", "w")

npcfile.write('inherit "/std/vendor";\n\n')
npcfile.write('#include "' + domain + '"\n\n')

npcfile.write('void setup(void) {\n')
npcfile.write('  set_name("Autobot");\n')

objects = []

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


npcfile.write('  set_short( "Autobot" );\n')
npcfile.write('  set_long( "This is a robot arm, it looks like it has seen some better days. It is attached to the ceiling. It might be leaking hyradulic fluid." );\n\n')

npcfile.write('  set_gender("other");\n')
npcfile.write('  set_race("robot");\n\n')
npcfile.write('  set_level(40);\n\n')
npcfile.write('  set_hit_skill("' + "combat/unarmed" + '");\n')
npcfile.write('  set_skill("' + "combat/unarmed" + '", ' + mob_skill + ');\n')
npcfile.write('  set_skill("' + "combat/defense" + '", ' + mob_skill + ');\n')
npcfile.write('  set_restock_delay(600);\n')
npcfile.write('  set_will_buy(0);\n')

for weapontype in weapontypes:
  for alvl in range(int(args.start), int(args.end)):
    npcfile.write('  add_item(DIR + "/objects/shop/weapon/' + weapontype + str(alvl) + '", 10);\n')

# end code here
npcfile.write('}\n')

npcfile.close
