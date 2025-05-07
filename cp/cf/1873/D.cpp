/**
 * File              : D.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 21.09.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </home/distiled/templates/debug.h>
#else
#define dbg(x...)
#endif

#define int           long long
#define all(x)        x.begin(), x.end()
#define sz(x)         (int) x.size()
#define MOD           1000000007
#define endl          '\n'
#define MULTI         int t;cin>>t;while(t--)
#define INF           (int) 1e18
#define MAXN          (int) 1e6 + 5

int nxt() {int n; cin >> n; return n;}

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  MULTI {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> b;
    for(int i = 0; i < n; i++) {
      if(s[i] == 'B') b.push_back(i);
    }
    int ans = 0;
    int m = sz(b); 
    int i = 0, j = 1; 
    if(m == 1) {
      cout << 1 << endl; continue;
    }
    while(i < m) {
      if(i == m || j == m) break;
      int curr = b[i]; ans++;
      while(j < m) {
        if(b[j] - curr + 1 <= k) {
          j++;
          if(j == m) break;
        }
        else {
          i = j;
          break;
        }
      }
    }
    cout << ans << endl;
  }  
}

