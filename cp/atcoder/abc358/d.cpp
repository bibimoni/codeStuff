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
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(b.begin(), b.end());
  multiset<int> st(a.begin(), a.end());
  int ans = 0;
  auto ptr = st.begin();
  for (int i = 0; i < m; i++) {
    if (ptr == st.end()) {
      ans = -1;
      break;
    }
    while (*ptr < b[i] && next(ptr) != st.end()) {
      ptr = next(ptr);
    }
    if (*ptr < b[i]) {
      ans = -1;
      break;
    }
    ans += *ptr;
    ptr = next(ptr);
  }
  cout << ans << '\n';
} 


