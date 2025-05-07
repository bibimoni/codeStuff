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

const int MOD = (int) 1e9 + 7;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  vector<int> dp(3e5 + 5, 0);
  dp[0] = dp[1] = 1;
  for(int i = 2; i <= (int) 3e5; i++) {
  	dp[i] = ((dp[i - 1] % MOD) + (2 * i - 2) % MOD * dp[i - 2] % MOD) % MOD;
 	}
  while(tt--) {
    int n, k;
    cin >> n >> k;
    int row = n;
    for(int i = 0; i < k; i++) {
    	int r, c;
    	cin >> r >> c;
    	row -= (2 - (r == c));
    }
    cout << dp[row] % MOD << '\n';
    //xet o i * i phu thuoc vao so move ket thuc tai (i - 1) * (i - 1) hoac (i - 2) * (i - 2)
    //dp[i - 2] * 2 * (i - 1)
  }
}


