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
#define int int64_t 

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  set<int> st;
  vector<pair<int, int>> q(tt);
  for (int i = 0; i < tt; i++) {
    int x, m;
    cin >> x >> m;
    q[i] = {x, m};
    st.insert(x);
  }
  const int N = 1e6 + 5;
  vector<vector<int>> f(N + 5);
  vector<vector<int>> cnt(N + 5);
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      int y = j ^ i;
      if (1 <= y && y < j) {
        if (st.find(j) != st.end()) {
          f[j].push_back(y);
        }
        if (st.find(y) != st.end()) {
          cnt[y].push_back(j);
        }
      }
    }
  }
  auto fx = [&] (vector<int> &x, int key) -> int {
    if (x.size() == 0) {
      return 0;
    }
    int ret = 0, lo = 0, hi = x.size() - 1;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (x[mid] > key) {
        hi = mid - 1;
      } else {
        ret = mid + 1;
        lo = mid + 1;
      }
    }
    return ret;
  };
  for (const auto [x, m] : q) {
    // dbg(cnt[x], f[x]);
    cout << fx(cnt[x], m) + fx(f[x], m) << '\n';
  }
}


