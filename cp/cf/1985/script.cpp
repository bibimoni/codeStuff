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
  cout << "1\n200000 200000\n";
  int n = 2e5;
  for(int i = 0; i < n; i++) {
    cout << (int) 2e5 << " \n"[i == n - 1];
  }
  for(int i = 0; i < n; i++) {
    cout << 1 << " \n"[i == n - 1];
  }
}

