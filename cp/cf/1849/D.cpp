/**
 * File              : D.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 28.07.2023
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
  int ans = 0;
  int n; cin >> n;
  int a[n + 1], pre[n + 1];
  bool check[n + 1]; 
  memset(check, false, sizeof(check));
  for(int i = 1; i <= n; i++) cin >> a[i];
  check[0] = true;
  for(int i = 1; i <= n; i++) 
    pre[i] = pre[i - 1] + (a[i] == 0);
  for(int i = 1; i <= n; i++) {
    if(a[i]) {
      int l = i, r = n, pos = i;
      while(l <= r) {
        int mid = (l + r) >> 1;
        if(pre[mid] - pre[i - 1] == 0) {
          l = mid + 1;
          pos = mid;
        }
        else {
          r = mid - 1;
        }
      }
      dbg(pos);
      int cnt2s = 0;
      for(int j = i; j <= pos; j++) {
        cnt2s += (a[j] == 2);
      }
      if(cnt2s) {
        for(int j = i - 1; j <= pos + 1; j++) {
          check[j] = true;
        }
      }
      else if(check[i - 1]) {
        for(int j = i; j <= pos + 1; j++) {
          check[j] = true;
        }
      }
      else {
        for(int j = i - 1; j <= pos; j++) {
          check[j] = true;
        }
      }
      ans++;
      i = pos;
    }
  }
  for(int i = 1; i <= n; i++) {
    ans += (check[i] == false);
  }
  cout << ans;
}

