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
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int rt, ct, ra, ca;
  cin >> rt >> ct >> ra >> ca;
  int n, m, t;
  cin >> n >> m >> t;
  vector<pair<char, int>> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i].first >> a[i].second;
  }
  vector<pair<char, int>> b(t);
  for (int i = 0; i < t; i++) {
    cin >> b[i].first >> b[i].second;
  }

  vector<int> tt;
  int prev = 0;
  for (int i = 0; i < m; i++) {
    tt.push_back(prev + 1);
    prev += a[i].second;
  }
  prev = 0;
  for (int i = 0; i < t; i++) {
    tt.push_back(prev + 1);
    prev += b[i].second;
  }

  sort(tt.begin(), tt.end());
  tt.erase(unique(tt.begin(), tt.end()), tt.end());
  tt.push_back(n + 1);

  dbg(tt);
  int stt = int(tt.size());
  vector<char> na(stt - 1);
  int sta = 0;
  for (int i = 0, j = 0; i < m && j < stt - 1; i++) {
    int ri = sta + a[i].second;
    int l = tt[j];
    while (j < stt - 1 && l <= ri) {
      na[j] = a[i].first;
      j += 1;
      l = tt[j];
    }
    sta = ri;
  }

  vector<char> nb(stt - 1);
  int stb = 0;
  for (int i = 0, j = 0; i < t && j < stt - 1; i++) {
    int ri = stb + b[i].second;
    int l = tt[j];
    while (j < stt - 1 && l <= ri) {
      nb[j] = b[i].first;
      j += 1;
      l = tt[j];
    }
    stb = ri;
  }

  auto dir = [&](char c) -> pair<int, int> {
    if (c == 'L') {
      return {0, -1};
    } else if (c == 'R') {
      return {0, 1};
    } else if (c == 'D') {
      return {1, 0};
    } else {
      return {-1, 0};
    }
  };

  int ans = 0;
  for (int i = 0; i + 1 < stt; i++) {
    dbg(rt, ct, ra, ca);
    int l = tt[i], r = tt[i + 1] - 1;
    dbg(na[i], nb[i]);
    auto v1 = dir(na[i]);
    auto v2 = dir(nb[i]);
    if (v1 == v2) {
      rt += v1.first * (r - l + 1);
      ct += v1.second * (r - l + 1);
      ra += v2.first * (r - l + 1);
      ca += v2.second * (r - l + 1);
      continue;
    }
    int dx = rt - ra;
    int dy = ct - ca;
    int dvx = v1.first - v2.first;
    int dvy = v1.second - v2.second;
    double tx = (double)dx / (double)dvx;
    double ty = (double)dy / (double)dvy;
    dbg(tx, ty);
    double t;
    if (dvx == 0) {
      t = ty;
    } else if (dvy == 0) {
      t = tx;
    } else if (tx == ty) {
      t = tx;
    } else {
      rt += v1.first * (r - l + 1);
      ct += v1.second * (r - l + 1);
      ra += v2.first * (r - l + 1);
      ca += v2.second * (r - l + 1);
      continue;
    }

    if (int(t) == t && abs(int(t)) <= (r - l + 1)) {
      ans += abs(int(round(t)));
    }
    rt += v1.first * (r - l + 1);
    ct += v1.second * (r - l + 1);
    ra += v2.first * (r - l + 1);
    ca += v2.second * (r - l + 1);

    dbg("old", rt, ct, ra, ca);
  }

  cout << ans << '\n';
}
