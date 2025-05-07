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
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> a(k);
    map<int, int> rows;
    map<int, set<int>> rowsS;
    map<int, int> idR;
    for(int i = 0; i < k; i++) {
      cin >> a[i].first >> a[i].second;
      if(!rows.count(a[i].first)) {
        rows[a[i].first] = m + 1;
        rowsS[a[i].first].insert(m + 1);
      }
      if(rows[a[i].first] > a[i].second) {
        idR[a[i].first] = i;
      }
      rows[a[i].first] = min(rows[a[i].first], a[i].second);
      rowsS[a[i].first].insert(a[i].second);
    }
    vector<pair<int, int>> s;
    for(auto [k, v] : rows) {
      s.push_back({k, v});
    }
    int prev = m + 1;
    sort(s.begin(), s.end());
    for(int i = s.size() - 1; i >= 0; i--) {
      if(prev <= s[i].second) {
        idR[s[i].first] = -1;
      }
      s[i].second = min(prev, s[i].second);
      prev = s[i].second;
    }
    int alpha = (s[0].second - 1) * (s[0].first);
    map<int, int> add;
    for(int i = 1; i < s.size(); i++) {
      alpha += (s[i].second - 1) * (s[i].first - s[i - 1].first);
    }
    alpha += (n - s[s.size() - 1].first) * m;
    cout << alpha << '\n';
    vector<int> ans(k, 0);
    for(auto [k, v] : add) {
      if(v != -1)
        ans[k] = v;
    }
    for(int i = 0; i < k; i++) {
      cout << ans[i] << " \n"[i == k - 1];
    }
  }
}


