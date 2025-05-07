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
  int n, t;
  cin >> n >> t;
  string s;
  cin >> s;
  s = " " + s;
  vector<int> x(n + 1);
  deque<int> subs;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  sort(x.begin() + 1, x.end());
  int ans = 0;
  for (int i = n; i >= 1; i--) {
    if (s[i] == '1') {
      while(subs.size() && subs.back() - t > x[i] + t) {
        subs.pop_back();
      }            
      ans += subs.size();
    } else {
      subs.push_front(x[i]);
    }
  }
  cout << ans << '\n';
}


