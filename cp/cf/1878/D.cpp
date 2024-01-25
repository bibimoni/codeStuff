/**
 * File              : D.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 28.09.2023
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
int cnt[MAXN] = {0};

signed main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  MULTI {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int l[k], r[k];
    for(int i = 0; i < k; i++) cin >> l[i], l[i]--;
    for(int i = 0; i < k; i++) cin >> r[i], r[i]--;
    int q; cin >> q;
    while(q--) {
      int x; cin >> x;
      cnt[--x] ^= 1;
    }
    for(int i = 0; i < k; i++) {
      int curr = 0;
      for(int j = l[i]; j <= (r[i] + l[i] - j); j++) {
        curr ^= cnt[j] ^ cnt[l[i] + r[i] - j];
        if(curr) {
          swap(s[j], s[r[i] + l[i] - j]);
        }
      } 
    }
    cout << s << endl;
  }    
}

