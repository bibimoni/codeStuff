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
#define all(x)         x.begin(), x.end()

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt; cin >> tt;
  while(tt--) {
    int n, m, k; cin >> n >> m >> k;
    vector<pair<int, int>> q;
    vector<vector<int>> pos(n + 1);
    int res = 0;
    for(int i = 0, l, r; i < m; i++) {
      cin >> l >> r;
      q.push_back({l, r});
      pos[l].push_back(i);
      if(r + 1 <= n) pos[r + 1].push_back(~i);
    }
    set<int> s;
    map<int, int> cnt1s;
    map<pair<int, int>, int> cnt2s;
    int dry = 0;
    for(int i = 1; i <= n; i++) {
      for(int j : pos[i]) {
        if(j >= 0) {
          s.insert(j);
        }
        else {
          s.erase(~j);
        }
      }
      if(s.size() == 0) {
        dry++;
      }
      else if(s.size() == 1) {
        cnt1s[*s.begin()]++;
      }
      else if(s.size() == 2) {
        pair<int, int> p(*s.begin(), *next(s.begin()));
        cnt2s[p]++;
      }
    }
    int ans = 0;
    //intersecs
    for(auto [p, cnt] : cnt2s) {
      auto [l, r] = p;
      ans = max(ans, (cnt1s[l] + cnt1s[r] + cnt));
    }
    //no intersecs
    vector<int> one;
    for(auto [i, cnt] : cnt1s) {
      one.push_back(cnt);
    }
    sort(all(one), greater<int>());
    int curr = 0;
    for(int i = 0; i < min((int) one.size(), 2ll); i++) {
      curr += one[i];
    }
    cout << max(ans, curr) + dry << '\n';
  }
}


