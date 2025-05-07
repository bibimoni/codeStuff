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
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    vector<string> a(n);
    r--; c--;
    bool can = false, fast = false;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      for(int j = 0; j < m; j++) {
        can |= (a[i][j] == 'B');
        if(i == r && j == c && a[i][j] == 'B') {
          fast = true;
        } 
      }
    }
    if(!can) {
      cout << "-1\n";
      continue;
    }
    if(fast) {
      cout << "0\n";
      continue;
    }
    bool one = false;
    for(int i = 0; i < n; i++) {
      one |= a[i][c] == 'B';
    }
    for(int i = 0; i < m; i++) {
      one |= a[r][i] == 'B';
    }
    if(one) {
      cout << "1\n";
    }
    else {
      cout << "2\n";
    }
  }
}

