/**
 * File              : D_1.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 08.08.2023
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
  int n, sumA = 0, sumB = 0;
  cin >> n; int a[n], b[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    sumA += a[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> b[i];
    sumB += b[i];
  }
  vector<int> res;
  for(int i = 0; i < n; i++) {
    if(abs(sumA - sumB) > abs(sumA - sumB - 2 * a[i] + 2 * b[i])) {
      sumA += b[i] - a[i];
      sumB += a[i] - b[i];
      res.push_back(i + 1);
    }
  }
  cout << abs(sumA - sumB) << endl;
  cout << sz(res) << ' '; for(auto i : res) cout << i << ' ';
}

