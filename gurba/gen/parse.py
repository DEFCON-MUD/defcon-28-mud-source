# Open the file with read only permit
f = open('directions_gen.txt', 'r')

lines = f.readlines()

for line in lines:
  name = line.rstrip().split(':')[0]
  exits = line.rstrip().split(':')[1].split(',')

  exitcode = str(" ")
  lexit = str("")

  for roomexit in exits:
    if roomexit == 'nw':
      exitcode = "--northwest 1 "
    if roomexit == 'n':
      exitcode = "--north 1 "
    if roomexit == 'ne':
      exitcode = "--northeast 1 "
    if roomexit == 'w':
      exitcode = "--west 1 "
    if roomexit == 'e':
      exitcode = "--east 1 "
    if roomexit == 'sw':
      exitcode = "--southwest 1 "
    if roomexit == 's':
      exitcode = "--south 1 "
    if roomexit == 'se':
      exitcode = "--southeast 1 "
    lexit += exitcode

  print "python room_p.py --area sewer --name " + name + " " + str(lexit)
