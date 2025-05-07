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
#define MULTI          int tt;cin>>tt;while(tt--)
inline int nxt() { int n; cin >> n; return n; }

const int N = (int) 2e5 + 5;
vector<string> sizeAt[10];
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  //dp[i][sum]
  int n; cin >> n;
  vector<string> a(n);
  for(int i = 0; i < n; i++) {
    string t; cin >> t;
    a[i] = t;
  }
  sort(all(a), [&] (string b, string c) {
    return sz(b) > sz(c);
  });
  for(int i = 0; i < n; i++) {
    int currSum = 0, sum = 0;
    for(auto c : a[i]) {
      sum += (c - '0');
    }
    sizeAt[sz(a[i])].pb(a[i]);
  }
  int ans = 0;
  for(int l = 1; l <= 5; l++) {
    for(int r = 1; r <= 5; r++) {
      if((l + r) & 1) continue;
      int mid = (l + r) >> 1;
      map<int, int> dp;
      for(auto t : sizeAt[l]) {
        int sum = 0;
        for(int i = 0; i < sz(t); i++) {
          if(i < mid) sum += t[i] - '0';
          else sum -= (t[i] - '0');
        }
        dp[sum]++;
      }
      for(auto t : sizeAt[r]) {
        int sum = 0;
        for(int i = 0; i < sz(t); i++) {
          if(i + l < mid) sum -= (t[i] - '0');
          else sum += (t[i] - '0');
        }
        ans += dp[sum];
      }
    }
  }
  cout << ans;
}



