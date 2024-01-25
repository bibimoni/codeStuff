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
#define int            long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    deque<int> dq;
    for(int i = 1; i <= n; i++) {
      int x; cin >> x;
      dq.push_back(x);
    }
    bool alice = false;
    int cnt = 1, a = dq.front(), b = 0, prev = a;
    dq.pop_front();
    while(dq.size()) {
      if(alice) {
        int curr = 0;
        while(dq.size() && curr <= prev) {
          curr += dq.front();
          dq.pop_front();
        }
        a += curr;
        prev = curr;
      }
      else {
        int curr = 0;
        while(dq.size() && curr <= prev) {
          curr += dq.back();
          dq.pop_back();
        }
        b += curr;
        prev = curr;
      }
      alice = !alice;
      cnt++;
    }
    cout << cnt << ' ' << a << ' ' << b << '\n';
  }
}


