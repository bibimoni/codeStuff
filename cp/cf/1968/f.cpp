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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), pre(n + 1, 0);
    map<int, vector<int>> f;
    f[0].push_back(0);
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      pre[i] = pre[i - 1] ^ a[i];
      f[pre[i]].push_back(i);
    }
    while(q--) {
      int l, r;
      cin >> l >> r;
      if(pre[l - 1] == pre[r]) {
        cout << "Yes\n";
      }
      else {
        int rt = *(upper_bound(f[pre[l - 1]].begin(), f[pre[l - 1]].end(), r) - 1);
        int lt = *(lower_bound(f[pre[r]].begin(), f[pre[r]].end(), l));
        if(l <= lt && lt < r && lt < rt && rt <= r)
          cout << "Yes\n";
        else 
          cout << "No\n";
      }
    }
  }
}


