import argparse

parser = argparse.ArgumentParser()
parser.add_argument('--label', help='npc label', required=False)
parser.add_argument('--level', help='level', required=True)
parser.add_argument('--type', help='type', required=True)

syspath = "../objects/shop/weapon/"
domain = "../../../domain.h"

args = parser.parse_args()

weapontype = args.type
weaponaction = "slash"
weaponskill = "combat/sharp/small"


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
  material = "iron-carbide"
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



weaponname = weapontype + args.level

weaponfile = open(syspath + weaponname + ".c", "w")

weaponfile.write('inherit "/std/weapon";\n\n')
weaponfile.write('#include "' + domain + '"\n\n')

weaponfile.write('void setup(void) {\n')
weaponfile.write('  set_id("' + material + ' ' + weapontype + '");\n')
weaponfile.write('  add_id("' + weapontype + '");\n')
weaponfile.write('  add_id("' + material + '");\n')
weaponfile.write('  add_id("' + material + ' ' + weapontype +'");\n')

if args.level:
    weaponfile.write('  set_value(' + str((int(args.level) * int(args.level)) * 200 ) + ');\n')
    weaponfile.write('  set_size(' + str(args.level) + ');\n')
    weaponfile.write('  set_weight(' + str(int(args.level) * 10) + ');\n')

if args.type:
    weaponfile.write('  set_weapon_action("' + weaponaction + '");\n')
    weaponfile.write('  set_weapon_skill("' + weaponskill + '");\n')

weaponfile.write('  set_short("A ' + material + ' ' + weapontype + '");\n')
weaponfile.write('  set_long("A ' + material + ' ' + weapontype + '");\n')
weaponfile.write('  set_min_damage(' + str(int(args.level)) + ');\n')
weaponfile.write('  set_max_damage(' + str(int(args.level) * 10) + ');\n')
weaponfile.write('  set_hit_bonus(' + str(int(args.level) * 2) + ');\n')


# end code here
weaponfile.write('}\n')

weaponfile.close
