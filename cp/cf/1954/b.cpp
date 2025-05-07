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
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = n;
    set<int> st;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      st.insert(a[i]);
    }
    if(st.size() == 1) {
      cout << "-1\n";
      continue;
    }
    int cnt = 1;
    for(int i = 1; i < n; i++) {
      if(a[i] != a[0]) {
        ans = min(ans, cnt);
        cnt = 0;
      }
      else {
        cnt++;
      }
    }
    ans = min(ans, cnt);
    cout << ans << '\n';
  }
}


