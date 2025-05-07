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
    string s;
    cin >> s;
    set<char> st;
    for(char c : s) 
      st.insert(c);
    vector<char> a;
    for(char c : st)
      a.push_back(c);
    vector<char> sym(26, 0);
    for(int i = 0; i < a.size(); i++) {
      sym[a[i] - 'a'] = a[a.size() - i - 1];
    }
    string ans = "";
    for(char c : s) {
      ans += sym[c - 'a'];
    }
    cout << ans << '\n';
  }
}


