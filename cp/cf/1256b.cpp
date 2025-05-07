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
    int p[n]; vector<int> pos(n + 1, 0);
    for(int i = 0; i < n; i++) {
      cin >> p[i];
      pos[p[i]] = i;
    }
    int op = n - 1, j = 0;
    while(op > 0 && j < n) {
      int pos = j, minE = n + 1;
      for(int i = j; i < n; i++) {
        if(minE > p[i]) {
          minE = p[i];
          pos = i;
        }
      }
      if(j == pos) {
        j++;
        continue;
      }
      for(int i = pos - 1; i >= j; i--) {
        swap(p[i], p[i + 1]);
        op--;
        if(op == 0) break;
      }
      j = pos;
    }
    for(int i = 0; i < n; i++) {
      cout << p[i] << " \n"[i == n - 1];
    }
  }
}

