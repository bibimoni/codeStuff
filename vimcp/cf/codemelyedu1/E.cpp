/**
 * File              : E.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 09.08.2023
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
  MULTI {
    int n, H; cin >> n >> H;
    int a[n]; for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<int>());
    if(a[0] >= H) {
      cout << 1 << endl; continue;
    }
    if(a[0] + a[1] >= H) {
      cout << 2 << endl; continue;
    }
    int cnt = H / (a[0] + a[1]);
    if(cnt * (a[0] + a[1]) >= H) {
      cout << 2 * cnt << endl;
      continue;
    }
    if(cnt * (a[0] + a[1]) + a[0] >= H) {
      cout << 2 * cnt + 1 << endl;
      continue;
    }
    if((cnt + 1) * (a[0] + a[1]) >= H) {
      cout << 2 * cnt + 2 << endl;
    }
  }
}
