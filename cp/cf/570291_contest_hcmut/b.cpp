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

const int N = 25;
int n, m;
int a[N];
vector<int> b;
int ft[N];
const int MOD = (int) 1e9 + 7;

int query(int u) {
  u += 1;
  int ret = 0;
  for (; u > 0; u -= (u & -u)) {
    (ret += ft[u]) %= MOD;
  }
  return ret;
}

void update(int u, int del) {
  u += 1;
  del %= MOD;
  for (; u < N; u += (u & -u)) {
    (ft[u] += del) %= MOD;
  }
}

int mod_pow(int x, int y) {
  int ret = 1, t = x;
  while (y) {
    if (y & 1) 
      (ret *= t) %= MOD;
    (t *= t) %= MOD;
    y /= 2;
  }
  return ret;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  //freopen("set.inp", "r", stdin);
  //freopen("set.out", "w", stdout);
  vector<int> s;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s.push_back(a[i]);
  }
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    b.push_back(x);
    // dbg(x);
    s.push_back(x);
  }
  // dbg(b);
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());

  auto get = [&] (int val) -> int {
    return lower_bound(s.begin(), s.end(), val) - s.begin() + 1;
  };

  for (int i = 1; i <= n; i++) {
    ft[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    a[i] = get(a[i]);
  }
  for (int i = 0; i < m; i++) {
    b[i] = get(b[i]);
  }

  vector<int> nxt(n, -1);
  vector<int> pos(n + 1, -1);
  for (int i = n - 1; i >= 0; i--) {
    if (pos[a[i]] != -1) {
      nxt[i] = pos[a[i]];
    }
    pos[a[i]] = i;
  }
  vector<int> cur(n + 1, 1);
  for (int i = n - 2; i >= 0; i--) {
    (cur[i] = (cur[i + 1] * 2)) %= MOD;
    if (nxt[i] != -1) {
      ((cur[i] -= cur[nxt[i] + 1]) += MOD) %= MOD;
    }
    update(i, cur[i]);
  }
  dbg(cur);
  int ans = 0;
  int idx = 0;
  bool ok = true;
  for (int i = 0; i < m; i++) {
    ok = false;
    int last = 0;
    (ans += query(n - 1) - query(last)) %= MOD;
    for (int j = idx; j < n; j++) {
      if (a[j] == b[i]) {
        last = j + 1;
        ok = true;
        break;
      }
    }    
    idx = last;
    if (!ok) {
      break;
    }
  }
  cout << (ok ? ans : -1);
}


