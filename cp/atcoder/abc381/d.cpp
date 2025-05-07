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
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  auto find = [&] (int beg) {
    
    int go = 0;
    vector<int> mark(n + 1, 0);
    if (beg == 2) {
      mark[a[1]] = 1;
    }
    int last = mark[a[beg - 1]];
    for (int i = beg; i < n; i += 2) {
      last = max(last, mark[a[i]]);
      if (a[i] == a[i + 1]) {
        go += 2;
        ans = max(ans, min(go, ((i + 1 - last) / 2) * 2));
        // dbg(go, ans, mark[a[i]], i, last)
      } else {
        go = 0;
      }
      mark[a[i + 1]] = i;
      mark[a[i]] = i;
    }
  };
  find(1);
  find(2);
  cout << ans << "\n";
}


