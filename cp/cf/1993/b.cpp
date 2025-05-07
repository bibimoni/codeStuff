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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (!any_of(a.begin(), a.end(), [&] (int v) { return v % 2 == 1; })) {
      cout << "0\n";
      continue;
    }
    sort(a.begin(), a.end());
    int largestOdd = -1;    
    int ans = 0;
    int idx = -1;
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] % 2 == 1) {
        largestOdd = a[i];
        idx = i;
        break;
      }
    }
    assert(idx != -1);
    for (int i = 0; i < n; i++) {
      if (a[i] % 2 == 0 && largestOdd >= a[i]) {
        ans += 1;
        largestOdd += a[i];
        idx = i;
      }
    }
    int currOdd = -1;
    for (int i = n - 1; i > idx; i--) {
      if (a[i] % 2 == 1) {
        continue;
      }
      if (a[i] <= largestOdd) {
        currOdd = largestOdd;
      }
      if (currOdd == -1) {
        ans += 2;
        largestOdd += a[i];
      } else {
        ans += 1;
      }
    }
    cout << ans << '\n';
  }
}


