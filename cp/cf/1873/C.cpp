/**
 * File              : C.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 21.09.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </home/distiled/templates/debug.h>
#else
#define dbg(x...)
#endif

#define int           long long
#define all(x)        x.begin(), x.end()
#define sz(x)         (int) x.size()
#define MOD           1000000007
#define endl          '\n'
#define MULTI         int t;cin>>t;while(t--)
#define INF           (int) 1e18
#define MAXN          (int) 1e6 + 5

int nxt() {int n; cin >> n; return n;}

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  MULTI {
    int ans = 0;
    for(int i = 1; i <= 10; i++) {
      string s; cin >> s; s = " " + s;
      for(int j = 1; j <= 10; j++) {
        if(s[j] != 'X') continue;  
        if(i == 1 || i == 10 || j == 10 || j == 1) {ans++; continue;}
        if(((i == 2 || i == 9) && j >= 2 && j <= 9) || ((j == 2 || j == 9) && i >= 2 && i <= 9)) {ans += 2; continue;}
        if(((i == 3 || i == 8) && j >= 3 && j <= 8) || ((j == 3 || j == 8) && i >= 3 && i <= 8)) {ans += 3; continue;}
        if(((i == 4 || i == 7) && j >= 4 && j <= 7) || ((j == 4 || j == 7) && i >= 4 && i <= 7)) {ans += 4; continue;}
        if(((i == 5 || i == 6) && j >= 5 && j <= 6) || ((j == 5 || j == 6) && i >= 5 && i <= 6)) {ans += 5; continue;}
      }
    }
    cout << ans << endl;
  }  
}

