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
#define int long long
#define sz(_x) (_x).size()
#define pb push_back

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
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = "#" + s;
    Hash hs1(s, 331), hs2(s, 31);
    int best = n, currLen = max(1ll, n / 2);
    for(int len = n / 2; len >= 1; len--) {
      int curr = n;
      for(int i = 1; i + len - 1 <= n; i++) {
        if(i + 2 * len - 1 > n)
          break;
        if(hs1.fwd(i, i + len - 1) == hs1.fwd(i + len, i + 2 * len - 1) && hs2.bwd(i, i + len - 1) == hs2.bwd(i + len, i + 2 * len - 1)) {
          curr -= len;
          i += len - 1;
        }
      }
      if(curr < best) {
        best = curr;
        currLen = len;
      }
    }
    cout << best << ' ' << currLen << '\n';
  }
}

