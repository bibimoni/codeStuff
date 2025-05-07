/**
 * Author: distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif

#define int            long long
#define pb             push_back
#define all(x)         x.begin(), x.end()
#define sz(x)          (int) x.size()
#define endl           '\n'
#define MULTI          int tt;cin>>tt;while(tt--)
inline int nxt() { int n; cin >> n; return n; }

using Matrix = array<array<int, 4>, 4>;

Matrix mul(Matrix a, Matrix b, int mod) {
  Matrix res = {{{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}};
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      for(int k = 0; k < 4; k++) {
        res[i][j] = (res[i][j] + a[i][k] % mod * b[k][j] % mod) % mod;
      }
    }
  }
  dbg(res);
  return res;
} 

Matrix power(Matrix a, int exp, int m) {
  if(exp == 1) return a;
  Matrix ans = power(a, exp / 2, m);
  if(exp & 1) return mul(ans, mul(ans, a, m), m);
  else return mul(ans, ans, m);
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  MULTI {
    int a2, n, m; cin >> a2 >> n >> m;
    Matrix base = {{
      {(1 + a2 * a2) % m, 0, 0, 0}, 
      {(a2 * a2) % m, 0, 0, 0}, 
      {1, 0, 0, 0}, 
      {a2 % m, 0, 0, 0}
    }};
    if(n <= 2) {
      if(n == 1) cout << 1 % m << endl;
      if(n == 2) cout << (1 + a2 * a2) % m << endl;
      continue;
    }
    Matrix c = {{
      {1, (4 * a2 * a2) % m, 1, (-4 * a2) % m}, 
      {0, (4 * a2 * a2) % m, 1, (-4 * a2) % m}, 
      {0, 1, 0, 0}, 
      {0, (2 * a2) % m, 0, -1}
    }};
    Matrix pwr = mul(power(c, n - 2, m), base, m);
    dbg(pwr[0][0], tt);
    cout << (pwr[0][0] + m) % m << endl;
  }
}



