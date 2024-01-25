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

const int MOD = (int) 1e9 + 5, INF = (int) 2e9;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for(int val = -500; val <= 500; val++) {
    vector<int> tmp(all(a));
    for(int &x : tmp) {
      if(x > val) x = -INF; 
    }
    int maxVal = 0, currMax = 0, curr = 0, res = 0;
    for(int i : tmp) {
      curr = max(curr + i, i);
      currMax = ((curr + i > i) ? max(currMax, i) : i);
      if(curr > res) {
        maxVal = currMax;
        res = curr;
      }
    }
    ans = max(ans, res - maxVal);
  }
  cout << ans;
}



