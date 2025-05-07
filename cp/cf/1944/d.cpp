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

const int N = (int) 2e5 + 5, MOD = (int) 1e9 + 7, BASE = 331, BASE1 = 31;

// rolling hash with one-based indexing
//
// usage Hash(s, BASE)
//
// query
//   hash.fwd(l, r) //get forward hash
//   hash.bwd(l, r) //get backward hash

struct Hash {
  vector<int> hash, hashR, pow;
  const int RND_MOD = 999119999ll;
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

int val[N];

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  for(int i = 1; i < N; i++) {
    val[i] = val[i - 1] + (i % 2 == 0 ? i : 0);
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int n, q;
    cin >> n >> q;
    string s; 
    cin >> s;
    s = " " + s + s[s.size() - 1];
    vector<int> same(n + 1, 0), alt(n + 1, 0);
    for(int i = 2; i <= n; i++) {
      same[i] = same[i - 1] + (s[i] != s[i - 1]);
      if(i >= 2) {
        alt[i] = alt[i - 2] + (s[i] == s[i - 2]);
      }
    }
    //[2, 4]
    //    [   ]
    // xaxbxaxa
    //  0 1 2 2 
    Hash hash(s, BASE), hash1(s, BASE1);
    auto isSame = [&] (int l, int r) -> bool {
      return (same[r] - same[l]) == 0;
    };
    auto isAlt = [&] (int l, int r) -> bool {
      if (r - l == 1) {
        return s[l] != s[r];
      }
      int x1, x2; x1 = x2 = 0;
      x1 = alt[r] - alt[((r & 1) == ((l + 1) & 1)) ? (l + 1) : l];
      x2 = alt[r - 1] - alt[(((r - 1) & 1) == ((l + 1) & 1)) ? (l + 1) : l];
      return (s[l] != s[l + 1]) && (x1 + x2 == r - l - 1);
    };
    auto isPalin = [&] (int l, int r) -> bool {
      // dbg(hash.fwd(l, r), hash.bwd(l, r));
      return hash.fwd(l, r) == hash.bwd(l, r) && hash1.fwd(l, r) == hash1.bwd(l, r);
    };
    while(q--) {
      int l, r;
      cin >> l >> r;
      int k = r - l + 1;
      if(isSame(l, r)) {
        cout << "0\n";
      }
      else if(isAlt(l, r) && k >= 3) {
        cout << val[k] << '\n';
      }
      else {
        cout << k * (k + 1) / 2 + (isPalin(l, r) ? -k : 0) - 1 << '\n';
      }
    }
  }
}


