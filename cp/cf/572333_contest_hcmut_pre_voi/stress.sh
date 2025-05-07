# b__Generator (generator) || b__Good (brute) || b (solution)
g++-14 b__Generator.cpp -std=gnu++23 -o b__Generator
echo compiled gen

g++-14 b.cpp -std=gnu++23 -o b
echo compiled ans

g++-14 b__Good.cpp -std=gnu++23 -o b__Good
echo compiled good

for((i=1;i<=100;i++)); do
  ./b__Generator > in_tmp
  (./b < in_tmp) > out
  (./b__Good < in_tmp) > ans
  if diff ans out; 
    then 
      echo pass $i
    else 
      echo failed test:
      sed -n 'p' in_tmp
      break 
  fi
done
