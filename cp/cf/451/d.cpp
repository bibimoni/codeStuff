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
  string s;
  cin >> s;

  vector<int> cnt;
  vector<int> c0;
  char prev = '$';
  int cur = 0, cnt0 = 0;
  for (int i = 0; i < int(s.size()); i++) {
    char x = s[i];
    if (prev != x) {
      if (cur) {
        c0.push_back(cnt0);
        cnt.push_back(cur);
      }
      cur = 1;
      cnt0 = int(i % 2 == 0);
      prev = x;
    } else {
      cur += 1;
      cnt0 += int(i % 2 == 0);
    }
  }

  cnt.push_back(cur);
  c0.push_back(cnt0);

  int n = int(cnt.size());

  vector<int> dp(2);
  vector<int> sum(2);
  int ans_even = 0, ans_odd = 0, v = s[0] - 'a';
  for (int i = 0; i < n; i++) {
    int x = 0, y = 0;
    for (int j = 0; j < cnt[i]; j++) {
      x += int(j % 2 == 0);
      y += int(j % 2 != 0);
      if (j % 2 == 0) {
        ans_even += y;
        ans_odd += x;
      } else {
        ans_even += x;
        ans_odd += y;
      }
    }
    ans_odd += c0[i] * dp[v] + (cnt[i] - c0[i]) * (sum[v] - dp[v]);
    ans_even += c0[i] * (sum[v] - dp[v]) + (cnt[i] - c0[i]) * dp[v];
    dp[v] += c0[i];
    sum[v] += cnt[i];
    v ^= 1;
  }

  cout << ans_even << ' ' << ans_odd << '\n';
  // 5 4 2 4
}
