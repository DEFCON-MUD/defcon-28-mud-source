titles = [
"SystemD Developer",
"consultant",
"consumer",
"analyst",
"senior analyst",
"operator",
"technician",
"engineer",
"nerd",
"pimply faced youth",
"bastard operator from hell",
"analyst",
"senior analyst",
"wizard",
"grey beard",
"hacker",
"guru",
"initiate of the church of wifi",
"pranker of the church of wifi",
"shenanigator of the church of wifi",
"UnHoly Knight of Trevor",
"team leader",
"section leader",
"manager",
"senior manager",
"director",
"senior director",
"managing director",
"senior managing director",
"red team operator",
"threat hunter"
]

counter = 0;
for title in titles:
  counter = counter + 1
  print "      case " + str(counter) + ":"
  print "        return \"the " + title + "\";"
  print "        break;"
