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
    int n; cin  >> n;
    vector<pair<int, int>> a(n);
    int sum = 0;
    vector<int> pre(n);
    for(int x, i = 0; i < n; i++) {
      cin >> x;
      a[i] = {x, i};
      sum += x;
    }
    if(n == 1) {
      cout << "0\n";
      continue;
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) {
      pre[i] = (i > 0 ? pre[i - 1] : 0) + a[i].first;
    }
    vector<int> ans(n);
    int posLess = n - 1;
    for(int i = n - 1; i >= 0; i--) {
      auto [e, j] = a[i];
      ans[j] = i;
      if(i == n - 1) continue;
      //dbg(posLess);
      if(pre[i] < a[i + 1].first) posLess = i;
      ans[j] += posLess - i;      
    }
    for(int i : ans) cout << i << ' ';
      cout << '\n';
  }
}


 