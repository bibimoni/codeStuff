/**
 * File              : J.cpp
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
  string t; cin >> t;
  int nb, ns, nc, pb, ps, pc, r; cin >> nb >> ns >> nc >> pb >> ps >> pc >> r;
  int b = 0, s = 0, c = 0;
  for(char i : t) {
    if(i == 'B') b++;
    if(i == 'S') s++;
    if(i == 'C') c++;
  }
  int ans = 0;
  dbg(ans, nb, ns, nc, b, s, c);
  while(((b != 0) ? nb > 0 : false) || ((s != 0) ? ns > 0 : false) || ((c != 0) ? nc > 0 : false) ) {
    int totalCost = 0;
    dbg(nb, ns, nc)
    if(b == 0) goto sTag;
    if(nb >= b) {
      nb -= b;
    }
    else {
      totalCost += pb * (b - nb);
      nb = 0;
    }
    sTag:
    if(s == 0) goto cTag;
    if(ns >= s) {
      ns -= s;
    }
    else {
      totalCost += ps * (s - ns);
      ns = 0;
    }
    cTag:
    if(c == 0) goto calc;
    if(nc >= c) {
      nc -= c;
    }
    else {
      totalCost += pc * (c - nc);
      nc = 0;
    }
    calc:
    if(totalCost <= r) {
      r -= totalCost;
      ans++;
    }
    else {
      break;
    }
  }
  dbg(ans, r, b, s, c);
  ans += (r / (pb * b + ps * s + pc * c));
  cout << ans;
}

