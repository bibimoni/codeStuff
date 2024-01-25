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
#define all(x)         x.begin(), x.end();

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int x; cin >> x; bool check = false;
    if(x == 0) {
      cout << "1 1\n";
      continue;
    }
    int n = -1, m = -1;
    for(int i = 1; i * i <= (int) 2e9; i++) {
      int cnt0 = i * i - x;
      if(cnt0 <= 0) continue;
      int scnt0 = sqrt(cnt0);
      if(scnt0 * scnt0 == cnt0) {
        if(i / (i / scnt0) == scnt0) {
          n = i, m = i / scnt0;
          break;
        }
      }
    }
    if(n != -1 && m != -1) {
      cout << n << ' ' << m << '\n';
    } 
    else {
      cout << "-1\n";
    }
  }
}


