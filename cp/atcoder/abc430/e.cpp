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
  Hash(string &s, int BASE, int _MOD) {
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
      hash[i] = (hash[i - 1] * BASE + s[i] - '0') % RND_MOD;
    }
    for (int i = n; i >= 1; i--) {
      hashR[i] = (hashR[i + 1] * BASE + s[i] - '0') % RND_MOD;
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
  DualHash(string s) {
    h1 = Hash(s, BASE1, MOD1);
    h2 = Hash(s, BASE2, MOD2);
  }
  pair<int, int> fwd(int i, int j) { return {h1.fwd(i, j), h2.fwd(i, j)}; }
  pair<int, int> bwd(int i, int j) { return {h1.bwd(i, j), h2.bwd(i, j)}; }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string a, b;
    cin >> a >> b;

    if (a == b) {
      cout << "0\n";
      continue;
    }

    int n = a.size();

    a = " " + a;
    b = " " + b;

    DualHash ha(a);
    DualHash hb(b);

    int ans = -1;
    for (int i = 1; i <= n; i++) {
      if (ha.fwd(1, i) == hb.fwd(n - i + 1, n) &&
          ha.fwd(i + 1, n) == hb.fwd(1, n - i)) {
        ans = i;
        break;
      }
    }

    cout << ans << '\n';
  }
}
