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
  vector<int> h(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  vector<int> ans(n + 1);
  deque<int> dq;
  for (int i = n; i >= 1; i--) {
    ans[i] = dq.size();
    while (dq.size() && dq.front() < h[i]) {
      dq.pop_front();
    }
    dq.push_front(h[i]);
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " \n"[i == n];
  }
}


