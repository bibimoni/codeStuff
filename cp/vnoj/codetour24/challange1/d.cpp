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

vector<array<int, 2>> dp;
const int INF = 2e9;

int memo(int i, int d1, int d2, int last1, int last2, 
  int n, int d, int k, vector<int> &a, vector<int> &b, vector<int> &t, string curr) {
  if(i == n + 1) {
    dbg(curr);
    return 0;
  }
  int prev = (d1 != 0); //A = 0, B = 1
  // if(dp[i][prev] != -1) {
  //   return dp[i][prev];
  // }
  int valA = (t[last1] == t[i] ? b[t[i]] : a[t[i]]);
  int valB = (t[last2] == t[i] ? b[t[i]] : a[t[i]]);  
  // dbg(i, valA, valB, last1, last2);
  int t1 = INF, t2 = INF;
  if(d2 + 1 <= d) {
    string tmp = curr + "A";
    t1 = valA + memo(i + 1, 0, d2 + 1, i, last2, n, d, k, a, b, t, tmp);
  }
  if(d1 + 1 <= d) {
    string tmp = curr + "B";
    t2 = valB + memo(i + 1, d1 + 1, 0, last1, i, n, d, k, a, b, t, tmp);
  }
  if(t1 >= t2) {
    return (dp[i][1] = t2); 
  }
  else {
    return (dp[i][0] = t1);
  }
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k, d;
    cin >> n >> k >> d;
    dp = vector<array<int, 2>>(n + 1, {-1, -1});
    vector<int> t(n + 1, 0);
    for(int i = 1; i <= n; i++) {
      cin >> t[i];
    }
    vector<int> a(k + 1, 0);
    for(int i = 1; i <= k; i++) {
      cin >> a[i];
    }
    vector<int> b(k + 1, 0);
    for(int i = 1; i <= k; i++) {
      cin >> b[i];
    }
    int ans = memo(1, 0, 0, -1, -1, n, d, k, a, b, t, "");
    cout << ans << '\n';
  }
}


