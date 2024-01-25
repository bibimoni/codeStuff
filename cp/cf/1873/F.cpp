/**
 * File              : F.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 23.09.2023
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
    int n, k; cin >> n >> k;
    int ans = 0, a[n], h[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> h[i];
    for(int l = 0, r = 0, cur = 0; l < n;) {
      if(r < l) {
        r = l;
        cur = 0;
      }
      while(r < n && cur + a[r] <= k && (r == l || h[r - 1] % h[r] == 0)) {
        cur += a[r++];
      }
      ans = max(ans, r - l);
      cur -= a[l++];
    }
    cout << ans << '\n';
  }  
}

