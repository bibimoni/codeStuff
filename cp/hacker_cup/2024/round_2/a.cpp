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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  freopen("cottontail_climb_part_2_input.txt", "r", stdin);
  freopen("cottontail_climb_part_2_validation_input.out", "w", stdout);
  int tt;
  cin >> tt;
  for (int tc = 1; tc <= tt; tc++) {
    int a, b, m;
    cin >> a >> b >> m;
    map<pair<int, int>, int> f;
    vector<int> pow10(1, 1);
    while (pow10.size() < 19) {
      pow10.push_back(pow10.back() * 10);
    }
    auto add_num = [&] (int num, int d1, int d2) -> int {
      num = num * 10 + d2;
      int tmp = num, cnt = 0;
      while(tmp) {
        cnt += 1;
        tmp /= 10;
      }
      num = d1 * pow10[cnt] + num;
      return num;
    };
    auto fn = [&] (int num) -> int {
      while (num > 9) {
        num /= 10;
      }
      return num;
    };
    auto make_num = [&] (auto &&self, int num, int len, int x) -> int {
      // dbg(num, len);
      if (len == 0) {
        return (num % m == 0) && num <= x;
      }
      if (f.count({num, len})) {
        return f[{num, len}];
      }
      int bound = (num <= 9) ? (num - 1) : num % 10;
      int bound2 = (num <= 9) ? (num - 1) : fn(num);
      int ret = 0;
      for (int d = 1; d <= bound; d++) {
        for (int d2 = 1; d2 <= bound2; d2++) {
          int nxt = add_num(num, d2, d);
          if (nxt > x) {
            continue;
          }
          ret += self(self, nxt, len - 1, x);
        }
      }
      // dbg(num);
      return (f[{num, len}] = ret);
      // return f[{num, len}];
      // return ret;
    };
    auto solve = [&] (int x) -> int {
      if (x < 0) 
        return 0;
      int cnt = 0;
      int tmp = x;
      // dbg(x);
      while (tmp) {
        cnt += 1;
        tmp /= 10;
      }
      cnt = (cnt + 1) / 2;
      // dbg(cnt, x, tmp);
      int ret = 0;
      for (int l = 1; l <= cnt; l++) {
        for (int d = 1; d <= 9; d++) {
          ret += make_num(make_num, d, l - 1, x);
        }
      }
      // dbg(ret);
      return ret;
    };
    // dbg(a, b);
    int t1 = solve(b);
    // f.clear();
    int t2 = solve(a - 1);
    // dbg(t1, t2);
    cout << "Case #" << tc << ": " << t1 - t2 << '\n';  
  }
}


