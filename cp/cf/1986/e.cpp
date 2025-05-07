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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, vector<int>> f;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      f[a[i] % k].push_back(a[i]);
    }
    int cnt = 0;
    for (auto [_, p] : f) {
      cnt += p.size() % 2;
    }
    if (cnt > 1) {
      cout << "-1\n";
      continue;
    }
    int ans = 0;
    for (auto [_, p] : f) {
      sort(p.begin(), p.end());
      if (p.size() & 1) {
        int s = 0;
        for (int i = 1; i < p.size(); i += 2) {
          if(i + 1 < p.size())
            s += p[i + 1] - p[i];
        }
        int curr = s;
        for (int i = 1; i < p.size(); i++) {
          if (i % 2 == 0)
            s -= p[i] - p[i - 1];
          else 
            s += p[i] - p[i - 1];                      
          curr = min(curr, s);
        }
        ans += curr;
      } else {
        for (int i = 0; i < p.size(); i += 2) {
          if (i + 1 < p.size())
            ans += p[i + 1] - p[i];
        }
      }
    }
    cout << ans / k << '\n';
  }
}



