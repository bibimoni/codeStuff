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
  int n, m, k; 
  cin >> n >> m >> k;
  int r[m + 1], x[m + 1], y[m + 1], kx[n + 1], ky[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> kx[i] >> ky[i];
  }
  for(int i = 1; i <= m; i++) {
    cin >> r[i] >> x[i] >> y[i];
  }
  auto distance = [&] (int i, int j, int x2, int y2) {
    return (i - x2) * (i - x2) + (j - y2) * (j - y2);
  };
  bitset<1024> bs[n + 1];
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(distance(kx[i], ky[i], x[j], y[j]) < r[j] * r[j]) {
        bs[i].set(j, 1);        
      }
    }
  }
  while(k--) {
    int a, b;
    cin >> a >> b;
    bitset<1024> tmp = bs[a] & bs[b];
    cout << bs[a].count() + bs[b].count() - 2 * tmp.count() << '\n';
  }
}

