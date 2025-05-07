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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(n + 1, 0);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      cnt[a[i]]++;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
      ans += (cnt[i] == 2);
    }
    cout << ans << '\n';
  }
}

