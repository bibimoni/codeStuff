#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,fma")
#pragma GCC optimize("no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld double

const ld EPS = 1e-9;
const int N = 2e5 + 6;
ld a[N], b[N];
ld area(ld x1, ld y1, ld x2, ld y2) {
  // if (y1 < y2) {swap(x1,x2); swap(y1, y2);}

  return (x2 - x1) * min(y1, y2) + (abs(y2 - y1) * (x2 - x1)) / 2.0;
}

/*
 * (y' + yi)*(x'-xi) = 2*S
 * -xiyi + yi*x' - xi*(ax'+b') + x'(ax'+b)
 *  -xiyi + yi*x' - xi*a*x' - xi*b' + ax'^2 + b*x'
 *
 */
ld area_inv(ld x1, ld y1, ld x2, ld y2, ld s, ld a, ld b) {
  // cerr << "a: " << a << ", b: " << b << endl;

  ld A = a;
  ld B = y1 - x1 * a + b;
  ld C = -2 * s - x1 * y1 - x1 * b;

  if (abs(a) < EPS) {
    return -C / B;
  }

  ld delta = B * B - 4 * A * C;
  // cerr << delta << endl;
  // cerr << A << " " << B << " " << C << endl;
  ld xx1 = (-B + sqrt(delta)) / (2.0 * A);
  ld xx2 = (-B - sqrt(delta)) / (2.0 * A);

  // cerr << xx1 << " " << xx2 << endl;

  if (x1 < xx1 && xx1 <= x2)
    return xx1;
  else
    return xx2;
}
/*
y = ax + b
a = (y2 - y1) / (x2 - x1)
b = (x2y1 - x1y2) / (x2 - x1)
*/

ld pre[N];
ld x[N], y[N];

int main() {
  //  freopen("main.inp", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n, m;

  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> x[i];
  for (int i = 1; i <= n; i++)
    cin >> y[i];
  for (int i = 1; i <= n; i++) {
    // ld a = (y2 - y1) / (x2 - x1);
    // ld b = (x2 * y1 - x1 * y2) / (x2 - x1);
    //
    a[i] = (y[i + 1] - y[i]) / (x[i + 1] - x[i]);
    b[i] = (x[i + 1] * y[i] - x[i] * y[i + 1]) / (x[i + 1] - x[i]);
  }

  ld part = 0;
  for (int i = 2; i <= n; i++) {
    pre[i - 1] = area(x[i - 1], y[i - 1], x[i], y[i]);
    part += pre[i - 1];
  }
  part /= m;

  // vector<ld> ans;

  cout << fixed << setprecision(6);

  int block = 1;
  ld bonus = 0;
  for (int i = 1; i <= m - 1; i++) {
    if (pre[block] - bonus >= part) {
      // same block
      cout << (area_inv(x[block], y[block], x[block + 1], y[block + 1],
                        part + bonus, a[block], b[block]))
           << " ";
      bonus += part;
    } else {
      ld cur_s = pre[block] - bonus;
      block++;
      bonus = 0;
      while (cur_s + pre[block] < part) {
        cur_s += pre[block];
        // bonus = 0;
        block++;
      }
      assert(block < n);
      // cerr << block << endl;
      // cerr << cur_s << endl;
      // cerr << part - cur_s << endl;
      cout << ((area_inv(x[block], y[block], x[block + 1], y[block + 1],
                         part - cur_s, a[block], b[block])))
           << " ";
      bonus = part - cur_s;
    }
  }
}
