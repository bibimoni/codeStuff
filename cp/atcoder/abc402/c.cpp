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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(m);
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
      a[i].push_back(x);
    }
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<int> days(*max_element(b.begin(), b.end()) + 1);
  for (int i = 0; i < n; i++) {
    days[b[i]] = i;
  }
  vector<int> ans(n);
  for (int i = 0; i < m; i++) {
    int mx = 0;
    for (int x : a[i]) {
      mx = max(days[x], mx);
    }
    ans[mx] += 1;
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      ans[i] += ans[i - 1];
    }
    cout << ans[i] << '\n';
  }
}


