mkdir -p ../rooms/center_sw_atrium
touch ../rooms/center_sw_atrium/area.h
python gen_room.py --area center_sw_atrium --name "x-20y-20z0" --custom atrium --southwest 1 --east 1 --aeast center_sw
python gen_room.py --area center_sw_atrium --name "x-30y-30z0" --custom atrium --southwest 1 --south 1 --northeast 1
python gen_room.py --area center_sw_atrium --name "x-40y-40z0" --custom atrium --north 1 --northeast 1
python gen_room.py --area center_sw_atrium --name "x-30y-40z0" --custom atrium --north 1 --southwest 1 --south 1
python gen_room.py --area center_sw_atrium --name "x-30y-50z0" --custom atrium --south 1 --north 1
python gen_room.py --area center_sw_atrium --name "x-40y-50z0" --custom atrium --west 1 --northeast 1
python gen_room.py --area center_sw_atrium --name "x-40y-30z0" --custom atrium --west 1 --south 1
python gen_room.py --area center_sw_atrium --name "x-50y-30z0" --custom atrium --west 1 --east 1
python gen_room.py --area center_sw_atrium --name "x-50y-50z0" --custom atrium --east 1 --north 1 --southeast 1 --southwest 1
python gen_room.py --area center_sw_atrium --name "x-30y-60z0" --custom atrium --southwest 1 --north 1
python gen_room.py --area center_sw_atrium --name "x-40y-70z0" --custom atrium --northeast 1 --east 1
python gen_room.py --area center_sw_atrium --name "x-30y-70z0" --custom atrium --west 1
python gen_room.py --area center_sw_atrium --name "x-50y-40z0" --custom atrium --south 1
python gen_room.py --area center_sw_atrium --name "x-60y-60z0" --custom atrium --south 1 --northeast 1 --east 1
python gen_room.py --area center_sw_atrium --name "x-40y-60z0" --custom atrium --northwest 1 --west 1
python gen_room.py --area center_sw_atrium --name "x-50y-60z0" --custom atrium --west 1 --east 1
python gen_room.py --area center_sw_atrium --name "x-60y-70z0" --custom atrium --north 1 --northwest 1
python gen_room.py --area center_sw_atrium --name "x-70y-60z0" --custom atrium --north 1 --southeast 1
python gen_room.py --area center_sw_atrium --name "x-70y-50z0" --custom atrium --northwest 1 --east 1 --south 1
python gen_room.py --area center_sw_atrium --name "x-60y-50z0" --custom atrium --west 1
python gen_room.py --area center_sw_atrium --name "x-80y-40z0" --custom atrium --southeast 1 --northeast 1
python gen_room.py --area center_sw_atrium --name "x-70y-30z0" --custom atrium --southwest 1 --east 1
python gen_room.py --area center_sw_atrium --name "x-60y-30z0" --custom atrium --west 1 --east 1

