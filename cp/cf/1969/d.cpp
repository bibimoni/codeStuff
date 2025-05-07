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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0ll);
    sort(p.begin(), p.end(), [&] (int i, int j) {
      return a[i] < a[j];
    });
    int curr = 0, ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 1; i <= n; i++) {
      if(a[p[i]] < b[p[i]]) {
        curr -= a[p[i]];
        pq.push(b[p[i]]);
        while(pq.size() > k) {
          ans = max(ans, curr);
          curr += pq.top();
          ans = max(ans, curr);
          pq.pop();
        }
      }
    }
    cout << ans << '\n';
  }
}


