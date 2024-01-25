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
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    int a[n];
    map<int, int> f;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    if(n == 1) {
      cout << "1\n";
      continue;
    }
    else if(n == 2) {
      if(a[1] == a[2]) {
        cout << "3 3\n";
      }
      else {
        cout << "2 1\n";
      }
      continue;
    }
    if(n & 1) {
      int start = 3;
      for(int i = 1; i <= n; i++) {
        f[a[i]] += start;
        if(i == n / 2) start += 2;
        else if(i < n / 2) start += 4;
        else start -= 4;
      }
    }
    else {
      int start = 3;
      for(int i = 1; i <= n; i++) {
        f[a[i]] += start;
        if(i == n / 2) start -= 2;
        else if(i < n / 2) start += 4;
        else start -= 4;
      }
    }
    for(int i = 1; i <= n; i++) cout << f[a[i]] << ' ';
    cout << '\n';
  }
}

