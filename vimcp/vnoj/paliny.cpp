/**
 * File              : paliny.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 17.09.2023
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

const int BASE = 31;
int h[MAXN], r[MAXN], power[MAXN];

int getH(int i, int j) {
  return (h[j] - h[i - 1] * power[j - i + 1] + MOD * MOD) % MOD;
}
int getR(int i, int j) {
  return (r[i] - r[j + 1] * power[j - i + 1] + MOD * MOD) % MOD;
}
bool isPalin(int i, int j) {
  return (getH(i, j) == getR(i, j));
}

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n; string s; cin >> n >> s;
  for(int i = 1; i <= n; i++) {
    h[i] = (h[i - 1] * BASE + s[i] - 'a') % MOD;
  }
  for(int i = n; i >= 1; i--) {
    r[i] = (r[i + 1] * BASE + s[i] - 'a') % MOD;
  }
  power[0] = 1;
  for(int i = 1; i <= n; i++) power[i] = (power[i - 1] * BASE) % MOD;
  int ans = 1;
  for(int i = 1; i <= n; i++) {
    int l = 0, r = min(i, n - i);
    while(l <= r) {
      int mid = (l + r) >> 1;
      if(isPalin(i - mid + 1, i + mid)) {
        ans = max(ans, mid << 1);
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
  }
}

