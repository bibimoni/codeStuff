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
  Hash(string &s, int BASE, int _RND_MOD) {
    RND_MOD = _RND_MOD;
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

const int MOD_1 = 870709207;
const int MOD_2 = (int)1e9 + 7;
const int B_1 = 31;
const int B_2 = 331;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  set<pair<int, int>> st;
  vector<string> a(n);
  vector<Hash> h1(n);
  vector<Hash> h2(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    int sz = a[i].size();
    a[i] = " " + a[i];
    h1[i] = Hash(a[i], B_1, MOD_1);
    h2[i] = Hash(a[i], B_2, MOD_2);
    st.insert({h1[i].fwd(1, sz), h2[i].fwd(1, sz)});
  }

  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(),
       [&](int i, int j) { return a[i].size() > a[j].size(); });

  dbg(a, st);
  const int K = (int)sqrt(n + 1000);
  int ans = -1;
  for (int k = 0; k < n; k++) {
    int idx = id[k];
    dbg(k, a[idx]);
    if ((int)a[idx].size() - 1 > K) {
      continue;
    }

    dbg(a[idx]);
    bool ok = true;
    for (int i = 1; i < (int)a[idx].size(); i++) {
      for (int j = 1; j <= i; j++) {
        int v1 = h1[idx].fwd(j, i);
        int v2 = h2[idx].fwd(j, i);
        ok &= st.find({v1, v2}) != st.end();
        dbg(ok, i, j, v1, v2);
      }
    }

    if (ok) {
      ans = a[idx].size() - 1;
      break;
    }
  }

  cout << ans << '\n';
}
