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
const int INF = (int) 1e18;
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    if(k > 2) {
      cout << "0\n";
    }
    else if(k == 1) {
      int ans = INF;
      for(int i = 0; i < n; i++) {
        ans = min(a[i], ans);
      }
      for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
          ans = min(abs(a[i] - a[j]), ans);
        }
      }
      cout << ans << '\n';
    }
    else if(k == 2) {
      int ans = INF;
      vector<int> neg;
      for(int i = 0; i < n; i++) {
        ans = min(ans, a[i]);
      }
      for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
          ans = min(abs(a[i] - a[j]), ans);
          neg.push_back(abs(a[i] - a[j]));
        }
      }
      sort(neg.begin(), neg.end());
      for(int i = 0; i < n; i++) {
        int pos = lower_bound(neg.begin(), neg.end(), a[i]) - neg.begin();
        for(int j = max(pos - 1, 0ll); j <= min(pos + 1, (int) neg.size() - 1); j++) {
          ans = min(ans, abs(a[i] - neg[j]));
          dbg(a[i], neg[j]);
        }
      }
      cout << ans << '\n';
    }
  }
}


