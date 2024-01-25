/**
 * File              : vcp23_h.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 02.08.2023
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
  int n, ans = 0; cin >> n;
  priority_queue<int> Q;
  for(int i = 0, x; i < n; i++) {
    cin >> x;
    if(!Q.empty() && Q.top() > x) {
      ans += Q.top() - x;
      Q.pop();
      Q.push(x);
    }
    Q.push(x);
  }
  cout << ans;
}

