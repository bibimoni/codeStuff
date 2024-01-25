/**
 * File              : H.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 12.08.2023
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
#define rall(x)       x.rbegin(), x.rend()
#define sz(x)         (int) x.size()
#define __lcm(a, b)   (1ll * ((a) / __gcd((a), (b))) * (b))
#define YES           cout << "YES\n";
#define NO            cout << "NO\n";
#define mod           1000000007
#define endl          '\n'
#define TLE           ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI         int t;cin>>t;while(t--)
#define INF           (int) 1e18
#define MAXN          (int) 1e6 + 5

int nxt() {int n; cin >> n; return n;}

signed main() {
  TLE;
  MULTI {
    int n; cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(a, a + n); 
    sort(b, b + n, greater<int>());
    for(int i : a) cout << i << ' '; cout << endl;
    for(int i : b) cout << i << ' '; cout << endl;
    int j = 0, i = 0, ans = 0, curr = 2;
    while(j < n - 1 || i < n - 1) {
      if(i + curr >= n || j + curr >= n) break;
      int currA = 0, currB = 0;
      int tmp = curr, tmpI = i, tmpJ = j;
      while(tmp--) {
        currA += a[i];
        currB += b[i];
        i++;
      }  
      dbg(currA, currB);
      if(currA > currB) {
        curr++;
        i = tmpI;
        j = tmpJ;
      }
      else {
        ans++;
        i += curr;
        j += curr;
        curr = 2;
      }
    }
    cout << ans << endl;
  }
}

