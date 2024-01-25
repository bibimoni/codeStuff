/**
 * File              : B.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 08.08.2023
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
  int n, k; cin >> n >> k;
  int a[n + 1], b[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for(int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  int ans = 0, pre[n + 1]; pre[0] = 0;
  for(int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + a[i] * b[i];
  }
  for(int i = 1; i <= n; i++) {
    int u = a[i], v = b[i];
    int tmp = k;
    if(v > u) swap(u, v);
    if(v + k > u) {
      k -= u - v;
      v = u;
      v += (k / 2) + (k & 1);
      u += (k / 2);
    }
    else {
      v += k;
    }
    k = tmp;
    dbg(u, v, i);
    ans = max(ans, pre[i - 1] + pre[n] - pre[i] + u * v);
  }
  cout << ans;
}

