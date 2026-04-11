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
  freopen("final_product_chapter_1_input.txt", "r", stdin);
  freopen("final_product_chapter_1_output.txt", "w", stdout);
  int tt;
  cin >> tt;
  for (int t = 1; t <= tt; t++) {
    int n, a, b;
    cin >> n >> a >> b;
    cout << "Case #" << t << ": ";
    for (int i = 0; i < 2 * n - 1; i++) {
      cout << "1 ";
    }
    cout << b << '\n';
  }
}
