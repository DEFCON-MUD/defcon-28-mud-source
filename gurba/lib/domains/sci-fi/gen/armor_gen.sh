mkdir -p ../objects/shop/armour/
for i in $(grep 'if args.type ==' core_armour.py | cut -d" " -f4 | cut -d'"' -f2); do
  for n in $(seq 1 20); do
    python core_armour.py --level $n --type $i    
  done
done
