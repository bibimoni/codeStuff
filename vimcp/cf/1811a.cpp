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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, d; cin >> n >> d;
    string s; cin >> s;
    int idx = n - 1;
    for(int i = 0; i < n; i++) {
      if(s[i] - '0' < d) {
        idx = i - 1;
        break;
      }
    }
    //dbg(idx);
    for(int i = 0; i <= idx; i++) cout << s[i];
    cout << d;
    for(int i = idx + 1; i < n; i++) cout << s[i];
    cout << '\n';
  }
}

