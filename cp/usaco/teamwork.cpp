/**
 * File              : teamwork.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 31.07.2023
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
#define LG            25

int nxt() {int n; cin >> n; return n;}

int st[LG][MAXN], a[MAXN], dp[MAXN];

int query(int l, int r) {
  int k = __lg(r - l + 1);
  return max(st[k][l], st[k][r - (1 << k) + 1]);
}

signed main() {
  TLE;
  freopen("teamwork.in", "r", stdin);
  freopen("teamwork.out", "w", stdout);
  int n, k; cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    st[0][i] = a[i];
  }
  //making a sparse table to query the max element from L, R
  for (int j = 1; j < LG; ++j)
    for (int i = 1; i + (1 << j) - 1 <= n; ++i)
      st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
  dp[0] = 0, dp[1] = a[1];
  //dp[i] is the max score we can get at the i-th cow.
  for(int i = 2; i <= n; i++) {
    for(int j = 1; j <= k; j++) {
      if(i - j >= 0) {
        dp[i] = max(dp[i], dp[i - j] + j * query(i - j + 1, i));
      }
    }
  }
  cout << dp[n];
}

