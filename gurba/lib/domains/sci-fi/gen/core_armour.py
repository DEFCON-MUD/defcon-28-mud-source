import argparse

parser = argparse.ArgumentParser()
parser.add_argument('--label', help='npc label', required=False)
parser.add_argument('--level', help='level', required=True)
parser.add_argument('--type', help='type', required=True)


syspath = "../objects/shop/armour/"
domain = "../../../domain.h"

args = parser.parse_args()


# BEGIN TYPE Block
if args.type == "torso":
  armortype = "plate"
if args.type == "head":
  armortype = "helmet"
if args.type == "hands":
  armortype = "gloves"
if args.type == "finger":
  armortype = "ring"
if args.type == "feet":
  armortype = "boots"
if args.type == "arm":
  armortype = "guantlets"
if args.type == "neck":
  armortype = "gorget"
if args.type == "body":
  armortype = "armour"
if args.type == "legs":
  armortype = "bracers"
if args.type == "waist":
  armortype = "faulds"

# Begin Level Block
if args.level == "1":
  material = "bronze"
if args.level == "2":
  material = "iron"
if args.level == "3":
  material = "gold"
if args.level == "4":
  material = "lead"
if args.level == "5":
  material = "aluminum"
if args.level == "6":
  material = "tungsten"
if args.level == "7":
  material = "iron-Carbide"
if args.level == "8":
  material = "mithril"
if args.level == "9":
  material = "tungsten-carbide"
if args.level == "10":
  material = "mithril-titanium"
if args.level == "11":
  material = "aluminum-titanium"
if args.level == "12":
  material = "titanium-carbide"
if args.level == "13":
  material = "ubobtanium"
if args.level == "14":
  material = "aluminum-unobtainium"
if args.level == "15":
  material = "tungsten-unobtanium"
if args.level == "16":
  material = "titanium-unobtanium"
if args.level == "17":
  material = "mogium"
if args.level == "18":
  material = "mogium-titanium"
if args.level == "19":
  material = "tungsten-mogium"
if args.level == "20":
  material = "mogium-unobtanium"



armorname = armortype + args.level

armorfile = open(syspath + armorname + ".c", "w")

armorfile.write('inherit "/std/armor";\n\n')
armorfile.write('#include "' + domain + '"\n\n')

armorfile.write('void setup(void) {\n')
armorfile.write('  set_id("' + material + ' ' + armortype + '");\n')
armorfile.write('  add_id("' + material + '");\n')
armorfile.write('  add_id("armour");')
armorfile.write('  add_id("' + armortype + '");\n')

if args.level:
    armorfile.write('  set_ac(' + args.level + ');\n')
    armorfile.write('  set_value(' + str((int(args.level) * int(args.level)) * 200 ) + ');\n')
    armorfile.write('  set_size(' + str(args.level) + ');\n')
    armorfile.write('  set_weight(' + str(int(args.level) * 10) + ');\n')

if args.type:
    armorfile.write('  set_slot("' + args.type + '");\n')

armorfile.write('  set_short("A ' + material + ' ' + armortype + '");\n')
armorfile.write('  set_long("A ' + material + ' ' + armortype + '");\n')

# end code here
armorfile.write('}\n')

armorfile.close
