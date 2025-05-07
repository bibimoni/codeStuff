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
#define int int64_t 

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  const int N = 502;
  vector<int> off(N);
  off[1] = 1;
  off[2] = 2;
  off[3] = 3;
  for (int i = 4, j = 2; i < N; i += 2, j++) {
    off[i] = off[i - 1] + j;
    off[i + 1] = off[i] + j;
  }
  while (tt--) {
    int n;
    cin >> n;
    cout << off[n] << '\n';
  }
}


