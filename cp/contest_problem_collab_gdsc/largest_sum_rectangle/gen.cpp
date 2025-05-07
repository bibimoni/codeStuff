/**
 * Author: distiled
 */
#include<iostream>
using namespace std;

#include "testlib.h"
#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif

int main(int argc, char * argv[]) {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  registerGen(argc, argv, 1);
  int tt = opt<int>("tt");
  int N = opt<int>("N");
  int M = opt<int>("M");
  int mx = opt<int>("mx");
  bool n_m = opt<bool>("n_m");
  tt = min(tt, min(N, M) / 2);
  auto n_vec = rnd.partition(tt, N, 2);
  auto m_vec = rnd.partition(tt, M, 2);
  if (n_m) {
    m_vec = n_vec;
  }
  int t = -500, jump = 1000 / tt;
  auto ok = [&] (int a, int b, int c, int d) -> bool {
    if (a > b) 
      swap(a, b);
    if (d > c) 
      swap(c, d);
    return d < a || b < c;
  };

  auto inside = [&] (int i, int j, int x, int y, int k) -> bool {
    return (x - k + 1 <= i && i <= x && y - k + 1 <= j && j <= y);
  };

  println(tt);
  for (int jj = 0; jj < tt; jj++) {
    int n = n_vec[jj], m = m_vec[jj];
    int k;
    if (min(n, m) / 2 == 1) {
      k = 1;
    } else {
      k = rnd.wnext(min(n, m) / 2, t) + 1;
    }
    t += jump;

    int x_1 = rnd.next(k, n), y_1 = rnd.next(k, m);
    vector<pair<int, int>> to_be;
    for (int i = k; i <= n; i++) {
      for (int j = k; j <= m; j++) {
        if (ok(i - k + 1, i, x_1 - k + 1, x_1) || ok(j - k + 1, j, y_1 - k + 1, y_1)) {
          to_be.push_back({i, j});
        }
      }
    }
    auto [x_2, y_2] = to_be[rnd.next(to_be.size())];
    vector<int> rnd_values;
    for (int i = 0; i < n * m; i++) {
      rnd_values.push_back(rnd.next(int(mx) + 1));
    }
    sort(rnd_values.begin(), rnd_values.end());
    // dbg(rnd_values)
    const int S = mx / 5; // the larger this is, the more chance our 2 random coords will be the largest

    cout << n << ' ' << m << ' ' << k << '\n';
    for (int i = 1; i <= n; i++) {
      vector<int> tmp;
      for (int j = 1; j <= m; j++) {
        if (inside(i, j, x_2, y_2, k) || inside(i, j, x_1, y_1, k)) {
          tmp.push_back(rnd_values[rnd.wnext(rnd_values.size(), S)]);
        } else {
          tmp.push_back(rnd_values[rnd.wnext(rnd_values.size(), -S)]);
        }
      }
      println(tmp);
    }
  }
}
