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

const int MOD = (int) 1e9 + 7;

using Matrix = array<array<int, 2>, 2>;

Matrix mul(Matrix a, Matrix b) {
  Matrix res = {{{0, 0}, {0, 0}}};
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      for(int k = 0; k < 2; k++) {
        (res[i][j] += a[i][k] * b[k][j]) %= MOD;
      }
    }
  }
  return res;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
    int n; cin >> n; 
    Matrix m = {{{0, 1}, {1, 1}}};
    Matrix base = {{{1, 0}, {0, 1}}};
    for(; n > 0; n /= 2, m = mul(m, m)) {
      if(n & 1) base = mul(base, m);
    }
    cout << base[1][0] << endl;
}

