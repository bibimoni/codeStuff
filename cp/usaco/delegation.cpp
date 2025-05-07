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
  freopen("deleg.in", "r", stdin);
  freopen("deleg.out", "w", stdout);
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  auto can_remove = [&] (int k, int idx, vector<int> &v) -> bool {
    int l = 0, r = v.size() - 1;
    while (l < r) {
      if (l == idx) {
        l += 1;
      } 
      if (r == idx) {
        r -= 1;
      } 
      if (v[l] + v[r] < k) {
        return false;
      }
      l += 1;
      r -= 1;
    }
    return true;
  };

  vector len(n + 1, int(0));
  auto dfs = [&] (auto &&self, int k, int u, int p) -> bool {
    vector<int> cands;
    for (int v : adj[u]) {
      if (v == p) {
        continue;
      }
      if (!self(self, k, v, u)) {
        return false;
      }
      cands.push_back(len[v] + 1);
    }
   
    if (u == 1) {
      if (cands.size() % 2 == 1) {
        cands.push_back(0);
      }
      sort(cands.begin(), cands.end());
      return can_remove(k, -1, cands);
    } else {
      if (cands.size() % 2 == 0) {
        cands.push_back(0);
      }
      sort(cands.begin(), cands.end());

      int lo = -1, hi = cands.size();
      while (hi - lo > 1) {
        int mid = (lo + hi) >> 1;
        if (can_remove(k, mid, cands)) {
          lo = mid;
        } else {
          hi = mid;
        }
      }

      if (lo == -1) {
        return false;
      } else {
        len[u] = cands[lo];
        return true;
      }
    }
  };

  int lo = -1, hi = 1e9;
  while (hi - lo > 1) {
    int mid = (lo + hi) >> 1;
    len = vector<int>(n + 1, 0);
    if (dfs(dfs, mid, 1, 1)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  cout << lo;
}

