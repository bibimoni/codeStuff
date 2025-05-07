/**
 * Author: distiled
 */
#include<iostream>
using namespace std;

#include "testlib.h"
#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
int main(int argc, char * argv[]) {
  #define int int64_t
  ios::sync_with_stdio(false); 
  cin.tie(0);
  registerGen(argc, argv, 1);
  
  int tt = opt<int>("tt");
  int Q = opt<int>("Q");
  int MX = opt<int>("MX");
  auto v = rnd.partition(tt, Q, 2ll);
  println(tt);
  for (int tc = 0; tc < tt; tc++) {
    int q = v[tc];
    println(q);
    vector<int> type{1, 2};
    while (type.size() < q) {
      type.push_back(rnd.next(1, 2));
    }
    int cnt = 0;
    shuffle(type.begin() + 2, type.end());
    for (int t : type) {
      if (cnt == 0) {
        t = 1;
      }
      if (t == 1) {
        auto [x, a] = pair<int, int>{rnd.next(1ll, MX), rnd.next(1ll, MX)};
        cnt += x;        
        cout << t << ' ' << x << ' ' << a << '\n';
      } else {
        int c = rnd.next(1ll, min(cnt, MX));
        cnt -= c;
        cout << t << ' ' << c << '\n';
      }
    }
  }
}
