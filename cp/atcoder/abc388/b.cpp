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
#define int int64_t 

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, d;
  cin >> n >> d;
  vector<int> t(n), l(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i] >> l[i];
  }
  for (int k = 1; k <= d; k++) {
    for (int i = 0; i < n; i++) {
      l[i] += 1;
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&] (int i, int j) {
      return l[i] * t[i] > l[j] * t[j];
    });
    cout << l[p[0]] * t[p[0]] << '\n';
  }
}


