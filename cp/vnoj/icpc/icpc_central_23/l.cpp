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
#define pb             push_back
#define all(x)         x.begin(), x.end()
#define sz(x)          (int) x.size()
#define endl           '\n'
#define MULTI          int t;cin>>t;while(t--)
inline int nxt() { int n; cin >> n; return n; }

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  vector<string> t = {"Welcome", "Hue", "University", "of", "Sciences"};
  vector<bool> check(5, 0);
  string s; 
  bool ans = true;
  while(cin >> s) {
    ans = true;
    for(int i = 0; i < 5; i++) {
      if(s == t[i]) {
        check[i] = true;
      }
      if(!check[i]) ans = false;
    }
  }
  cout << (ans ? "Yes" : "No");
}



