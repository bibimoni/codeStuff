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
    const int X = sqrt(n);
    int a[n + 1];
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<vector<int>> pref(n + 1, vector<int>(X + 1, 0));
    vector<vector<int>> sub(n + 1, vector<int>(X + 1, 0));
    auto get = [&] (int i, int j) {
      return (i / j) + (i % j != 0);
    };
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= X; j++) {
        pref[i][j] = pref[max(0ll, i - j)][j] + get(i, j) * a[i];
        sub[i][j] = sub[max(0ll, i - j)][j] + a[i];
      }
    }
    while(q--) {
      int s, d, k;
      cin >> s >> d >> k;
      if(d > X) {
        int ans = 0, cnt = 1; 
        for(int i = s; i <= s + d * (k - 1); i += d) {
          ans += a[i] * (cnt++);
        }
        cout << ans << ' ';
      }
      else {
        cout << (pref[s + d * (k - 1)][d] - pref[max(s - d, 0ll)][d]) 
          - ((get(s, d) - 1) * (sub[s + d * (k - 1)][d] - sub[max(s - d, 0ll)][d])) << ' ';
      }
    }
    cout << '\n';
  }
}


