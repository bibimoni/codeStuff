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

int bn(vector<int> b, int val) {
  int pos = -1, l = 0, r = b.size() - 1;
  while(l <= r) {
    int mid = (l + r) >> 1;
    if(b[mid] >= val) {
      r = mid - 1;
    }
    else {
      l = mid + 1;
      pos = mid;
    }
  }
  return pos;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, x; cin >> n >> x;
    vector<pair<int, int>> a(n);
    vector<int> ans(n);
    for(int i = 0, x; i < n; i++) {
      cin >> x;
      a[i] = {x, i};
    }
    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(all(b));
    sort(all(a), greater<pair<int, int>>());
    auto [element, id] = a[x - 1];
    int cnt = 0;
    int pos = x - 1;
    for(int i = 0; i < x; i++) {
      ans[a[i].second] = b[pos--];
      if(a[i].first > b[pos + 1]) {
        cnt++;
      }
    }
    pos = n - 1;
    for(int i = x; i < n; i++) {
      ans[a[i].second] = b[pos--];
      if(a[i].first > b[pos + 1]) {
        cnt++;
      }
    }
    if(cnt == x) {
      cout << "YES\n";
      for(auto i : ans) cout << i << ' ';
      cout << '\n';
    }
    else {
      cout << "NO\n";
    }
  } 
}

