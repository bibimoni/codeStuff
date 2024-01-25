/**
 * File              : G.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 10.08.2023
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
  int n; cin >> n;
  int a[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  vector<int> ret;
  int pos = n / 2 + 1;
  int maxLen = pos - 1;
  if(pos <= n) ret.push_back(a[pos++]);
  for(int i = 1; i <= maxLen; i++) {
    ret.push_back(a[i]);
    if(pos <= n) ret.push_back(a[pos++]);
  }
  int cnt = 0;
  for(int i = 1; i < n - 1; i++) {
    if(ret[i] < ret[i - 1] && ret[i] < ret[i + 1]) cnt++;
    i++;
  }
  cout << cnt << endl;
  for(int i : ret) cout << i << ' ';
}


