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
  int p;
  cin >> p;
  string s;
  cin >> s;
  int n = s.size();
  s = " " + s;
  if (p == 2 || p == 5) {
    vector<int> pre(n + 1), cnt(n + 1);
    for (int i = 1; i <= n; i++) {
      if ((s[i] - '0') % p == 0) {
        pre[i] = pre[i - 1] + i;
        cnt[i] = cnt[i - 1] + 1;
      } else {
        pre[i] = pre[i - 1];
        cnt[i] = cnt[i - 1];
      }
    }
    int q;
    cin >> q;
    while (q--) {
      int l, r;
      cin >> l >> r;
      cout << (pre[r] - pre[l - 1]) - (cnt[r] - cnt[l - 1]) * (l - 1) << '\n';
    }
  } else {
    int q;
    cin >> q;
    vector<array<int, 3>> queries(q);
    for (int i = 0; i < q; i++) {
      cin >> queries[i][0] >> queries[i][1];
      queries[i][2] = i;
    }

    vector<int> com;
    com.push_back(0);
    int cur = 0, base = 1;
    vector<int> m(n + 1);
    reverse(s.begin() + 1, s.end());

    for (int i = 1; i <= n; i++) {
      (cur = (cur % p) + ((int(s[i] - '0') % p) * (base % p)) % p) %= p;
      com.push_back(cur);
      m[i] = cur;
      (base *= 10) %= p;
    }

    sort(com.begin(), com.end());
    com.erase(unique(com.begin(), com.end()), com.end());
    int BLOCK_SIZE = sqrt(n);
    sort(queries.begin(), queries.end(), [&] (array<int, 3> i, array<int, 3> j) {
      return pair<int, int>{i[0] / BLOCK_SIZE, i[1]} < pair<int, int>{j[0] / BLOCK_SIZE, j[1]};
    });

    vector<int> ans(q);
    auto id = [&] (int val) -> int {
      return lower_bound(com.begin(), com.end(), val) - com.begin() + 1;
    };

    vector<int> cnt(com.size() + 1);
    int t = 0;
    auto add = [&] (int idx) -> void {
      t += cnt[id(m[idx])];
      cnt[id(m[idx])] += 1;
    };
    auto rem = [&] (int idx) -> void {
      cnt[id(m[idx])] -= 1;
      t -= cnt[id(m[idx])];
    };
    int cur_l = 1, cur_r = 0;
    for (auto p : queries) {
      int l = p[0], r = p[1], index = p[2];
      l -= 1;
      while (cur_l > l) {
        cur_l -= 1;
        add(cur_l);
      }
      while (cur_r < r) {
        cur_r += 1;
        add(cur_r);
      }
      while (cur_l < l) {
        rem(cur_l);
        cur_l += 1;
      }
      while (cur_r > r) {
        rem(cur_r);
        cur_r -= 1;
      }
      ans[index] = t;
    }
    for (int i = 0; i < q; i++) {
      cout << ans[i] << '\n';
    }
  }
}

