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
#define int __int128_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int64_t n, p, h;
  cin >> n >> p >> h;

  vector<int> mul;
  int atk = 0;
  vector<int> add;
  for (int i = 0; i < n; i++) {
    char x;
    cin >> x;
    if (x == '!') {
      atk += 1;
    } else if (x == '*') {
      int64_t v;
      cin >> v;
      mul.push_back(v);
    } else {
      int64_t v;
      cin >> v;
      add.push_back(v);
    }
  }

  if (atk == 0 || (int(add.size()) == 0 && p == 0)) {
    cout << "*";
    return 0;
  }

  int a = 1;
  const int bound = 2e9;
  for (int i = 0; i < int(mul.size()); i++) {
    if (a > bound / mul[i]) {
      a = bound ;
      break;
    }
    a *= mul[i];
  }
  int b = accumulate(add.begin(), add.end(), 0ll);

  int turn = 0;
  if (a == 1) {
    int lo = 0, hi = 1e9;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      __int128_t v = b * (mid * (mid + 1)) / 2 + mid * p;
      if (v >= (h - 1 + atk) / atk) {
        hi = mid - 1; 
        turn = mid;
      } else {
        lo = mid + 1;
      }
    }
    turn -= 1;
    h -= atk * (turn * p + b * (turn * (turn + 1)) / 2);
    p += turn * b;
  } else {
    for (;;) {
      p = (p + a) * b;
      if (p >= (h - 1 + atk) / atk) {
        break;
      }
      h -= p * atk;
      turn += 1;
    }
  }
  dbg((int64_t)h, (int64_t)turn, (int64_t)a, (int64_t)b, p);

  assert(h > 0);

  sort(mul.begin(), mul.end(), greater<>());
  sort(add.begin(), add.end(), greater<>());
  int prem = 1;
  int ans = 1e18;
  for (int cm = 0; cm <= int(mul.size()); cm++) {
    int prea = 0;
    for (int ca = 0; ca <= int(add.size()); ca++) {
      for (int at = 1; at <= atk; at++) {
        __int128_t dmg = ((p + prea)  * prem) * at;
        if (dmg >= h) {
          ans = min(ans, ca + cm + at + turn * n);
        }
      }
      if (ca < int(add.size()))
        prea += add[ca];
    }
    if (cm < int(mul.size())) {
      if (prem > bound / mul[cm]) {
        prem = bound;
      } else {
        prem *= mul[cm];
      }
    }
  }

  if (ans == int(1e18)) {
    cout << "*";
  } else {
    cout << (int64_t)ans;
  }
}
