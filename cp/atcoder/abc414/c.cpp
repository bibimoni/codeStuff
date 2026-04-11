/**
 * Author: distiled
 */
#include <algorithm>
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
  int a, n;
  cin >> a >> n;

  auto isPalindrome = [&](long long x) -> bool {
    int length = -1;
    vector<int> digit(100);
    while (x) {
      ++length;
      digit[length] = x % a;
      x /= a;
    }
    for (int i = 0, j = length; i < j; ++i, --j) {
      if (digit[i] != digit[j]) {
        return false;
      }
    }
    return true;
  };

  set<int> vals;
  int l = 1;
  for (int cnt = 0; cnt < 7; cnt++) {
    int r = l * 10;
    for (int op = 0; op < 2; op++) {
      for (int i = l; i < r; i++) {
        int val = i;
        int x = (op == 0 ? i / 10 : i);
        while (x) {
          val = val * 10 + x % 10;
          x /= 10;
        }
        if (val <= n && isPalindrome(val)) {
          vals.insert(val);
        }
      }
    }
    l = r;
  }

  int ans = 0;
  for (int x : vals) {
    ans += x;
  }
  cout << ans << '\n';
}
