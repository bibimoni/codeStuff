#!/bin/bash
cd /Users/distiled/codeStuff/cp/cf/pre-icpc-2026/contest/teams/space-bunny
T=/tmp/sbt; mkdir -p $T
cat > $T/k1.txt <<'EOF'
4
5 3
1 4 2 3 5
3 3
10 20 30
1 1
7
4 2
5 1 1 5
EOF
cat > $T/k2.txt <<'EOF'
2
6 1
9 3 8 1 10 2
5 4
8 2 7 1 9
EOF
cat > $T/h1.txt <<'EOF'
3
3 12
2 2
2 5
1 4 10
2 1
2 4
1 2 7
2 2
1 9 1
2 3
2 9
1 4 8
2 2
1 4
2 1
1 5 3
2 1
2 5
2 5
2 1
1 3 6
2 2
2 1
2 3
EOF
cat > $T/i1.txt <<'EOF'
4
2 3
15 15 15
15 15 15
3
1 1
1 2
2 2
3 3
6 10 12
5 10 5
3 10 9
2
2 2
1 2
1 3
5 6 5
2
1 2
1 3
1 1
0
0
EOF
cat > $T/i2.txt <<'EOF'
1
4 5
6 10 12 6 12
5 10 5 5 5
3 10 9 3 9
0 0 0 0 0
6
2 2
1 2
2 5
1 5
3 1
2 4
EOF
for f in K H I; do g++-14 -O2 -std=gnu++17 -o $T/$f.bin $f.cpp 2>&1 | grep -v Woverriding | grep -v '^ ' | head -5; done
echo "== K1 (expect 3 40 7 2)"; $T/K.bin < $T/k1.txt
echo "== K2 (expect 1 9)"; $T/K.bin < $T/k2.txt
echo "== H1"; $T/H.bin < $T/h1.txt
echo "== I1 (expect '1 0 0' / '1 0' / '0 0' / '')"; $T/I.bin < $T/i1.txt
echo "== I2 (expect 2 1 0 0 0 0)"; $T/I.bin < $T/i2.txt
