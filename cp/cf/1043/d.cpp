/**
 * Author: distiled
 */
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
#define int int64_t

// rolling hash with one-based indexing
//
// usage Hash(s, BASE)
//
// query
//   hash.fwd(l, r) //get forward hash
//   hash.bwd(l, r) //get backward hash

struct Hash {
  vector<int> hash, hashR, pow;
  int RND_MOD;
  Hash() {}
  Hash(vector<int> &s, int BASE, int _MOD) {
    RND_MOD = _MOD;
    int n = s.size() - 1;
    hash = vector<int>(n + 5);
    hashR = vector<int>(n + 5);
    pow = vector<int>(n + 5);
    hash[0] = 0;
    hashR[0] = 0;
    pow[0] = 1;
    for (int i = 1; i <= n; i++) {
      pow[i] = (pow[i - 1] * BASE) % RND_MOD;
    }
    for (int i = 1; i <= n; i++) {
      hash[i] = (hash[i - 1] * BASE + s[i]) % RND_MOD;
    }
    for (int i = n; i >= 1; i--) {
      hashR[i] = (hashR[i + 1] * BASE + s[i]) % RND_MOD;
    }
  }
  int fwd(int i, int j) {
    return (hash[j] - hash[i - 1] * pow[j - i + 1] + RND_MOD * RND_MOD) %
           RND_MOD;
  }
  int bwd(int i, int j) {
    return (hashR[i] - hashR[j + 1] * pow[j - i + 1] + RND_MOD * RND_MOD) %
           RND_MOD;
  }
};

struct DualHash {
  Hash h1, h2;
  int BASE1 = 31, BASE2 = 331;
  int MOD1 = (int)1e9 + 7, MOD2 = 998244353;
  DualHash() {}
  DualHash(vector<int> s) {
    h1 = Hash(s, BASE1, MOD1);
    h2 = Hash(s, BASE2, MOD2);
  }
  pair<int, int> fwd(int i, int j) { return {h1.fwd(i, j), h2.fwd(i, j)}; }
  pair<int, int> bwd(int i, int j) { return {h1.bwd(i, j), h2.bwd(i, j)}; }
};

const int M = 10, N = (int)1e5;
// int a[M + 1][N + 1];
int id[M + 1][N + 1];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;

  vector<vector<int>> a(m, vector<int>(n + 1));
  // vector<vector<int>> id(m, vector<int>(n + 1));
  for (int i = 0; i < m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      id[i][a[i][j]] = j;
    }
  }

  vector<DualHash> h(m);
  for (int i = 0; i < m; i++) {
    h[i] = DualHash(a[i]);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int val = a[0][i];
    int j = i;
    while (j <= n) {
      auto p1 = h[0].fwd(i, j);
      int len = j - i + 1;
      bool ok = true;
      for (int k = 0; k < m; k++) {
        if (id[k][val] + len - 1 > n) {
          ok = false;
          break;
        }
        ok &= p1 == h[k].fwd(id[k][val], id[k][val] + len - 1);
      }
      if (!ok) {
        break;
      }
      j += 1;
    }
    int ll = j - i;
    ans += (ll + 1) * ll / 2;
    i = j - 1;
  }

  cout << ans << '\n';
}
