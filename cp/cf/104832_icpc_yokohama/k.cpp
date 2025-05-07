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
  auto ask = [&] (int xs, int ys, int xe, int ye) -> long double {
    cout << "query " << xs << ' ' << ys << ' ' << xe << ' ' << ye << '\n';
    cout.flush();
    long double ret;
    cin >> ret;
    return ret;
  };
  const int N = int(1e5), DEL = 100;
  pair<int, int> coord{-1, 0};
  for (int i = 0; i <= N; i += DEL) {
    long double len = ask(i, 0, i, N);
    if (len > (long double)0) {
      coord.first = i;
      break;
    }
  }
  assert(coord.first != -1);
  int lo = 1, hi = N;
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    long double len = ask(coord.first, 0, coord.first, mid);
    if (len > (long double)0) {
      coord.second = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  dbg(coord);
  long double dy  = ask(coord.first, 0           , coord.first, N);
  long double d_y = ask(coord.first, coord.second, coord.first, N);
  long double dx  = ask(0          , coord.second, N          , coord.second);
  long double d_x = ask(coord.first, coord.second, N          , coord.second);
  int y_ans = round(coord.second + -(dy / 2.0) + d_y);
  int x_ans = round(coord.first + -(dx / 2.0) + d_x);
  // dbg(dx, d_x, dy, d_y);
  int r = ask(x_ans, y_ans, x_ans, N);
  cout << "answer " << x_ans << ' ' << y_ans << ' ' << r << '\n';
}

