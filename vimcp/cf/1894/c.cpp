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
#define all(x)         x.begin(), x.end()

int update(int i, int n) {
  if(i < 0) {
    i += n;
  }
  return i;
}

const int N = 2e5 + 5;
int a[N];
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt; cin >> tt;
  while(tt--) {
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    int curr = n - 1, cnt = 0;
    vector<bool> check(n, false);
    bool ok = true; 
    while(cnt < k) {
      if(a[curr] > n) {
        ok = false; 
        break;
      }
      if(check[curr]) {
        break;
      }
      cnt++;
      check[curr] = true;
      curr = update(curr - a[curr], n);
    }
    cout << (ok ? "Yes" : "No") << '\n';
  }
}


