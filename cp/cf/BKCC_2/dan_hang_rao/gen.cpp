#include "testlib.h"
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);

  int tt = opt<int>("t");
  int N = opt<int>("N");
  vector<int> part = rnd.partition(tt, N, 1);
  cout << tt << '\n';
  for (auto n : part) {
    cout << n << '\n';
  }
}
