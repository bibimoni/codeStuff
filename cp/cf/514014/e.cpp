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
    int n, s;
    cin >> n >> s;
    vector<int> b(n);
    vector<int> mark(301);
    for(int i = 0; i < n; i++) {
      cin >> b[i];
      mark[b[i]] = 1;
    }
    for(int i = 1; i <= 300 && s > 0; i++) {
      s -= (mark[i] ? 0 : i);
    }
    cout << (s == 0 ? "Yes\n" : "No\n");
  }
}

