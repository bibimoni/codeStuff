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
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    map<int, int> f;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      f[a[i]]++;
    }
    int nextMex = 0;
    while(f[nextMex]) nextMex++;
    a[n] = nextMex;
    k--;
    k %= (n + 1);
    k = n - k;
    int cnt = 0;
    for(int i = k; i <= n && cnt < n; i++) cout << a[i] << ' ', cnt++;
    for(int i = 0; i <= n && cnt < n; i++) cout << a[i] << ' ', cnt++;
    
    cout << '\n';
  }
}


