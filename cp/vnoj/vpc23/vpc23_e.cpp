/**
 * File              : vpc23_e.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 04.08.2023
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
  int n, p, q; cin >> n >> p >> q;
  int a[n];
  int offset = 0;
  int minOffset = INF;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    offset += a[i];
    minOffset = min(minOffset, offset);
  }
  if(minOffset > 0) {
    cout << -1; return 0;
  }
  if(offset >= 0) {
    int ans = 0;
    for(int i = 0; i < n; i++) {
      if(p <= q) break;
      if(a[i] < 0) {
        p -= min(p, -a[i]);
      }
      if(a[i] > 0) {
        p += a[i];
      }
      ans++;
    }
    if(p > q) cout << -1;
    else cout << ans;
    return 0;
  }
  int ans = 0;
  while(p + minOffset > q) {
    ans += n;
    p += offset;
  }
  for(int i = 0; i < n; i++) {
    if(p <= q) break;
    if(a[i] < 0) {
      p -= min(p, -a[i]);
    }
    if(a[i] > 0) {
      p += a[i];
    }
    ans++;
  }
  cout << ans;
}

