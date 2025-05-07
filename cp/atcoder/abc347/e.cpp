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
  int n, q;
  cin >> n >> q;
  vector<int> x(q + 1);
  for(int i = 1; i <= q; i++) {
    cin >> x[i];
  }
  vector<int> ans(n + 1);
  set<int> st;
  int curr = 0;
  for(int i = 1; i <= q; i++) {
    if(st.find(x[i]) == st.end()) {
      ans[x[i]] -= curr;
      st.insert(x[i]);
    }
    else {
      ans[x[i]] += curr;
      st.erase(x[i]);
    }
    curr += st.size();
  }
  for(int i : st) {
    ans[i] += curr;
  }
  for(int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
}


