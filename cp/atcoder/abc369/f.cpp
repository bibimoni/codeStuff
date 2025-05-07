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

const int INF = 1e9;

struct SegTree {
  vector<pair<int, int>> st;
  int n;
  SegTree(int _n) : n(_n) {
    st.assign(4 * n + 5, pair<int, int>{0, 1});
  }

  void update(int i, pair<int, int> val) {
    update(i, val, 1, 1, n);
  }

  void update(int i, pair<int, int> val, int id, int l, int r) {
    if (r < i || i < l) {
      return;
    }
    if (l == r) {
      st[id] = val;
      return;
    }
    int mid = (l + r) >> 1;
    update(i, val, id * 2, l, mid);
    update(i, val, id * 2 | 1, mid + 1, r);
    st[id] = max(st[id * 2 | 1], st[id * 2]);
  }

  pair<int, int> query(int u, int v) {
    return query(u, v, 1, 1, n);
  }

  pair<int, int> query(int u, int v, int id, int l, int r) {
    if (v < l || r < u) {
      return {-INF, 0};
    }
    if (u <= l && r <= v) {
      return st[id];
    }
    int mid = (l + r) >> 1;
    return max(query(u, v, id * 2, l, mid), query(u, v, id * 2 | 1, mid + 1, r));
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int h, w, n;
  cin >> h >> w >> n;
  vector<pair<int, int>> coins(n + 1, {0, 0});
  map<int, vector<int>> mp;
  for (int i = 1; i <= n; i++) {
    cin >> coins[i].first >> coins[i].second;
  }
  coins.push_back({1, 1});
  coins.push_back({h, w});
  n += 2;

  SegTree st(w + 1);
  sort(coins.begin(), coins.end());
  vector<int> dp(n + 1, 0), trace(n + 1, -1);
  for (int i = 1; i <= n; i++) {
    if (coins[i] == pair<int, int>{1, 1}) {
      st.update(1, {0, 1});
      continue;
    } 
    auto [val, id] = st.query(1, coins[i].second);
    dp[i] = val + 1;
    st.update(coins[i].second, {dp[i], i});
    trace[i] = id;

    if (coins[i] == pair<int, int>{h, w}) {
      dp[n] -= 1;
    }
  }
  cout << dp[n] << '\n';
  
  auto to_path = [&] (pair<int, int> se, pair<int, int> fi) -> string {
    return ((se.first - fi.first) > 0 ? string(se.first - fi.first, 'D') : "") 
      + ((se.second - fi.second) > 0 ? string(se.second - fi.second, 'R') : "");
  };
  
  int cur = n;
  string ans = "";
  while (trace[cur] != -1) {
    ans += to_path(coins[cur], coins[trace[cur]]);
    cur = trace[cur];
  }
  reverse(ans.begin(), ans.end());
  cout << ans << '\n';
}

