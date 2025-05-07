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
  int n, w1, w2;
  cin >> n >> w1 >> w2;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  dbg(a);
  int ans = 0;
  for(int i = n - 5; i < n; i++) {
    vector<int> d;
    for(int j = 0; j < 5; j++) {
      d.push_back(a[(i + j) % n]);
    }
    dbg(d);
    sort(d.begin(), d.end());
    do {
      ans = max(ans, d[0] * w1 + d[4] * w2 + d[2] + d[3] * w2 + d[1] * w1);
    } while(next_permutation(d.begin(), d.end()));
    swap(w1, w2);
    sort(d.begin(), d.end());
    do {
      ans = max(ans, d[0] * w1 + d[4] * w2 + d[2] + d[3] * w2 + d[1] * w1);
    } while(next_permutation(d.begin(), d.end()));
  }
  cout << ans << '\n';
}


