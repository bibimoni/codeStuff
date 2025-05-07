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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> pre(n + 1, 0);
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      pre[i] = pre[i - 1] + a[i];
    }
    int id = -1;
    int curr = 1;
    for(int i = 1; i <= n; i++) {
      if(a[i] == 1 && id == -1) {
        curr += a[i];
        id = i;
      }
      else if(id != -1) {
        if(curr >= a[i])
          curr += a[i];
        else {
          id = -1;
          curr = 1;
        }
      }
    }
    if(id == -1) {
      cout << "NO\n";
      continue;
    }
    bool ok = true;
    int sum = pre[n] - pre[id - 1] + 1;
    for(int i = id - 1; i >= 1; i--) {
      if(sum < a[i]) {
        ok = false;
        break;
      }
      sum += a[i];
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}


