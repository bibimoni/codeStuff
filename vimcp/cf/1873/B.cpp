/**
 * File              : B.cpp
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
    int n; cin >> n;
    int tmp = 0;
    int a[n]; for(int i = 0; i < n; i++) cin >> a[i];
    int ans = 0, curr = 1;;
    for(int i = 0; i < n; i++) {
      a[i]++;
      for(int j = 0; j < n; j++) {
        curr *= a[j];
      }
      a[i]--;
      ans = max(ans, curr);
      curr = 1;
    }
    cout << ans << endl;
  }  
}

