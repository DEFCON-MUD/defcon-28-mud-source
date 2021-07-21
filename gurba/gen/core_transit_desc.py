import argparse

parser = argparse.ArgumentParser()
parser.add_argument('--name', help='quadrant name', required=True)
parser.add_argument('--north', help='north exit', required=False)
parser.add_argument('--west', help='west exit', required=False)
parser.add_argument('--south', help='south exit', required=False)
parser.add_argument('--east', help='east exit', required=False)

args = parser.parse_args()
longdesc = "This circular room is in the very center of a tiny dome that is a connector for all of the domes in the "
longdesc += args.name + " District.  Use any exit to be instantly transported via mass-transit tube to the listed "
longdesc += "destination."
longdesc += "\n\n"
longdesc += "%^CYAN%^"
longdesc += "+----------"
longdesc += "%^RED%^"
longdesc += "D I R E C T O R Y"
longdesc += "%^CYAN%^"
longdesc += "------------+"
longdesc += "\n"
longdesc += "%^CYAN%^|                                       |%^RESET%^\n"
if args.north is not None:
    longdesc += "%^CYAN%^|%^RESET%^    N - "
    longdesc += args.north
    longdesc += (" " * (30 - len(args.north)))
    longdesc += " %^CYAN%^|%^RESET%^\n"
if args.west is not None:
    longdesc += "%^CYAN%^|%^RESET%^    N - "
    longdesc += args.west
    longdesc += (" " * (30 - len(args.west)))
    longdesc += " %^CYAN%^|%^RESET%^\n"
if args.south is not None:
    longdesc += "%^CYAN%^|%^RESET%^    N - "
    longdesc += args.south
    longdesc += (" " * (30 - len(args.south)))
    longdesc += " %^CYAN%^|%^RESET%^\n"
if args.east is not None:
    longdesc += "%^CYAN%^|%^RESET%^    N - "
    longdesc += args.east
    longdesc += (" " * (30 - len(args.south)))
    longdesc += " %^CYAN%^|%^RESET%^\n"
longdesc += "%^CYAN%^|                                       |%^RESET%^\n"
longdesc += "%^CYAN%^+---------------------------------------+%^RESET%^\n"
print repr(longdesc)