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
  int m; 
  cin >> m;
  int s[m];
  set<int> st;
  for(int i = 0; i < m; i++) {
    cin >> s[i];
    st.insert(s[i]);
  }
  sort(s, s + m);
  int minE = s[0];
  bool ok = true;
  for(int i = 0; i < m; i++) {
    if(s[i] % minE != 0) {
      ok = false;
    }
  }
  if(!ok) {
    cout << "-1\n";
    return 0;
  }
  cout << m * 2 << '\n';
  for(int i = 0; i < m; i++) {
    cout << s[i] << ' ' << minE << ' ';
  }
}

