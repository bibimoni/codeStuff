// time-limit: 3000
/**
 * Author: distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
#define int int64_t 

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int la, ra, lb, rb;
    cin >> la >> ra >> lb >> rb;
    if (la > lb) {
      swap(la, lb);
      swap(ra, rb);
    }    
    const int n = 100;
    vector<int> mark(n + 5);
    for (int i = la; i <= ra; i++) {
      mark[i] += 1;
    }
    for (int i = lb; i <= rb; i++) {
      mark[i] += 1;
    }
    if (ra < lb) {
      cout << "1\n";
      continue;
    }
    int cnt = 0;
    bool isLeft = false, isRight = false;
    for (int i = 1; i <= n; i++) {
      if (mark[i] == 2) {
        cnt += 1;
      }
      if (mark[i] == 2 && mark[i - 1] == 1) {
        isLeft = true;
      }
      if (mark[i] == 2 && mark[i + 1] == 1) {
        isRight = true;
      }    
    }
    cout << cnt - 1 + int(isLeft) + int(isRight) << '\n';
  }
}


