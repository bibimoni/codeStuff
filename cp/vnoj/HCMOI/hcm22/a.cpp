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
  int n; cin >> n;
  int a[n + 1][n + 1]; bool ok = true;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) {
      cin >> a[i][j];
      if(a[i][j] < 0) ok = false;
    }
  if(!ok) {
    cout << "NO\n";
    return 0;
  }
  vector<int> sum(n + 1, 0);
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      sum[i] += a[i][j];
    }
  }
  ok = true; int cnt = 0;
  for(int i = 1; i <= n; i++) {
    if(2 * a[i][i] < sum[i]) {
      ok = false;
      break;
    }
    else if(2 * a[i][i] > sum[i]) {
      cnt++;
    }
  }
  if(!ok || cnt == 0) {
    cout << "NO\n";
  }
  else {
    cout << "YES\n" << cnt << '\n';
  }
}

