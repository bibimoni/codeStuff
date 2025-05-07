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
#define int int64_t

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  multiset<int> l, r;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    l.insert(a[i].first);
    r.insert(a[i].second);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    l.erase(l.find(a[i].first));
    r.erase(r.find(a[i].second));
    ans = max(ans, *r.begin() - *l.rbegin());
    l.insert(a[i].first);
    r.insert(a[i].second);
  }
  cout << ans << '\n';
}

