/**
 * File              : E.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 29.08.2023
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
#define rall(x)       x.rbegin(), x.rend()
#define sz(x)         (int) x.size()
#define __lcm(a, b)   (1ll * ((a) / __gcd((a), (b))) * (b))
#define YES           cout << "YES\n";
#define NO            cout << "NO\n";
#define mod           1000000007
#define endl          '\n'
#define TLE           ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI         int t;cin>>t;while(t--)
#define INF           (int) 1e18
#define MAXN          (int) 1e6 + 5

int nxt() {int n; cin >> n; return n;}

signed main() {
  TLE;
    string s; cin >> s;
    int cnt = 0;
    int n = sz(s);
    bool p[n][n];
    memset(p, false, sizeof(p));
    for(int i = 0; i < n; i++) p[i][i] = true;
    for(int j = 2; j <= n; j++) {
      for(int i = 0; i <= n - j; i++) {
        int g = j + i - 1;
        if(i == g - 1) {
          p[i][g] = (s[i] == s[g]);
        }
        else {
          p[i][g] = (s[i] == s[g] && p[i + 1][g - 1]);
        }
        if(p[i][g]) cnt++;
      }
    }
    dbg(cnt);
    double sum = 1;
    for(int i = 1; i <= 2; i++){
      sum = sum * (cnt - 2 + i) / i;
    }
    dbg(sum);
    cout << ((cnt <= 1) ? 1 : (int) sum);
 
}
