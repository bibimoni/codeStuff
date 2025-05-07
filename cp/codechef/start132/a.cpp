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
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    vector<int> b(m);
    for(int i = 0; i < m; i++) {
      cin >> b[i];
    }
    sort(b.begin(), b.end(), greater<int>());
    if(n < 4 || m < 4 || n + m < 11) {
      cout << "-1\n";
      continue;
    }
    int ans = 0;
    for(int i = 0; i < 4; i++) 
      ans += a[i] + b[i];
    vector<int> c;
    for(int i = 4; i < n; i++)
      c.push_back(a[i]);
    for(int i = 4; i < m; i++)
      c.push_back(b[i]);
    sort(c.begin(), c.end(), greater<int>());
    for(int i = 0; i < 3; i++)
      ans += c[i];
    cout << ans << '\n';
  }
}


