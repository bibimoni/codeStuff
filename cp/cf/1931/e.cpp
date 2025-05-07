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
#define int            long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    int a[n + 1];
    vector<pair<int, int>> b(n);
    vector<int> items;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      int tmp = a[i], cntZero = 0, len = 0;
      bool can = true;
      while(tmp) {
        if(can) 
          cntZero += (tmp % 10 == 0);
        if(tmp % 10 != 0)
          can = false;
        len++;
        tmp /= 10;
      }
      b[i - 1] = {len, cntZero};
    }
    sort(b.begin(), b.end(), [&] (pair<int, int> i, pair<int, int> j) {
      return i.second > j.second;
    });
    int ans = 0;
    for(int i = 0; i < n; i++) {
      if(i % 2 == 0)
        b[i] = {b[i].first - b[i].second, 0ll};
      else if(i < n - 1)
        b[i + 1] = {b[i + 1].first - b[i + 1].second, 0ll};
      if(i < n - 1)
        b[i + 1] = {b[i].first + b[i + 1].first, 0ll};
    }
    cout << (b[b.size() - 1].first >= m + 1 ? "Sasha\n" : "Anna\n");
  }
}


