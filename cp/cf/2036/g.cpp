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
    int l = 1, r = n;
    vector<int> ans;
    auto ask = [&] (int l, int r) -> int {
      cout << "xor " << l << ' ' << r << '\n';
      cout.flush();
      int ret;
      cin >> ret;
      return ret;
    };
    auto find_ans = [&] (auto &&self, int l, int r) -> void {
      int mid = (l + r) >> 1;
      int ans_l = ask(l, mid);
      int ans_r = ask(mid + 1, r);
      if (ans_l != 0) {
        self(self, l, mid);
      } 
      if (ans_r != 0) {

      }
    };
    int mid = n / 2;
  }
}

