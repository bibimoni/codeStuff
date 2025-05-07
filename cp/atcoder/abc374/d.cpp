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

struct Line {
  int a, b, c, d;
  Line() {}
  Line(int _a, int _b, int _c, int _d) :
    a(_a), b(_b), c(_c), d(_d) {}
  pair<int, int> get(int id) const {
    if (id == 0) {
      return pair<int, int>{a, b};
    } else {
      return pair<int, int>{c, d};
    }
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, s, t;
  cin >> n >> s >> t;
  vector<Line> line(n);
  for (int i = 0; i < n; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    line[i] = Line(a, b, c, d);
  }
  vector<int> p(n);
  iota(p.begin(), p.end(), int(0));
  long double ans = 1e18;
  auto calc = [&] (pair<int, int> i, pair<int, int> j) -> long double {
    return sqrt((i.first - j.first) * (i.first - j.first) + (i.second - j.second) * (i.second - j.second));
  };
  do {
    for (int mask = 0; mask < (int(1) << n); ++mask) {
      pair<int, int> pos{0, 0};
      long double time_takes = 0;
      for(int id = 0; id < n; id++) {
        int i = p[id];
        Line cur = line[i];
        array<pair<int, int>, 2> nxt;
        nxt[0] = cur.get((mask >> id) & 1);
        nxt[1] = cur.get(1 ^ ((mask >> id) & 1));
        // dbg(nxt[0], nxt[1]);
        time_takes += calc(pos, nxt[0]) / s;
        // dbg(s * calc(pos, nxt[0]));
        time_takes += calc(nxt[0], nxt[1]) / t;
        // dbg(t * calc(nxt[0], nxt[1]));
        pos = nxt[1];
      }
      // dbg(time_takes);
      ans = min(ans, time_takes);
    }
  } while (next_permutation(p.begin(), p.end()));
  cout << setprecision(9) << fixed << ans << '\n';
}


