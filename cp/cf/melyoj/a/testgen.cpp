#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char ** argv) {
  registerGen(argc, argv, 1);
  int N = opt<int>("n");
  int t = opt<int>("t");
  vector<int> p = rnd.partition(t, N);
  for (int n : p) {
    cout << n << '\n';
    for (int i = 1; i <= n; i++) {
      cout << rnd.next(1,n) << " \n"[i==n];
    }
  }
}