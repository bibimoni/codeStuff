/**
 * Author: distiled
 */
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
// #define int int64_t

const int N = 1e6;
int minPrime[N + 5];

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 1; i <= N; i++) {
    minPrime[i] = 0;
  }
  minPrime[1] = 1;
  for (int i = 2; i <= N; i++) {
    if (minPrime[i] == 0) {
      minPrime[i] = i;
      for (int j = i * 2; j <= N; j += i) {
        minPrime[j] = i;
      }
    }
  }

  int n;
  cin >> n;
  int64_t ans = 0;
  map<vector<int>, int> cnt;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    int tmp = x;
    vector<int> cur;
    while (tmp != 1) {
      cur.push_back(minPrime[tmp]);
      tmp /= minPrime[tmp];
    }
    sort(cur.begin(), cur.end());
    vector<int> odd;
    int c = 0, pre = -1;
    for (int y : cur) {
      if (pre != y) {
        if (c % 2 == 1) {
          odd.push_back(pre);
        }
        pre = y;
        c = 1;
      } else {
        c += 1;
      }
    }
    if (c % 2 == 1) {
      odd.push_back(pre);
    }

    ans += cnt[odd];
    cnt[odd] += 1;
  }

  cout << ans << '\n';
}
