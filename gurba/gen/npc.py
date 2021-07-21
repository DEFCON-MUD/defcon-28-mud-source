import argparse

parser = argparse.ArgumentParser()
parser.add_argument('--file', help='npc file', required=True)

parser.add_argument('--name', help='npc name', required=True)
parser.add_argument('--domain', help='path to domain include ../domain.h', required=True)
parser.add_argument('--syspath', help='system path to drop files', required=True)
parser.add_argument('--adj', help='adjective', required=False)
parser.add_argument('--adj2', help='adjective', required=False)
parser.add_argument('--adj3', help='adjective', required=False)
parser.add_argument('--adj4', help='adjective', required=False)
parser.add_argument('--short', help='short desc', required=True)
parser.add_argument('--scolor', help='short desc color', required=False)
parser.add_argument('--long', help='long desc', required=True)
parser.add_argument('--lcolor', help='long desc color', required=False)
parser.add_argument('--race', help='race', required=True)
parser.add_argument('--gender', help='male/female/unknown', required=True)
parser.add_argument('--level', help='level', required=True)
parser.add_argument('--primary', help='primary skill, eg: "combat/unarmed"', required=True)
parser.add_argument('--plvl', help='primary skill level, eg: 50', required=True)
parser.add_argument('--skill2', help='secodary skill, eg: combat/defense"', required=False)
parser.add_argument('--slvl2', help='secondary skill level, eg: 100', required=False)
parser.add_argument('--skill3', help='secodary skill, eg: combat/defense"', required=False)
parser.add_argument('--slvl3', help='secondary skill level, eg: 100', required=False)
parser.add_argument('--skill4', help='secodary skill, eg: combat/defense"', required=False)
parser.add_argument('--slvl4', help='secondary skill level, eg: 100', required=False)
parser.add_argument('--skill5', help='secodary skill, eg: combat/defense"', required=False)
parser.add_argument('--slvl5', help='secondary skill level, eg: 100', required=False)

args = parser.parse_args()

npcfile = open(args.syspath + args.file + ".c", "w")

npcfile.write('inherit "/std/monster";\n\n')
npcfile.write('inherit "' + args.domain + '");\n\n')

npcfile.write('void setup( void ) {\n')
npcfile.write('  set_name("' + args.name + '");\n')
if args.adj is not None:
    npcfile.write('  add_adj("' + args.adj + '");\n')
if args.adj2 is not None:
    npcfile.write('  add_adj("' + args.adj2 + '");\n')
if args.adj3 is not None:
    npcfile.write('  add_adj("' + args.adj3 + '");\n')
if args.adj4 is not None:
    npcfile.write('  add_adj("' + args.adj4 + '");\n')
if args.scolor is None:
    npcfile.write('  set_short( "' + args.short + '" );\n')
else:
    npcfile.write('  set_short( "%^' + args.scolor + '%^' + args.short + '%^RESET%^" );\n')
if args.lcolor is None:
    npcfile.write('  set_long( "' + args.long + '" );\n\n')
else:
    npcfile.write('  set_long( "%^' + args.lcolor + '%^' + args.long + '%^RESET%^" );\n\n')
npcfile.write('  set_gender("' + args.gender + '");\n')
npcfile.write('  set_race("' + args.race + '");\n\n')
npcfile.write('  set_level(' + str(args.level) + ');\n\n')
npcfile.write('  set_hit_skill("' + args.primary + '");\n')
npcfile.write('  set_skill("' + args.primary + '", ' + str(args.plvl) + ');\n')

if args.skill2 is not None:
    if args.slvl2 is not None:
        npcfile.write('  set_skill("' + args.skill2 + '", ' + str(args.slvl2) + ');\n')
if args.skill3 is not None:
    if args.slvl3 is not None:
        npcfile.write('  set_skill("' + args.skill3 + '", ' + str(args.slvl3) + ');\n')
if args.skill4 is not None:
    if args.slvl4 is not None:
        npcfile.write('  set_skill("' + args.skill4 + '", ' + str(args.slvl4) + ');\n')
if args.skill5 is not None:
    if args.slvl5 is not None:
        npcfile.write('  set_skill("' + args.skill5 + '", ' + str(args.slvl5) + ');\n')

# end code here
npcfile.write('}\n')

npcfile.close
