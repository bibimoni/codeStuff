/**
 * File              : binary.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 03.10.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </home/distiled/templates/debug.h>
#else
#define dbg(x...)
#endif

#define int            long long
#define pb             push_back
#define all(x)         x.begin(), x.end()
#define sz(x)          (int) x.size()
#define makeUnique(x)  sort(all(x)); x.erase(unique(all(x)), x.end());
#define endl           '\n'
#define MULTI          int t;cin>>t;while(t--)
const int 
      MAXN = (int) 1e6 + 5, 
      INF = (int) 1e18, 
      MOD = (int) 1e9 + 7; //998244353
inline int nxt() { int n; cin >> n; return n; }

signed main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  freopen("BINARY.INP", "r", stdin);
  freopen("BINARY.OUT", "w", stdout);
  string s; cin >> s;
  int n = sz(s);
  s = " " + s;
  int pre[n + 1], nxt0[n + 1]; pre[0] = 0;
  for(int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + (s[i] == '1');
  }
  int ans = 0;
  for(int i = 1; i < n; i++) {
    dbg(i);
    if(s[i] == '1') continue;
    for(int j = i; j <= n; j++) {
      if(s[j] == '0' && ((pre[j] - pre[i - 1]) % 2 == 1)) {
        ans++;
      }
    }
  } 
  cout << ans;
}

