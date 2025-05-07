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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    for (char c : s) {
      cnt[c - 'a'] += 1;
    }
    auto get_divs = [&] (int num) -> vector<int> {
      vector<int> ret;
      for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
          ret.push_back(i);
          if (i * i != num) {
            ret.push_back(num / i);
          }
        }
      }
      sort(ret.begin(), ret.end());
      return ret;
    };
    int ans = 0;
    vector<int> dk = get_divs(k);
    for (int curr : dk) {
      int l = 1, r = n / curr;
      while (l <= r) {
        int l_need = (l + r) >> 1;
        int l_len = curr;
        for (int c : cnt) {
          if (c == 0) {
            continue;
          }
          l_len -= c / l_need;
        }
        if (l_len <= 0) {
          l = l_need + 1;
          ans = max(ans, l_need * curr);
        } else {
          r = l_need - 1;
        }
      }
    }
    cout << ans << '\n';
  }
}

