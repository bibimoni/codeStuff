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

const int N = (int) 2e5 + 5;

int f[N];
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  auto sumDigit = [&] (int x) {
    int ret = 0;
    while(x) {
      ret += x % 10;
      x /= 10;
    }
    return ret;
  };
  f[0] = 0;
  for(int i = 1; i < N; i++) {
    f[i] = f[i - 1] + sumDigit(i);
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    cout << f[n] << '\n';
  }
}

