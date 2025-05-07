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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> pre_a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      pre_a[i] = pre_a[i - 1] + a[i];
    }
    vector<int> b(n + 1);
    vector<int> pre_b(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
      pre_b[i] = pre_b[i - 1] + b[i];
    }
    vector<int> c(n + 1);
    vector<int> pre_c(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      cin >> c[i];
      pre_c[i] = pre_c[i - 1] + c[i];
    }
    int tot = accumulate(a.begin(), a.end(), 0ll);
    int bound = (tot + 2) / 3;
    auto bs = [&] (vector<int> &pre) -> vector<int> {
      vector<int> ret(n + 1, -1);
      for (int idx = 1; idx <= n; idx++) {
        int l = idx, r = n;
        while (l <= r) {
          int m = (l + r) >> 1;
          if (pre[m] - pre[idx - 1] >= bound) {
            ret[idx] = m;
            r = m - 1;
          } else {
            l = m + 1;
          }
        }
      }
      return ret;
    };
    vector<int> idx_a(n + 1);
    vector<int> idx_b(n + 1);
    vector<int> idx_c(n + 1);
    idx_a = bs(pre_a);
    idx_b = bs(pre_b);
    idx_c = bs(pre_c);
    pair<int, int> ans_a{-1, -1};
    pair<int, int> ans_b{-1, -1};
    pair<int, int> ans_c{-1, -1};
    auto findAns = [&] (vector<char> &order) -> void {
      if (order[1] == 'A') {
        for (int i = 2; i < n; i++) {
          if (idx_a[i] == -1) {
            continue;
          }
          if (order[0] == 'B') {
            int sumB = pre_b[i - 1];
            int sumC = pre_c[n] - pre_c[idx_a[i]];
            if (sumB >= bound && sumC >= bound) {
              ans_b = {1, i - 1};
              ans_c = {idx_a[i] + 1, n};
              ans_a = {i, idx_a[i]};
              return;
            }
          } else {
            int sumC = pre_c[i - 1];
            int sumB = pre_b[n] - pre_b[idx_a[i]];
            if (sumB >= bound && sumC >= bound) {
              ans_c = {1, i - 1};
              ans_b = {idx_a[i] + 1, n};
              ans_a = {i, idx_a[i]};
              return;
            }
          }
        }
      } else if (order[1] == 'B') {
        for (int i = 2; i < n; i++) {
          if (idx_b[i] == -1) {
            continue;
          }
          if (order[0] == 'A') {
            int sumA = pre_a[i - 1];
            int sumC = pre_c[n] - pre_c[idx_b[i]];
            if (sumA >= bound && sumC >= bound) {
              ans_a = {1, i - 1};
              ans_c = {idx_b[i] + 1, n};
              ans_b = {i, idx_b[i]};
              return;
            }
          } else {
            int sumC = pre_c[i - 1];
            int sumA = pre_a[n] - pre_a[idx_b[i]];
            if (sumA >= bound && sumC >= bound) {
              ans_c = {1, i - 1};
              ans_a = {idx_b[i] + 1, n};
              ans_b = {i, idx_b[i]};
              return;
            }
          }
        }
      } else {
        for (int i = 2; i < n; i++) {
          if (idx_c[i] == -1) {
            continue;
          }
          if (order[0] == 'A') {
            int sumA = pre_a[i - 1];
            int sumB = pre_b[n] - pre_b[idx_c[i]];
            if (sumA >= bound && sumB >= bound) {
              ans_a = {1, i - 1};
              ans_b = {idx_c[i] + 1, n};
              ans_c = {i, idx_c[i]};
              return;
            }
          } else {
            int sumB = pre_b[i - 1];
            int sumA = pre_a[n] - pre_a[idx_c[i]];
            if (sumA >= bound && sumB >= bound) {
              ans_b = {1, i - 1};
              ans_a = {idx_c[i] + 1, n};
              ans_c = {i, idx_c[i]};
              return;
            }
          }
        }
      }
    };
    vector<char> order = {'A', 'B', 'C'};
    do {
      findAns(order);
    } while (next_permutation(order.begin(), order.end()));
    
    if (ans_a != pair<int, int>{-1, -1}) {
      cout << ans_a.first << ' ' << ans_a.second << ' ';
      cout << ans_b.first << ' ' << ans_b.second << ' ';
      cout << ans_c.first << ' ' << ans_c.second << '\n';
    } else {
      cout << "-1\n";
    }
  }
}


