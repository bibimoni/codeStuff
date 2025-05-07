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
    int l, r;
    cin >> l >> r;
    auto find = [&] (int mx) -> int {
      int nxt = 0;
      bool ge = false;
      for (int j = 30; j >= 0; j--) {
        int b = ((mx >> j) & 1) ^ 1;
        int bl = ((l >> j) & 1);
        int t = nxt | (b << j);
        if (t > mx) {
          b ^= 1;
        } 
        if (!ge && bl == 1 && b == 0) {
          b ^= 1;
        }
        if (b == 1 && bl == 0) {
          ge = true;
        }
        nxt |= b << j;
      }
      if (nxt == mx) {
        if (nxt - 1 >= l) {
          nxt -= 1;
        } else {
          nxt += 1;
        }
      } 
      return nxt;
    };
    auto calc = [&] (int v1, int v2, int v3) -> int {
      return (v1 ^ v2) + (v2 ^ v3) + (v1 ^ v3);
    };
    int a11 = find(r);
    vector<int> ans{l, r, a11};
    for (int k : {-1, 1}) {
      if (a11 + k != r && a11 + k >= l) {
        ans.push_back(a11 + k);
      }
    }
    auto find_2 = [&] (int mn) -> int {
      int nxt = 0;
      bool ge = false;
      for (int j = 30; j >= 0; j--) {
        int b = ((mn >> j) & 1) ^ 1;
        int bl = ((mn >> j) & 1);
        int t = nxt | (b << j);
        if (t > r) {
          b ^= 1;
        }
        if (!ge && bl == 1 && b == 0) {
          b ^= 1;
        }
        if (b == 1 && bl == 0) {
          ge = true;
        }
        nxt |= b << j;
      }
      if (nxt == mn) {
        if (nxt + 1 <= r) {
          nxt += 1;
        } else {
          nxt -= 1;
        }
      } 
      return nxt;
    };
    int a22 = find_2(l);
    for (int k : {-1, 1}) {
      if (a22 + k != l && a22 + k <= r) {
        ans.push_back(a22 + k);
      }
    }
    int cur = 0;
    vector<int> o;
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    do {
      int tmp = calc(ans[0], ans[1], ans[2]);
      if (tmp > cur) {
        cur = tmp;
        o = vector<int>{ans[0], ans[1], ans[2]};
      }
    } while (next_permutation(ans.begin(), ans.end()));
    cout << o[0] << ' ' << o[1] << ' ' << o[2] << '\n';
  }
}


