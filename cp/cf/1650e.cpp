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
    int n, d;
    cin >> n >> d;
    // dbg(n, d);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    multiset<pair<int, int>> st;
    int prev = 0;
    for (int i = 0; i < n; i++) {
      st.insert({a[i] - prev - 1, i});
      prev = a[i];
    }
    auto getAns = [&](int idx) -> int {
      vector<int> b;
      for (int i = 0; i < n; i++) {
        if (i == idx) {
          continue;
        }
        b.push_back(a[i]);
      }
      int prev = 0;
      int gap = 0, id = 0, m = d;
      for (int i = 0; i < n - 1; i++) {
        if (gap < b[i] - prev - 1) {
          gap = b[i] - prev - 1;
          m = (b[i] + prev) / 2;
          id = i;
        }
        prev = b[i];
      }
      if ((gap - 1) / 2 <= d - b[n - 2] - 1 && b[n - 2] != d) {
        b.push_back(d);
      } else {
        b.insert(b.begin() + id, m);
      }
      prev = 0;
      int ret = d;
      for (int i = 0; i < n; i++) {
        ret = min(ret, b[i] - prev - 1);
        if (i < n - 1) {
          ret = min(ret, b[i + 1] - b[i] - 1);
        }
        prev = b[i];
      }
      return ret;
    };
    auto [val, id] = *st.begin();
    if (id > 0) {
      cout << max({getAns(id), getAns(id - 1), val}) << '\n';
    } else {
      cout << max(val, getAns(id)) << '\n';
    }
  }
}

