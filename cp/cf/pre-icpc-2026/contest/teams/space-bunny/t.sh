#!/bin/bash
cd /Users/distiled/codeStuff/cp/cf/pre-icpc-2026/contest/teams/space-bunny
T=/tmp/sbt; mkdir -p $T
printf "4\n4 1 2 3\n" > $T/a1.txt
printf "4\n4 3 2 1\n" > $T/a2.txt
printf "7\n4 3 1 2 6 7 5\n" > $T/a3.txt
printf "3\n9\n18\n27\n" > $T/d1.txt
printf "9\ncity 1\nof 1\nshining 1\nstars 1\nare 2\nme 2\njust 1\nfor 1\nyou 1\n" > $T/f1.txt
printf "3\n4\n2 1 1 2\n4\n1 2 3 4\n5\n1 1 1 1 1\n" > $T/g1.txt
printf "4\n3 1 1\n3 1 2\n4 0 1\n4 6 2\n" > $T/m1.txt
printf "4\n4 3 1\n4 3 6\n5 5 10\n1 0 2\n" > $T/m2.txt
for f in A D F G M; do g++-14 -O2 -std=gnu++17 -o $T/$f.bin $f.cpp 2>/dev/null; done
echo "== A (expect 2,1,4)"; for i in 1 2 3; do $T/A.bin < $T/a$i.txt; done
echo "== D (expect premiere,deuxieme,premiere)"; $T/D.bin < $T/d1.txt
echo "== F"; $T/F.bin < $T/f1.txt
echo "== G (expect Yes,No,Yes)"; $T/G.bin < $T/g1.txt
echo "== M1 (expect '1 3 2','2 1 3','1 2 3 4',-1)"; $T/M.bin < $T/m1.txt
echo "== M2 (expect '1 4 3 2','4 1 2 3','3 2 4 5 1',-1)"; $T/M.bin < $T/m2.txt
