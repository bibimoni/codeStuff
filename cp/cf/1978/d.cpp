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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, c;
    cin >> n >> c;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    a[1] += c;
    vector<int> pre(n + 1, 0);
    for(int i = 1; i <= n; i++) {
      pre[i] = pre[i - 1] + a[i];
    }
    vector<int> mx(n + 2, 0);
    for(int i = n; i >= 1; i--) {
      mx[i] = max(a[i], mx[i + 1]);
    }
    vector<int> ans(n + 1, 0);
    bool only = false;
    for(int i = 1; i <= n; i++) {
      if(a[i] == mx[1] && !only) {
        only = true;
        continue;
      }
      ans[i] = i - 1;
      if(pre[i] < mx[i + 1]) {
        ans[i] += 1;
      }
    }
    for(int i = 1; i <= n; i++) {
      cout << ans[i] << " \n"[i == n];
    }
  }
}

