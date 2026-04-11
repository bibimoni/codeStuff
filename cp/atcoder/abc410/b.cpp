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
  int n, q;
  cin >> n >> q;
  vector<int> boxes(n + 1);
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    if (x > 0) {
      boxes[x] += 1;
      cout << x << ' ';
    } else {
      int box = min_element(boxes.begin() + 1, boxes.end()) - boxes.begin();
      boxes[box] += 1;
      cout << box << ' ';
    }
  }
}
