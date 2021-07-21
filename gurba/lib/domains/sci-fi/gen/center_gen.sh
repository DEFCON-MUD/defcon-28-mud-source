mkdir -p ../rooms/center_sw
touch ../rooms/center_sw/area.h
python core_room.py --area center_sw --name "x-10y-10z0" --short "Hallway" --long "This is a standard boring hallway, the floors are some sort of nondescript washable surface, the walls look like poorly painted drywall, its almost as if somebody slapped this together in a hurry."  --northeast 1 --anortheast transit --west 1 --south 1
python gen_room.py --area center_sw --name "x-20y-10z0" --custom hallway --west 1 --east 1
python core_room.py --area center_sw --name "x-30y-10z0" --short "Hallway" --long "This appears to be a hallway, there is a sign next to a door that goes south." --item1 sign --item1desc "This is a rusty old sign, it has a picture of broken armour on it" --east 1 --west 1 --south 1
python gen_room.py --area center_sw --name "x-40y-10z0" --custom "hallway" --south 1 --west 1 --east 1
python gen_room.py --area center_sw --name "x-50y-10z0" --custom "hallway" --west 1 --east 1 --south 1
python gen_room.py --area center_sw --name "x-60y-10z0" --custom "hallway" --west 1 --south 1 --east 1
python gen_room.py --area center_sw --name "x-70y-10z0" --custom "hallway"  --west 1 --south 1 --east 1
python gen_room.py --area center_sw --name "x-80y-10z0" --custom "hallway" --west 1 --east 1 --south 1
python core_room.py --area center_sw --name "x-90y-10z0" --short "Hallway" --long "This is a hallway, it connects the shops to the rest of the mass transit system." --northwest 1 --anorthwest transit --south 1 --east 1
python gen_room.py --area center_sw --name "x-10y-90z0" --custom "hallway" --north 1 --west 1 --southeast 1 --asoutheast transit
python gen_room.py --area center_sw --name "x-10y-80z0" --custom "hallway" --south 1 --north 1
python core_room.py --area center_sw --name "x-10y-70z0" --short "hALlWAy" --long "This is a hallway. The walls appear to be covered in fingerpaint while the floors look like they are covered in a mix of silly putty and crackers. A sign is on the wall." --item1 sign --item1desc "This is a paper sign written in crayon. It says '%^HMAGENTA%^Hu%^HGREEN%^ma%^HCYAN%^n%^RESET%^ %^GREEN%^Re%^RED%^%^YELLOW%^sou%^MAGENTA%^rc%^HRED%^es%^RESET%^'" --south 1 --north 1 --west 1
python gen_room.py --area center_sw --name "x-10y-60z0" --custom "hallway" --north 1 --west 1 --south 1
python gen_room.py --area center_sw --name "x-10y-50z0" --custom "hallway" --west 1 --north 1 --south 1
python gen_room.py --area center_sw --name "x-10y-40z0" --custom "hallway" --west 1 --south 1 --north 1
python gen_room.py --area center_sw --name "x-10y-30z0" --custom "hallway" --west 1 --north 1 --south 1
python gen_room.py --area center_sw --name "x-10y-20z0" --custom "hallway" --west 1 --north 1 --south 1 --awest center_sw_atrium
python core_room.py --area center_sw --name "x-20y-70z0" --short "Hallway" --long "Welcome to the HR department, unfortunately the last of them went crazy and left. The walls are covered in fingerpaint while the bare floors have paint splotches all over.\n\nThere is a sign on the wall written in crayon." --east 1 --hr 1
python gen_room.py --area center_sw --name "x-20y-60z0" --custom ashop --east 1 --mon1 abot_1_2
python gen_room.py --area center_sw --name "x-20y-50z0" --custom ashop --east 1 --mon1 abot_3_4
python gen_room.py --area center_sw --name "x-20y-40z0" --custom ashop --east 1 --mon1 abot_5_6
python gen_room.py --area center_sw --name "x-20y-30z0" --custom ashop --east 1 --mon1 abot_7_8
python gen_room.py --area center_sw --name "x-20y-90z0" --custom hallway --east 1 --north 1 --west 1
python gen_room.py --area center_sw --name "x-30y-90z0" --custom hallway --west 1 --north 1 --east 1
python gen_room.py --area center_sw --name "x-40y-90z0" --custom hallway --northwest 1 --north 1 --east 1
python gen_room.py --area center_sw --name "x-50y-80z0" --custom hallway --southeast 1 --north 1 --west 1
python gen_room.py --area center_sw --name "x-60y-80z0" --custom hallway --east 1 --northwest 1
python gen_room.py --area center_sw --name "x-70y-70z0" --custom hallway --southeast 1 --northwest 1
python gen_room.py --area center_sw --name "x-80y-60z0" --custom hallway --north 1 --southeast 1
python gen_room.py --area center_sw --name "x-80y-50z0" --custom hallway --south 1 --northwest 1
python gen_room.py --area center_sw --name "x-90y-40z0" --custom hallway --north 1 --southeast 1
python gen_room.py --area center_sw --name "x-90y-30z0" --custom hallway --north 1 --south 1 --east 1
python gen_room.py --area center_sw --name "x-90y-20z0" --custom hallway --north 1 --south 1
python gen_room.py --area center_sw --name "x-30y-20z0" --custom ashop --north 1 --mon1 abot_9_10
python gen_room.py --area center_sw --name "x-40y-20z0" --custom ashop --north 1 --mon1 abot_11_12
python gen_room.py --area center_sw --name "x-50y-20z0" --custom ashop --north 1 --mon1 abot_13_14
python gen_room.py --area center_sw --name "x-60y-20z0" --custom ashop --north 1 --mon1 abot_15_16
python gen_room.py --area center_sw --name "x-70y-20z0" --custom ashop --north 1 --mon1 abot_17_18
python gen_room.py --area center_sw --name "x-80y-20z0" --custom ashop --north 1 --mon1 abot_19_20
python gen_room.py --area center_sw --name "x-80y-30z0" --custom ashop --west 1 --mon1 wbot_1_20
python gen_room.py --area center_sw --name "x-50y-70z0" --custom mshop --south 1 --inherit "/std/evil/sketchymining" --action1func "do_list" --action1 "list" --action2func "do_upgrade" --action2 "upgrade" 
python gen_room.py --area center_sw --name "x-40y-80z0" --custom clinic --south 1 --inherit "/std/evil/clinic" --action1func "do_list" --action1 "list" --action2func "do_immune" --action2 "immune" --action3func "do_heal" --action3 "heal"
python gen_room.py --area center_sw --name "x-30y-80z0" --custom office --south 1
python gen_room.py --area center_sw --name "x-20y-80z0" --custom office --south 1
