// time-limit: 3000
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

using Matrix = array<array<int, 2>, 2>;

Matrix mul(Matrix a, Matrix b) {
  Matrix res = {{{0, 0}, {0, 0}}};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        res[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  return res;
}

int getFibo(int n) {
  Matrix base = {{{1, 0}, {0, 1}}};
  Matrix m = {{{1, 1}, {1, 0}}};

  for (; n > 0; n /= 2, m = mul(m, m)) {
    if (n & 1) base = mul(base, m);
  }

  return base[0][1];
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; 
    cin >> n;
    if(n == 1) {
      cout << "0\n";
      continue;
    }
    int l = 1, r = 86, ans = 0;
    while(l <= r) {
      int mid = (l + r) >> 1;
      int t = getFibo(mid);
      //dbg(l, r, mid, t, n);
      if(t <= n) {
        l = mid + 1;
        ans = mid;
      }
      else {
        r = mid - 1;
      }
    }
    dbg(ans);
    cout << getFibo(ans - 1) << '\n';
  
  }
}


