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
    l = l_; r = r_; idx = idx_;
  }
  int toOrd() const {
    return hilbertOrder(l, r);
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int m;
  cin >> m;
  vector<Query> Q(m);
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    l--; r--;
    Q[i] = Query(l, r, i);
  }

  sort(Q.begin(), Q.end(), [&] (const auto &u, const auto &v) {
    return u.toOrd() < v.toOrd();
  });

  vector<int> cnt(n + 1);
  int ans = 0; 

  auto add = [&] (int idx) -> void {
    cnt[a[idx]] += 1;
    ans += cnt[a[idx]] % 2 == 0;
  };

  auto remove = [&] (int idx) -> void {
    cnt[a[idx]] -= 1;
    ans -= cnt[a[idx]] % 2 != 0;
  };

  vector<int> res(m);
  int l = 0, r = -1;
  for (Query q : Q) {
    while (r < q.r) {
      r++;
      add(r);
    }
    while (l > q.l) {
      l--;
      add(l);
    }
    while (r > q.r) {
      remove(r);
      r--;
    }
    while (l < q.l) {
      remove(l);
      l++;
    }
    res[q.idx] = ans;
  }
  for (int i = 0; i < m; i++) {
    cout << res[i] << "\n";
  }
}