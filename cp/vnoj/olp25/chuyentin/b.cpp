/**
 * Author: distiled
 */
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
// #define int uint64_t

const int N = 1005, M = 55;
uint64_t box[N][N];
uint64_t pen_code[M + 5];
int rep[N][N];
int cnt[N * N];

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

inline long long rnd(long long l, long long r) {
  uniform_int_distribution<long long> dis(l, r);
  return dis(rng);
}

// const uint64_t MOD = 1e9 + 7;
uint64_t add(uint64_t x, uint64_t y) {
  // return ((x % MOD) + ((y + MOD * MOD) % MOD)) % MOD;
  return x + y;
  // return x + y;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, p;
  cin >> n >> m >> p;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      box[i][j] = 0;
    }
  }

  for (int i = 1; i <= m; i++) {
    pen_code[i] = rng();
    // pen_code[i] = i;
  }

  while (p--) {
    int i, j, x, y, c;
    cin >> i >> j >> x >> y >> c;
    box[i][j] = add(box[i][j], pen_code[c]);
    box[i][y + 1] = add(box[i][y + 1], -pen_code[c]);
    box[x + 1][j] = add(box[x + 1][j], -pen_code[c]);
    box[x + 1][y + 1] = add(box[x + 1][y + 1], pen_code[c]);
  }

  vector<pair<uint64_t, pair<int, int>>> cur;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      box[i][j] = add(box[i][j], box[i - 1][j]);
      box[i][j] = add(box[i][j], box[i][j - 1]);
      box[i][j] = add(box[i][j], -box[i - 1][j - 1]);
      cur.push_back({box[i][j], {i, j}});
      // cout << box[i][j] << " \n"[j == m];
    }
  }

  for (int i = 1; i <= n * n; i++) {
    cnt[i] = 0;
  }

  sort(cur.begin(), cur.end());
  int id = 0, c = 0;
  uint64_t pre = -1;
  for (auto [v, pp] : cur) {
    uint64_t val = v;
    auto [x, y] = pp;
    if (val != pre) {
      if (c != 0) {
        cnt[id] = c;
      }
      c = 1;
      id += 1;
      pre = val;
    } else {
      c += 1;
    }
    rep[x][y] = id;
  }
  cnt[id] = c;

  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    cout << cnt[rep[x][y]] << '\n';
  }
}
