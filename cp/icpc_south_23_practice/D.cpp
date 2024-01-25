/**
 * File              : D.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 14.10.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </home/distiled/templates/debug.h>
#else
#define dbg(x...)
#endif

#define int            long long
#define pb             push_back
#define all(x)         x.begin(), x.end()
#define sz(x)          (int) x.size()
#define makeUnique(x)  sort(all(x)); x.erase(unique(all(x)), x.end());
#define endl           '\n'
#define MULTI          int t;cin>>t;while(t--)
const int 
      MAXN = (int) 1e6 + 5, 
      INF = (int) 1e18, 
      MOD = (int) 1e9 + 7; //998244353
inline int nxt() { int n; cin >> n; return n; }

int d[MAXN] = {0};

void solve(int n, int k) {
  string t = "ACTG";
  int tn = (n - 1) / 2 + 1;
  for(int i = tn - 1; i >= 0; i--) {
    d[i] = k % 4;
    k /= 4;
  }
  if(k > 0) {
    cout << -1; return;
  }
  for(int i = 0; i < tn; i++) {
    cout << t[d[i]];
  }
  for(int i = (n & 1 ? tn - 2 : tn - 1); i >= 0; i--) {
    cout << t[d[i]];
  }
}

signed main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int n, k;
  cin >> n >> k; k--;
  solve(n, k);
}

