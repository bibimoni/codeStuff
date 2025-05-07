/**
 * Author: distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  vector<int> cnt(m + 1), sum(m + 1);
  for(int i = 1; i <= n; i++) {
  	cin >> a[i];
    cnt[a[i]]++;
    if(a[i] > 1) {
      if(a[i] > a[i] + 1)
        sum[a[i]] += a[i - 1];
      else
        sum[a[i]] 
    }
  }
  int X = 0, ans = 0;
  for(int j = 0; j <= m; j++) {

  }
  cout << ans << '\n';
}

