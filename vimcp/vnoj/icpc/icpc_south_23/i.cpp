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
#define pb             push_back
#define all(x)         x.begin(), x.end()
#define sz(x)          (int) x.size()
#define endl           '\n'
#define MULTI          int t;cin>>t;while(t--)
inline int nxt() { int n; cin >> n; return n; }

const int MOD = (int) 1e9 + 7;

int add(int num, int val) {
  num += val;
  if(num < 0) {
    num += MOD;
  }
  else if(num >= MOD) {
    num -= MOD;
  }
  return num;
}

int fpow(int a, int b) {
  if(b == 0) return 1;
  int tmp = fpow(a, b / 2);
  if(b & 1) return (a * tmp * tmp) % MOD;
  return (tmp * tmp) % MOD;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n; cin >> n;
  int a[n]; for(int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  vector<int> dp(5011), dp1(5011);
  dp[0] = 1;
  int res = 0;
  for(int i = 0; i < n; i++) {
    if(i >= 2) {
      res += fpow(2ll, i) - 1 - i; 
      for(int j = 1; j <= a[i]; j++) {
        res = add(res, add(-dp[j], dp1[j])); 
      }
    }
    for(int j = 5000; j >= a[i]; j--) {
      dp[j] = add(dp[j], dp[j - a[i]]);
    }
    dp1[a[i]]++;
  }
  cout << res;
}



