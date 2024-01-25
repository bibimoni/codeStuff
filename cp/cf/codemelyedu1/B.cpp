/**
 * File              : B.cpp
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
  MULTI {
    int n; cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++) {
      a.push_back(nxt());
    }
    sort(all(a));
    bool check = true;
    while(check && sz(a) > 1) {
      int cnt = 0;
      int prev = 0;
      for(int i = 0; i < sz(a); i++) {
        if(prev == 0) {
          prev = a[i];
          continue;
        }  
        if(a[i] - prev <= 1) {
          if(sz(a) > 0) a.erase(a.begin() + i - 1);
          cnt++;
        }
        dbg(a[i], prev, sz(a));
        prev = a[i];
      }
      if(cnt < 1) check = false;
    }
    if(sz(a) <= 1) YES
    else NO
  }
}

