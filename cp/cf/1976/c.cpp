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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + m + 2);
    for(int i = 1; i <= n + m + 1; i++)
      cin >> a[i];
    vector<int> b(n + m + 2);
    for(int i = 1; i <= n + m + 1; i++)
      cin >> b[i];  
    vector<int> pro, te;
    int sp = 0, st = 0;
    vector<int> mark(n + m + 1, 0);
    for(int i = 1; i <= n + m + 1; i++) {
      if(a[i] > b[i] && pro.size() < n) {
        pro.push_back(i);
        sp += a[i];
        st += a[i];
      }
      else if(a[i] < b[i] && te.size() < m) {
        te.push_back(i);
        st += b[i];
        sp += b[i];
      }
      else if(pro.size() == n) {
        te.push_back(i);
        st += b[i];
        sp += b[i];
      }
      else {
        pro.push_back(i);
        sp += a[i];
        st += a[i];
      }
    }
    dbg(pro, te);
    vector<int> ans(n + m + 2);
    for(int i = 1; i <= n + m + 1; i++) {
      auto t = lower_bound(pro.begin(), pro.end(), i);
      if(t == pro.end()) {
        ans[i] = sp - a[i];
      }
      else {
        ans[i] = st - b[i];
      }
    }
    for(int i = 1; i <= n + m + 1; i++) {
      cout << ans[i] << " \n"[i == n + m + 1];
    }
  }
}


