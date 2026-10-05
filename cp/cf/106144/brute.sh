g++-15 j__Generator.cpp -std=gnu++23 -o j__Generator
echo compiled gen

g++-15 j.cpp -std=gnu++23 -o j
echo compiled ans

g++-15 j__Good.cpp -std=gnu++23 -o j__Good
echo compiled good

for ((i=1;i<=100;i++)); do
    ./j__Generator > in_tmp
    (./j < in_tmp) > out
    (./j__Good < in_tmp) > ans
    if diff ans out;
        then 
            echo pass $i
        else
            echo failed test:
            sed -n 'p' in_tmp
            break
    fi
done
