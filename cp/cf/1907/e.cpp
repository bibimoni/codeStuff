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

const int N = 10;

int dp[N];

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    memset(dp, 0, sizeof dp);
    int n; cin >> n;
    for(int a = 0; a <= 9; a++) {
      for(int b = 0; b <= 9; b++) {
        for(int c = 0; c <= 9; c++) {
          if(a + b + c < 10)
          dp[a + b + c]++;
        }
      }
    }
    int ans = 1;
    while(n) {
      ans *= dp[n % 10];
      n /= 10;
    }
    cout << ans << '\n';
  }
}


