/**
 * File              : btuyet.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 23.09.2023
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
#define endl          '\n'
#define MULTI         int t;cin>>t;while(t--)
const int MAXN = (int) 1e6 + 5, INF = 1e18, MOD = 1000000007; //998244353
int nxt() {int n; cin >> n; return n;}

//tra ve vi tri cua gia tri nho nhat trong mang
int fixArray(int a[9]) {
  int curr = INT_MAX, k = 0;
  for(int i = 0; i < 9; i++) {
    if(a[i] == 0) continue;
    if(curr > a[i]) {
      curr = a[i];
      k = i;
    } 
  }
  return k;
}

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  //freopen("BTUYET.INP", "r", stdin);
  //freopen("BTUYEN.OUT", "w", stdout);
  int a[9];
  for(int i = 0; i < 9; i++) cin >> a[i];
  a[fixArray(a)] = 0; a[fixArray(a)] = 0;
  for(int i = 0; i < 9; i++) {
    if(a[i] == 0) continue;
    else cout << a[i] << endl;
  }
}

