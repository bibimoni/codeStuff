/**
 * Author: distiled
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
#define int int64_t

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

inline long long rnd(long long l, long long r) {
  uniform_int_distribution<long long> dis(l, r);
  return dis(rng);
}

int hilbertOrder(int x, int y) {
  const int lg = __lg(max(x, y) * 2 + 1) | 1;
  const int maxn = (int(1) << lg) - 1;
  int ret = 0;
  for (int s = int(1) << (lg - 1); s > 0; s >>= 1) {
    bool rx = x & s, ry = y & s;
    ret = (ret << 2) | (rx ? ry ? 2 : 1 : ry ? 3 : 0);
    if (!rx) {
      if (ry) {
        x ^= maxn;
        y ^= maxn;
      }
      swap(x, y);
    }
  }
  return ret;
}

struct Query {
  int l, r, idx;

  Query() {}
  Query(int l_, int r_, int idx_) {
    l = l_;
    r = r_;
    idx = idx_;
  }
  int toPair() const { return hilbertOrder(l, r); }
};

bool operator<(const Query &L, const Query &R) {
  return L.toPair() < R.toPair();
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> s;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      s.push_back(a[i]);
    }
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    map<int, int> old;
    for (int i = 1; i <= n; i++) {
      int x = a[i];
      a[i] = lower_bound(s.begin(), s.end(), a[i]) - s.begin() + 1;
      old[a[i]] = x;
    }

    vector<Query> Q(q);
    for (int i = 0; i < q; i++) {
      int l, r;
      cin >> l >> r;
      Q[i] = Query(l, r, i);
    }

    vector<int> mp(n + 1, 0);

    auto add = [&](int x) -> void {
      int val = a[x];
      mp[val]++;
    };
    auto remove = [&](int x) -> void {
      int val = a[x];
      mp[val]--;
    };

    sort(Q.begin(), Q.end());
    int l = 1, r = 0;
    vector<vector<int>> res(q);
    for (Query qq : Q) {
      dbg(qq.l, qq.r);
      while (r < qq.r) {
        r++;
        add(r);
      }
      while (l > qq.l) {
        l--;
        add(l);
      }
      while (r > qq.r) {
        remove(r);
        r--;
      }
      while (l < qq.l) {
        remove(l);
        l++;
      }

      int b = (r - l + 1) / 3;
      const int BOUND = 50;
      for (int x = 0; x < BOUND; x++) {
        int v = rnd(l, r);
        if (mp[a[v]] > b) {
          res[qq.idx].push_back(a[v]);
        }
      }
    }

    for (int i = 0; i < q; i++) {
      sort(res[i].begin(), res[i].end());
      res[i].erase(unique(res[i].begin(), res[i].end()), res[i].end());
      if (res[i].size() == 0) {
        cout << "-1\n";
      } else {
        for (int v : res[i]) {
          cout << old[v] << ' ';
        }
        cout << '\n';
      }
    }
  }
}
