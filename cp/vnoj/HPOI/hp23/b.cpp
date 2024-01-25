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
  string s; cin >> s; int cnt = 0;
  for(char i : s) {
    if(i >= '0' && i <= '9') cnt++;
  }
  cout << cnt << '\n';
}

