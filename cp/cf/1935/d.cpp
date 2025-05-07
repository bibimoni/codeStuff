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
    int n, c;
    cin >> n >> c;
    int a[n];
    for(int &i : a)
      cin >> i;
    int ans = (c + 2) * (c + 1) / 2;
    vector<int> cnt(2);
    for(int i : a) {
      cnt[i % 2]++;
      ans -= (i / 2) + 1;
      ans -= c - i + 1;
    }
    ans += (cnt[0] * (cnt[0] + 1)) / 2 + (cnt[1] * (cnt[1] + 1)) / 2;
    cout << ans << '\n';
  }
}


