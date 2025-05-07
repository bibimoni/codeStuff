/**
 * File              : A.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 14.10.2023
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
int n;
map<int, int> f[101][2];
string s;
int dp(int i, int j, int state, string curr) {
  if(i == n) {
    if(state) {dbg("correct", curr);}
    else {dbg("wrong", curr, state, j);}
    return (state == true);
  }
  if(f[j][state][i] > 0) return f[j][state][i];
  int res = 0;
  for(char c : {'0', '1'}) {
    if(c == s[j]) {
      if(state) {
        if(j == sz(s) - 1) {
          continue;
        }
        dbg("same", i, j, s[j], c, curr);
        (res += dp(i + 1, j + 1, state, curr + c)) %= MOD;
      }
      else {
        if(j == sz(s) - 1) {
          state = true;
        }
        dbg("same", i, j, s[j], c, curr);
        (res += dp(i + 1, j + 1, state, curr + c)) %= MOD;
      }
    }
    else {
      dbg("diff", j, s[j], c, curr);
      (res += dp(i + 1, 0, state, curr + c)) %= MOD;
    }
  }
  return f[j][state][i] = res;
}
signed main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cin >> n >> s;
  cout << dp(0, 0, false, "");
}

