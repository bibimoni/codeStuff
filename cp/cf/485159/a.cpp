// time-limit: 10000
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

const int N = 5e6 + 5;

vector<int> mPrime(N, 0);
int dp[N];

void solve(int n) {
  mPrime[1] = 1;
  for(int i = 2; i * i <= n; i++) {
    if(!mPrime[i]) {
      mPrime[i] = i; 
      for(int j = i * i; j <= n; j += i) {
        if(!mPrime[j]) mPrime[j] = i;
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    if(!mPrime[i]) mPrime[i] = i;
  }
  for(int i = 1; i <= n; i++) {
    int tmp = i, x = 1;
    while(tmp != 1) {
      int p = mPrime[tmp], c = 0;
      dbg(p, tmp);
      while(tmp % p == 0) {
        tmp /= p;
        c ^= 1;
      }
      if(c) x *= p;
    }
    dp[x]++; 
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    ans += dp[i] * (dp[i] - 1) * (dp[i] - 2) / 6;
  }
  cout << ans;
}
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n; cin >> n;
  solve(n);
} 


