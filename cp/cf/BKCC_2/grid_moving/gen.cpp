#include "testlib.h"
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  
  int tt = opt<int>("t");
  int N = opt<int>("N");
  int MX = opt<int>("MX");
  vector<int> part = rnd.partition(tt, N, 2);
  cout << tt << '\n';
  for (auto n : part) {
    cout << n << '\n';
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      ans[i] = rnd.next(1, MX); 
    }
    println(ans);
  }

}
