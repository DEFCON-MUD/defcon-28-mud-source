# Open the file with read only permit
f = open('labyrinth_gen.txt', 'r')

lines = f.readlines()

for line in lines:
  name = line.rstrip().split(':')[0]
  exits = line.rstrip().split(':')[1].split(',')

  exitcode = str(" ")
  lexit = str("")

  name_x = name.split(',')[0]
  name_y = name.split(',')[1]
  name_z = name.split(',')[2]
  x = "x"
  y = "y"
  z = "z"

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

  print "python lab_p.py --area labyrinth --x " + name_x + " --y " + name_y + " --z " + name_z + " --name " + x + name_x + y + name_y + z + name_z + " " + str(lexit) 
