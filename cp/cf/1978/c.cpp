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
    int n, k;
    cin >> n >> k;
    if(k & 1) {
      cout << "No\n";
      continue;
    }
    vector<int> ans(n + 1);
    iota(ans.begin(), ans.end(), 0ll);
    int l = 1, r = n;
    while(l < r) {
      if (k == 0)
        break;
      if(abs(ans[l] - ans[r]) * 2 <= k) {
        swap(ans[l], ans[r]);
        k -= abs(ans[l] - ans[r]) * 2;
        r--;
      }
      l++;
    }
    if(k != 0) {
      cout << "No\n";
      continue;
    }
    cout << "Yes\n";
    for(int i = 1; i <= n; i++) {
      cout << ans[i] << " \n"[i == n];
    }
  }
}

