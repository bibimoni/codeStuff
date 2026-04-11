// Hello I'm Nekan
//
#include <bits/stdc++.h>
#define Nekan "test"
#define fi first
#define se second
#define pb push_back
#define zs(v) ((int)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define pii pair<int, int>

typedef long double ld;
typedef long long ll;

const int N = 5e5 + 5;
const int LIM = 2e6;
const long long mod = 1e9 + 7; // 998244353;

using namespace std;

int n, m;
int a[N], b[N];
bool valid[LIM + 5];
int d[LIM + 5];
bool is_exist_snt[LIM];
ll h[LIM + 5], g[LIM + 5], s[LIM + 5], t[LIM + 5], c[LIM + 5];
ll ans;

void xuly() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    c[a[i]]++;
  }

  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
    is_exist_snt[b[i]] = true;
  }

  int cnt = 0;
  for (int i = 2; i <= LIM; ++i) {
    if (d[i])
      continue;
    ++cnt;
    for (int j = i; j <= LIM; j += i) {
      d[j] = i;
    }
  }
  // cout << cnt << '\n';

  function<bool(int)> check_valid = [&](int x) {
    if (x == 1)
      return true;
    int c = d[x];
    if (!is_exist_snt[c])
      return false;
    return check_valid(x / c);
  };

  for (int i = 1; i <= LIM; ++i) {
    int val = i;
    valid[i] = check_valid(i);
  }

  for (int i = LIM; i >= 1; --i) {
    for (int j = i; j <= LIM; j += i) {
      g[i] += c[j] * j;
      h[i] += c[j];
    }
    if (h[i] == 0 || !valid[i])
      continue;
    s[i] = g[i] / i * (h[i] - 1);
    for (int j = i + i; j <= LIM; j += i) {
      s[i] = s[i] - (s[j] * (j / i));
    }
    ans += s[i];
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  if (fopen(Nekan ".inp", "r")) {
    freopen(Nekan ".inp", "r", stdin);
    freopen(Nekan ".out", "w", stdout);
  }
  int t = 1;
  // cin >> t;
  while (t--)
    xuly();
}

// Surely nothing could go wrong.
