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

// rolling hash with one-based indexing
//
// usage Hash(s, BASE)
//
// query
//   hash.fwd(l, r) //get forward hash
//   hash.bwd(l, r) //get backward hash

struct Hash {
  vector<int> hash, hashR, pow;
  const int RND_MOD = 870709207;
  Hash(string &s, int BASE) {
    int n = s.size() - 1;
    hash = vector<int>(n + 5);
    hashR = vector<int>(n + 5);
    pow = vector<int>(n + 5);
    hash[0] = 0;
    hashR[0] = 0;
    pow[0] = 1;
    for(int i = 1; i <= n; i++) {
      pow[i] = (pow[i - 1] * BASE) % RND_MOD;
    }
    for(int i = 1; i <= n; i++) {
      hash[i] = (hash[i - 1] * BASE + s[i] - 'a' + 1) % RND_MOD;
    }
    for(int i = n; i >= 1; i--) {
      hashR[i] = (hashR[i + 1] * BASE + s[i] - 'a' + 1) % RND_MOD;
    } 
  }
  int fwd(int i, int j) {
    return (hash[j] - hash[i - 1] * pow[j - i + 1] + RND_MOD * RND_MOD) % RND_MOD;
  }
  int bwd(int i, int j) {
    return (hashR[i] - hashR[j + 1] * pow[j - i + 1] + RND_MOD * RND_MOD) % RND_MOD;
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<string> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = " " + a[i];
  }
  map<pair<int, int>, int> mp;
  for (int i = 0; i < q; i++) {
    string t;
    cin >> t;
    t = " " + t;
    Hash hash(t, 331);
    Hash hash_2(t, 61);
    mp[{hash.fwd(1, t.size() - 1), hash_2.fwd(1, t.size() - 1)}] = i;
    // cout << (st.find() != st.end());
  }
  string ans = string(q, '0');
  for (int len = 2; len <= 10; len++) {
    for (int i = 1; i <= n; i++) {
      Hash hash(a[i], 331);
      Hash hash_2(a[i], 61);
      for (int j = 1; j + len - 1 <= m; j++) {
        if (mp.count({hash.fwd(j, j + len - 1), hash_2.fwd(j, j + len - 1)})) {
          ans[mp[{hash.fwd(j, j + len - 1), hash_2.fwd(j, j + len - 1)}]] = '1';
        }      
      }
    }
    for (int j = 1; j <= m; j++) {
      string curr = "#";
      for (int i = 1; i <= n; i++) {
        curr += a[i][j];
      }
      Hash hash(curr, 331);
      Hash hash_2(curr, 61);
      for (int i = 1; i + len - 1 <= n; i++) {
        if (mp.count({hash.fwd(i, i + len - 1), hash_2.fwd(i, i + len - 1)})) {
          ans[mp[{hash.fwd(i, i + len - 1), hash_2.fwd(i, i + len - 1)}]] = '1';
        }
      }
    }
  }
  cout << ans << '\n';
}


