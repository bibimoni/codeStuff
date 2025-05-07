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
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 1; i <= n; i++) {
      int x; cin >> x;
      if(a.size() && a.back() == x) 
        continue;
      a.push_back(x);
    }
    vector<int> cnt(n + 1, 1);
    n = a.size();
    for(int i = 0; i < n; i++) {
      cnt[a[i]]++;
      if(i == 0) 
        cnt[a[i]]--;
      if(i == n - 1)
        cnt[a[i]]--;
    }
    int ans = n;
    for(int i : a) {
      ans = min(cnt[i], ans);
    }
    cout << ans << '\n';
  }
}


