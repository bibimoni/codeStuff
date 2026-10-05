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
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
    sort(arr.begin(), arr.end(), greater<>());
    if (arr.size() > 3) {
      arr.pop_back();
    }
    
    if (arr.size() == 3) {
      cout << arr[2] << '\n';
    }
  }
}
