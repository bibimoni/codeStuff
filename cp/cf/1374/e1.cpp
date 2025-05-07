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
  int n, k;
  cin >> n >> k;
  int t[n + 1], a[n + 1], b[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> t[i] >> a[i] >> b[i];
  }
  int ans = INF;
  vector<int> all, f, s;
  for(int i = 1; i <= n; i++) {
    if(a[i] == b[i] && a[i] == 1) {
      all.push_back(t[i]);
    }
    else if(a[i] == 1 && a[i] != b[i]) {
      f.push_back(t[i]);
    }
    else if(a[i] == 0 && a[i] != b[i]) {
      s.push_back(t[i]);
    }
  }
  all.push_back(0);
  f.push_back(0);
  s.push_back(0);
  sort(all.begin(), all.end());
  sort(f.begin(), f.end());
  sort(s.begin(), s.end());
  vector<int> pall(n + 1, 0), pf(n + 1, 0), ps(n + 1, 0);
  for(int i = 1; i < all.size(); i++) 
    pall[i] = pall[i - 1] + all[i];
  for(int i = 1; i < f.size(); i++)
    pf[i] = pf[i - 1] + f[i];
  for(int i = 1; i < s.size(); i++)
    ps[i] = ps[i - 1] + s[i];
  //all
  for(int i = 0; i < all.size(); i++) {
    if(k - i >= 0 && k - i < min(f.size(), s.size()))
      ans = min(ans, pall[i] + pf[k - i] + ps[k - i]);
  }
  cout << (ans == INF ? -1 : ans);
}


