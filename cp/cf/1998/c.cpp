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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i].first;
    }
    multiset<int> zero, one;
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i].second;
    }
    int ans = 0;
    int mid = (n + 1) / 2;
    auto median = [&] () -> int {
      int m = n / 2;

    };
    if (b[mid] == 1) {

    } else {

    }
  }
}


