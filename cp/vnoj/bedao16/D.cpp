/**
 * File              : D.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 07.08.2023
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

int n, bit1[MAXN], bit2[MAXN];

void update(int idx, int u, int v, bool make = 0) {
  while(idx <= n) {
    if(make) {
      bit1[idx] += u;
      bit2[idx] += v;
    }
    else {
      bit1[idx] += - v + u;
      bit2[idx] += - u + v;
    }
    idx += (idx & -idx);
  }
}

pair<int, int> getSum() {
  int idx = n, ans1 = 0, ans2 = 0;
  while(idx > 0) {
    ans1 += bit1[idx];
    ans2 += bit2[idx];
    idx -= (idx & -idx);
  }
  return {ans1, ans2};
}

signed main() {
  TLE;
  cin >> n;
  int a[n + 1], b[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for(int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for(int i = 1; i <= n; i++) {
    update(i, a[i], b[i], 1);
  }
  vector<int> res;
  for(int i = 1; i <= n; i++) {
   auto [u1, v1] = getSum();
    int before = abs(u1 - v1);
    update(i, b[i], a[i]);
   auto [u2, v2] = getSum();
    int after = abs(u2 - v2);
    if(after >= before) {
      update(i, a[i], b[i]);  
    }
    else {
      res.push_back(i);
    }
  }
  auto [u, v] = getSum();
  cout << abs(u - v) << endl;
  cout << sz(res) << ' ';
  for(auto i : res) cout << i << ' ';
}

