/**
 * File              : A.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 26.09.2023
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
#define pb             push_back()
#define all(x)         x.begin(), x.end()
#define sz(x)          (int) x.size()
#define make_unique(x) sort(all(x)); x.erase(unique(all(x)), x.end());
#define endl           '\n'
#define MULTI          int t;cin>>t;while(t--)
const int 
      MAXN = (int) 1e6 + 5, 
      INF = (int) 1e18, 
      MOD = (int) 1e9 + 7; //998244353
inline int nxt() { int n; cin >> n; return n; }

signed main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  MULTI {
    int n, k; cin >> n >> k;
    map<int, int> f;
    for(int i = 0; i < n; i++) {
      f[nxt()]++;
    }
    if(f[k] > 0) cout << "YES";
    else cout << "NO";
    cout << endl;
  } 
}

