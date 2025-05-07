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
  int n, m;
  cin >> n >> m;
  vector<int> s;
  vector<pair<int, int>> a(n);
  map<int, vector<int>> f;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    s.push_back(a[i].first);
    s.push_back(a[i].second);
    f[a[i].first].push_back(a[i].second);
  }
  vector<pair<int, int>> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i].first >> b[i].second;
    s.push_back(b[i].first);
    s.push_back(b[i].second);
  }
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());
  auto idx = [&](int val) -> int {
    return lower_bound(s.begin(), s.end(), val) - s.begin() + 1;
  };
  sort(a.begin(), a.end(), [&] (pair<int, int> i, pair<int, int> j) {
    return i.first < j.first;
  });
  sort(b.begin(), b.end(), [&] (pair<int, int> i, pair<int, int> j) {
    return i.first < j.first;
  });
  int ans = 0, curr = 0;
  for (int i = 0; i < n; i++) {
    
  } 
}

