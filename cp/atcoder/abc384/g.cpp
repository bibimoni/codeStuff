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

const int BLOCK_SIZE = 350;

struct Block {
  int l, r, idx;
  // pair<int, int> ord;
  int ord;
  Block() { l = -1, r = -1, idx = -1; }
  Block(int _l, int _r, int _idx) : 
    l(_l), r(_r), idx(_idx) {}
  inline void order() {
    // Your order here 
    // ord = pair{l / BLOCK_SIZE, (l / BLOCK_SIZE) & 1 ? -r : r};
    ord = hilbertOrder(l, r);
  }
  friend ostream& operator<<(ostream& out, const Block& cur) {
    return out << "[" << cur.l << ' ' << cur.r << "]\n";
  }
};


template <class T>
class Fenwick {
  vector<T> a;
  int n;

public:
  Fenwick() {}

  Fenwick(int n_) : n(n_) {
    // check initial value
    a.assign(n + 5, static_cast<T>(0));
  }

  T query(int r) {
    T q = 0; // check default value of query
    for (; r > 0; r -= (r & -r)) {
      q += a[r]; // check query modification
    }
    return q;
  }

  void update(int r, T del) {
    for (; r <= n; r += (r & -r)) {
      a[r] += del; //check update rule
    }
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  vector<int> s(a.begin() + 1, a.end());
  s.insert(s.end(), b.begin() + 1, b.end());
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());

  auto idx = [&] (int val) -> int {
    return lower_bound(s.begin(), s.end(), val) - s.begin() + 1;
  };
  vector<int> da(n + 1), db(n + 1);
  for (int i = 1; i <= n; i++) {
    da[i] = idx(a[i]);
    db[i] = idx(b[i]);
  }
  Fenwick<int> sum_a(s.size() + 1);
  Fenwick<int> sum_b(s.size() + 1);
  Fenwick<int> cnt_a(s.size() + 1);
  Fenwick<int> cnt_b(s.size() + 1);

  int q;
  cin >> q;
  vector<Block> que(q);
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    que[i] = Block(l, r, i);
    que[i].order();
  }
  sort(que.begin(), que.end(), [&] (Block i, Block j) {
    return i.ord < j.ord;
  }); 
  vector<int> ans(q);
  int cur_x = 0, cur_y = 0, s_a = 0, s_b = 0;
  int now = 0;

  for (const Block& bb : que) {
    while (cur_x < bb.l) {
      cur_x += 1;
      // add
      int c = cnt_b.query(da[cur_x] - 1);
      int t = sum_b.query(da[cur_x] - 1);
      now += cur_y * a[cur_x] + s_b - 2 * (t + (cur_y - c) * a[cur_x]);
      cnt_a.update(da[cur_x], 1);
      sum_a.update(da[cur_x], a[cur_x]);
      s_a += a[cur_x];
    }
    while (cur_y < bb.r) {
      // add
      cur_y += 1;
      int c = cnt_a.query(db[cur_y] - 1);
      int t = sum_a.query(db[cur_y] - 1);
      now += cur_x * b[cur_y] + s_a - 2 * (t + (cur_x - c) * b[cur_y]);
      cnt_b.update(db[cur_y], 1);
      sum_b.update(db[cur_y], b[cur_y]);
      s_b += b[cur_y];
    }
    while (cur_x > bb.l) {
      // remove
      int c = cnt_b.query(da[cur_x] - 1);
      int t = sum_b.query(da[cur_x] - 1);
      now -= cur_y * a[cur_x] + s_b - 2 * (t + (cur_y - c) * a[cur_x]);
      cnt_a.update(da[cur_x], -1);
      sum_a.update(da[cur_x], -a[cur_x]);
      s_a -= a[cur_x];
      cur_x -= 1;
    }
    while (cur_y > bb.r) {
      // remove
      int c = cnt_a.query(db[cur_y] - 1);
      int t = sum_a.query(db[cur_y] - 1);
      now -= cur_x * b[cur_y] + s_a - 2 * (t + (cur_x - c) * b[cur_y]);
      cnt_b.update(db[cur_y], -1);
      sum_b.update(db[cur_y], -b[cur_y]);
      s_b -= b[cur_y];
      cur_y -= 1;
    }
    ans[bb.idx] = now;
  }
  for (int i = 0; i < q; i++) {
    cout << ans[i] << '\n';
  }
}

