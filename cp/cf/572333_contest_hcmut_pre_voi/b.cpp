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
#define int int64_t 

const int N = 1e5 + 5, MOD = 1e9 + 7;
int n;
int h[N], w[N];
int board[101][101];
int pre[101][101];

int mul(int x, int y) {
  return ((x % MOD) * (y % MOD)) % MOD;
}
int pow_mod(int x, int y) {
  int a = 1, b = 1;
  while (y) {
    if (y & 1) {
      a = mul(a, b);
    }
    b = mul(b, b);
    y >>= 1;
  }
  return a;
}

int inv(int x) {
  return pow_mod(x, MOD - 2);
}

void sub_23() {
  int W = 0, H = h[1];
  for (int i = 1; i <= n; i++) {
    (W += w[i]) %= MOD;
  }
  // int sumH = ((H * (H + 1)) / 2) % MOD;
  // int sumW = (((W + 1) * W) / 2) % MOD;
  int inv2 = inv(2);
  int sumH = mul(mul(H, H + 1), inv2);
  int sumW = mul(mul(W, W + 1), inv2);

  cout << mul(sumH, sumW) << '\n';
}

void sub1() {
  int H = 0, W = 0;
  for (int i = 1; i <= n; i++) {
    W += w[i];
    H = max(H, h[i]);
  }
  for (int i = 0; i <= W; i++) {
    for (int j = 0; j <= H; j++) {
      board[i][j] = 0;
      pre[i][j] = 0;
    }
  }
  int prev = 0;
  for (int i = 1; i <= n; i++) {
    for (int k = prev + 1; k <= w[i] + prev; k++) {
      for (int j = 1; j <= h[i]; j++) {
        board[k][j] = 1;
      }
    }
    prev += w[i];
  }
  // for (int i = 1; i <= W; i++) {
  //   for (int j = 1; j <= H; j++) {
  //     cout << board[i][j] << " \n"[j == H];
  //   }
  // }
  for (int i = 1; i <= W; i++) {
    for (int j = 1; j <= H; j++) {
      pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + board[i][j];
    }
  }
  // for (int i = 0; i <= W; i++) {
  //   for (int j = 0; j <= H; j++) {
  //     cout << pre[i][j] << " \n"[j == H];
  //   }
  // }
  auto area = [&] (int x, int y, int x2, int y2) -> int {
    return pre[x2][y2] - pre[x - 1][y2] - pre[x2][y - 1] + pre[x - 1][y - 1];
  };
  int ans = 0;
  for (int ww = 1; ww <= W; ww++) {
    for (int hh = 1; hh <= H; hh++) {
      for (int i = ww; i <= W; i++) {
        for (int j = hh; j <= H; j++) {
          // dbg(i, j, ww, hh, area(i - ww + 1, j - hh + 1, i, j));
          ans += int(area(i - ww + 1, j - hh + 1, i, j) == ww * hh);
          // if (area(i - ww + 1, j - hh + 1, i, j) == ww * hh) {
          //   dbg(i, j, ww, hh);
          // }
        }
      }
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  // freopen("b.in", "r", stdin);
  // freopen("b.out", "w", stdout);
  cin >> n;
  bool eq = true;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
    eq &= (i == 1 || (i > 1 && h[i] == h[i - 1]));
  }
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  if (eq) {
    sub_234();
  } else {
    sub1();
  }
  // sub1();
}


