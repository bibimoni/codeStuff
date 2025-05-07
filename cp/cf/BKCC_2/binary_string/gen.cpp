#include "testlib.h"
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  
  int tt = opt<int>("t");
  int N = opt<int>("N");
  vector<int> part = rnd.partition(tt, N, 2);
  cout << tt << '\n';
  for (auto n : part) {
    cout << n << '\n';
    string s = rnd.next("[0-1]{" + to_string(n) + "}");
    println(s);
  }
}
