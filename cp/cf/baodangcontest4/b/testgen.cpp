/**
 * Author: distiled
 */
#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include "../testlib.h"
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  registerGen(argc, argv, 1);
  int t = opt<int>("t");
  int sub = opt<int>("sub");
  int sim = opt<int>("sim");
  int N;
  if (sub == 1)
    N = 200;
  else if (sub == 2) 
    N = 5000;
  else
    N = 5e5; 
  cout << t << '\n';
  auto d = rnd.partition(t, N);
  dbg(d, N);
  for(int i = 0; i < t; i++) {
    int n = d[i];
    cout << n << '\n';
    auto d1 = rnd.partition(rnd.next(1, max(1, n / sim)), n);
    // dbg(d1);
    string test = "";
    for(int j = 0; j < d1.size(); j++) {
      int sz = rnd.next(1, d1[j] / 2 + 1);
      int m = d1[j] / sz;
      string ms = to_string(m);
      int curr = 0;
      if(m > 0) {
          string a = rnd.next("[a-z]{" + ms + "," + ms + "}");
          // dbg(a, m, sz);
          for(int k = 0; k < sz; k++) {
            if(curr + m > d1[j]) {
              break;
            }
            curr += m;
            test += a;
          }
      }
      if(d1[j] - curr > 0) {
        ms = to_string(d1[j] - curr);
        string a = rnd.next("[a-z]{" + ms + "," + ms + "}");
        test += a;
      }
    }
    assert(test.size() == n);
    cout << test << '\n';
  }
}

