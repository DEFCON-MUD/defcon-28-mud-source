import argparse
import random

parser = argparse.ArgumentParser()
parser.add_argument('--file', help='npc file', required=True)

syspath = "/Users/dustin.heywood1@ibm.com/git/gurba/lib/domains/sewer/monsters/"
domain = "../domain.h"

option_1b = ['rat', 'snake', 'mouse', 'ferret', 'alligator', 'eel', 'parrot', 'lizard', 'worm']
option_1c = [1, 2, 3, 4, 5, 6, 7]
option_1d = ['male', 'female', 'neuter']
option_1e = ['sewer', 'death', 'hacker', 'uggghhhhh']
option_1f = ['blood', 'gunk', 'oil', 'dirt', 'sewage']
option_1g = ['str', 'wis', 'con', 'dex', 'cha', 'int']

mob_race = random.choice(option_1b)
mob_level = str(random.choice(option_1c))
mob_gender = random.choice(option_1d)
mob_skill = str(int(mob_level) * 5)

mob_sizes = ['uninitiated', 'newbie', 'meh', 'mediocre', 'sub-average', 'average', 'strong']
mob_size = mob_sizes[int(mob_level) - 1]

mob_name = mob_size + " " + mob_race

npcfile = open(syspath + mob_size + "_" + mob_race + "_" + mob_level + ".c", "w")

npcfile.write('inherit "/std/monster";\n\n')
npcfile.write('#include "' + domain + '"\n\n')

npcfile.write('void setup(void) {\n')
npcfile.write('  set_name("' + mob_race + '");\n')
npcfile.write('  add_adj("' + mob_size + '");\n')
npcfile.write('  add_adj("' + mob_race + '");\n')

npcfile.write('  set_short( "' + mob_name + '" );\n')
npcfile.write('  set_long( "Before you stands a ' + mob_name + '. It smells like ' + random.choice(
    option_1e) + ' and appears to be covered in ' + random.choice(option_1f) + '." );\n\n')

npcfile.write('  set_gender("' + mob_gender + '");\n')
npcfile.write('  set_race("' + mob_race + '");\n\n')
npcfile.write('  set_level(' + str(mob_level) + ');\n\n')
npcfile.write('  set_hit_skill("' + "combat/unarmed" + '");\n')
npcfile.write('  set_skill("' + "combat/unarmed" + '", ' + mob_skill + ');\n')
npcfile.write('  set_skill("' + "combat/defense" + '", ' + mob_skill + ');\n')
npcfile.write('  add_object(DIR + "/objects/' + random.choice(option_1g) + '_potion.c", 9);\n')

# end code here
npcfile.write('}\n')

npcfile.close
