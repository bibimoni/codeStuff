/**
 * File              : substr.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 31.08.2023
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
#define mod           (int) 1000000003
#define endl          '\n'
#define TLE           ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI         int t;cin>>t;while(t--)
#define INF           (int) 1e18
#define MAXN          (int) 1e6 + 5

int nxt() {int n; cin >> n; return n;}

int POW[MAXN], hashT[MAXN];
const int base = 31;

int getHashT(int i, int j) {
  return (hashT[j] - hashT[i - 1] * POW[j - i + 1] + mod * mod) % mod;
}

signed main() {
  TLE;
  string t, p; cin >> t >> p;
  int szT = sz(t), szP = sz(p);
  t = " " + t, p = " " + p;
  POW[0] = 1;
  for(int i = 1; i <= szT; i++) {
    POW[i] = (POW[i - 1] * base) % mod;
  }

  for(int i = 1; i <= szT; i++) {
    hashT[i] = (hashT[i - 1] * base + t[i] - 'a' + 1) % mod;
  }

  int hashP = 0;
  for(int i = 1; i <= szP; i++) {
    hashP = (hashP * base + p[i] - 'a' + 1) % mod;
  }

  for(int i = 1; i <= szT - szP + 1; i++) {
    dbg(hashP, getHashT(i, i + szP - 1));
    if(hashP == getHashT(i, i + szP - 1)) {
      cout << i << ' ';
    }
  }

}

