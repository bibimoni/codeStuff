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
  // freopen("final_product_chapter_1_input.txt", "r", stdin);
  // freopen("final_product_chapter_1_output.txt", "w", stdout);
  int tt;
  cin >> tt;
  for (int t = 1; t <= tt; t++) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    // chi phi cac subarray xor != 0 la do dai
    // chi phi cac subarray xor == 0 la so phan tu khac khong - 1
    //  x1 0 x3 x4
    // |       |
    for (int i = 0; i < n; i++) {
    }
    cout << "Case #" << t << ": " << ans << '\n';
  }
}
