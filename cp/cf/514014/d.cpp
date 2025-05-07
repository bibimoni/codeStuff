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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> cnt(n, 0);
    for(int i = 1; i < n; i++) {
      if(a[i - 1] >= a[i])
        cnt[i] = cnt[i - 1] + (a[i - 1] - a[i] + 1);
      else 
        cnt[i] = cnt[i - 1];
    }
    dbg(cnt);
    while(q--) {
      int l, r;
      cin >> l >> r;
      l--, r--;
      cout << cnt[r] - cnt[l] << '\n';
    }
  }
}

