#!/bin/zsh
set -e
ROOT=/Users/distiled/codeStuff/cp/cf/pre-icpc-2026/contest/teams/gpt-5.6-sol
check() {
  local letter="$1" input="$2" expected="$3"
  g++-14 -std=c++17 -O2 "$ROOT/$letter.cpp" -o "/tmp/gpt-sol-$letter"
  local got
  got=$(print -r -- "$input" | "/tmp/gpt-sol-$letter")
  [[ "$got" == "$expected" ]] || { print -u2 "$letter failed: [$got] != [$expected]"; exit 1; }
}
check F $'9\ncity 1\nof 1\nshining 1\nstars 1\nare 2\nme 2\njust 1\nfor 1\nyou 1' $'city\nof\nshining\nstars\njust\nfor\nyou'
check D $'3\n9\n18\n27' $'La premiere joueuse gagne.\nLa deuxieme joueuse gagne.\nLa premiere joueuse gagne.'
check A $'7\n4 3 1 2 6 7 5' '4'
check G $'3\n4\n2 1 1 2\n4\n1 2 3 4\n5\n1 1 1 1 1' $'Yes\nNo\nYes'
check K $'4\n5 3\n1 4 2 3 5\n3 3\n10 20 30\n1 1\n7\n4 2\n5 1 1 5' $'3\n40\n7\n2'
check I $'4\n2 3\n15 15 15\n15 15 15\n3\n1 1\n1 2\n2 2\n3 3\n6 10 12\n5 10 5\n3 10 9\n2\n2 2\n1 2\n1 3\n5 6 5\n2\n1 2\n1 3\n1 1\n0\n0' $'1 0 0\n1 0\n0 0'
check M $'4\n3 1 1\n3 1 2\n4 0 1\n4 6 2' $'1 3 2\n2 1 3\n1 2 3 4\n-1'
print 'easy samples OK'
