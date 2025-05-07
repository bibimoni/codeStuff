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
    string s;
    cin >> s;
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if ((st.size() == 0 && s[i] == '_') || s[i] == '(') {
        st.push(i);
      } else if ((st.size() > 0 && s[i] == '_') || s[i] == ')') {
        ans += i - st.top();
        st.pop();
      }
    }    
    cout << ans << '\n';
  }
}


