/**
 * File              : I.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 12.08.2023
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
    int n; cin >> n;
    vector<pair<int, int>> a(n); 
    for(int i = 0; i < n; i++) a[i] = {nxt(), i + 1};
    sort(all(a), greater<pair<int, int>>());
    int ans = 0;
    vector<int> ret(n + 1);
    ret[0] = 0;
    int currPos = 1;
    for(int i = 0; i < n; i++) {
      ans += a[i].first * 2 * currPos;
      ret[a[i++].second] = currPos;
      if(i == n) break;
      ans += a[i].first * 2 * currPos;
      ret[a[i].second] = -currPos;
      currPos++;
    }
    cout << ans << endl;
    for(int i : ret) cout << i << ' '; cout << endl;
  }
}

