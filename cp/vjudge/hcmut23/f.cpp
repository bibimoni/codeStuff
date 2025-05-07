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

struct Matrix {
  int x, y, a[60][60];
  Matrix operator * (Matrix other) {
    Matrix c; c.x = x; c.y = y;
    for(int i = 1; i <= c.x; i++)
      for(int j = 1; j <= c.y; j++) 
        c.a[i][j] = 0ll;
    for(int i = 1; i <= c.x; i++)
      for(int j = 1; j <= c.y; j++) 
        for(int k = 1; k <= y; k++)
          c.a[i][j] = (c.a[i][j] + a[i][k] * other.a[k][j] % MOD) % MOD;
    return c;
  }
};

Matrix power(Matrix a, int exp) {
  if(exp == 1) return a;
  Matrix ans = power(a, exp / 2);
  return (exp & 1 ? ans * ans * a : ans * ans);
}
int c[60][60];
int n, k;
Matrix a, x;
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  c[0][0] = 1ll;
  for(int j = 1; j <= 50; j++) {
    c[0][j] = 1ll;
    for(int i = 1; i <= j; i++) {
      c[i][j] = (c[i][j - 1] + c[i - 1][j - 1]) % MOD;
    }
  }
  while(cin >> n >> k) {
    if(n == 1) {cout << "1" << endl; continue;}
    a.x = k + 2;
    a.y = 1;
    for(int i = 1; i <= a.x; i++) a.a[i][1] = 1ll;
    x.x = x.y = k + 2;
    for(int i = 1; i <= x.x; i++)
      for(int j = 1; j <= x.y; j++)
        x.a[i][j] = 0ll;
    x.a[1][1] = 1;
    for(int j = 2; j <= x.y; j++) 
      x.a[1][j] = c[j - 2][k];
    for(int i = 2; i <= x.x; i++)
      for(int j = 2; j <= i; j++)
        x.a[i][j] = c[j - 2][i - 2];
    Matrix ans = power(x, n - 1) * a;
    cout << ans.a[1][1] << endl;
  } 
}



