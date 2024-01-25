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
const int N = (int) 1e6;
int pref[N];
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n; cin >> n;
  for(int i = 1, x; i <= n; i++) {
    cin >> x;
    pref[i] = pref[i - 1] ^ x;
  }
  int S = 0;
  for(int i = 1; i <= n; i++) {
    S += pref[i] & (pref[n] ^ pref[i]);
  }
  cout << S << '\n';
}

