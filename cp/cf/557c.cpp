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
  int n;
  cin >> n;
  vector<int> l(n);
  for (int i = 0; i < n; i++) {
    cin >> l[i];
  }
  vector<int> cost(*max_element(l.begin(), l.end()) + 1);
  vector<int> need(*max_element(l.begin(), l.end()) + 1);
  vector<int> d(n);
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++) {
    cin >> d[i];
    cost[l[i]] += d[i];
    mp[l[i]].push_back(d[i]);
    need[l[i]]++;
  }
  int curr = 0;
  for (int i = cost.size() - 1; i >= 1; i--) {
    if (cost[i] != 0) {
      int tmp = cost[i];
      cost[i] = curr;
      curr += tmp;
    }
  }
  multiset<int, greater<int>> save;
  curr = 0;
  int ans = accumulate(d.begin(), d.end(), 0ll);
  for (int i = 1; i < need.size(); i++) {
    if (need[i] != 0 && save.size()) {
      int cnt = need[i] - 1;
      auto p = save.begin();
      cost[i] += curr;
      while (cnt && p != save.end()) {
        cost[i] -= *p;
        p++;
        cnt--;
      }
      ans = min(ans, cost[i]);
    } else if (need[i] != 0 && !save.size()) {
      ans = min(ans, cost[i]);
    }
    for (auto p : mp[i]) {
      save.insert(p);
      curr += p;
    }
  }
  cout << ans << '\n';
  // dbg(cost, need);
}

