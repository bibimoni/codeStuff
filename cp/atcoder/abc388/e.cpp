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
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  deque<int> dq;
  for (int i = 1; i <= n / 2; i++) {
    dq.push_back(a[i]);
  }
  for (int i = (n / 2) + 1; i <= n; i++) {
    if (dq.front() * 2 <= a[i]) {
      dq.pop_front();
      ans += 1;
    }
  }
  cout << ans;
}


