// gen_rice_squares.cpp
// Generator for the "beautiful square" problem.
// Usage (example):
//   ./gen -T=10 -N=200 -Q=400 -seed=42 > input.txt
//
// Requires testlib.h in include path.

#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);

  int n = opt<int>("N", 1);
  int m = opt<int>("M", 2);
  long long max_a = opt<long long>("MA", 3);
  long long max_b = opt<long long>("MB", 4);
  int type = opt<int>("Typ", 5);
}
