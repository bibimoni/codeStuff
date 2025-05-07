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

#define int            long long
#define all(x)         x.begin(), x.end()

const int INF = (int) 1e18;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n; cin >> n;
  int a[n], ans = 0, curr = INF;
  for(int i = 0; i < n; i++) {
    cin >> a[i];  
  }
  for(int i = 0; i < n - 1; i++) {
    for(int j = i + 1; j < n; j++) {
      ans = max(ans, a[j] - a[i]);
    }
  }
  cout << ans;
}

