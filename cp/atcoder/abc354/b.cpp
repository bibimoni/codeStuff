// time-limit: 3000
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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<string, int>> a(n);
  int t = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    t += a[i].second;
  }
  sort(a.begin(), a.end());
  cout << a[t % n].first;
}


