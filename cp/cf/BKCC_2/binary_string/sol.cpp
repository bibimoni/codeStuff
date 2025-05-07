// time-limit: 3000
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
  int RND_MOD = 870709207;

  Hash() {}
  Hash(string &s, int BASE, int MOD = 870709207) {
    int n = s.size() - 1;
    RND_MOD = MOD;
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
      hash[i] = (hash[i - 1] * BASE + s[i] - 'a' + 1) % RND_MOD;
    }
    for (int i = n; i >= 1; i--) {
      hashR[i] = (hashR[i + 1] * BASE + s[i] - 'a' + 1) % RND_MOD;
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

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = s;
    for (char &c : t) {
      c = '1' - c + '0';
    }
    s = " " + s;
    t = " " + t;

    vector<Hash> h{Hash(s, 31), Hash(s, 331, 1e9 + 7), Hash(s, 3331, 1e9 + 3)};
    vector<Hash> ht{Hash(t, 31), Hash(t, 331, 1e9 + 7), Hash(t, 3331, 1e9 + 3)};

    auto check = [&](int k) -> bool {
      int cur = 1;
      while (cur + k <= n) {
        int ln = cur + k;
        int rn = min(n, cur + 2 * k - 1);
        bool ok = true;
        for (int i = 0; i < 3; i++) {
          ok &= (h[i].fwd(cur, cur + rn - ln) == ht[i].fwd(ln, rn) ||
                 h[i].fwd(cur, cur + rn - ln) == h[i].fwd(ln, rn));
        }
        if (!ok) {
          return false;
        }
        cur = ln;
      }
      return true;
    };

    int ans = -1;
    for (int k = (n + 1) / 2; k >= 1; k--) {
      if (check(k)) {
        ans = k;
        break;
      }
    }
    assert(ans != -1);
    cout << ans << '\n';
  }
}
