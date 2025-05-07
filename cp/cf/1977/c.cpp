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
    vector<int> a(n);
    map<int, int> cnt;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      cnt[a[i]]++;
    }
    auto lcm = [&] (int a, int b) -> int {
      return (a * b) / __gcd(a, b);
    };
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    reverse(a.begin(), a.end());
    int ans = 0;
    for(int i = 0; i < a.size(); i++) {
      int curr = a[i];
      int l = cnt[a[i]];
      for(int j = i + 1; j < a.size(); j++) {
        int nxt = lcm(curr, a[j]);
        if(nxt > a[0]) {
          ans = n;
          break;
        }
        if(nxt == curr || !cnt[nxt]) {
          l += cnt[a[j]];
          curr = nxt;
          if(!cnt[curr])
            ans = max(ans, l);
        }
      }
    }
    cout << ans << '\n';
  }
}


