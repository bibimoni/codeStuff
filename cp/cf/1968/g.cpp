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

const int N = (int) 2e5 + 5, MOD = (int) 1e9 + 7;

// double rolling hash with one-based indexing
//
// usage Hash(s, BASE1, BASE2)
//
// query
//   hash.fwd(l, r) //get forward hash
//   hash.bwd(l, r) //get backward hash

struct Hash {
  vector<int> hash, hashR, pow, hash1, hashR1, pow1;
  const int RND_MOD = 803574797;
  Hash(string &s, int BASE, int BASE1) {
    int n = s.size() - 1;
    hash = vector<int>(n + 5, 0);
    hashR = vector<int>(n + 5, 0);
    pow = vector<int>(n + 5, 1);
    hash1 = vector<int>(n + 5, 0);
    hashR1 = vector<int>(n + 5, 0);
    pow1 = vector<int>(n + 5, 1);
    for(int i = 1; i <= n; i++) {
      pow[i] = (pow[i - 1] * BASE) % RND_MOD;
      pow1[i] = (pow1[i - 1] * BASE1) % RND_MOD;      
    }
    for(int i = 1; i <= n; i++) {
      hash[i] = (hash[i - 1] * BASE + s[i] - 'a' + 1) % RND_MOD;
      hash1[i] = (hash1[i - 1] * BASE1 + s[i] - 'a' + 1) % RND_MOD;
    }
    for(int i = n; i >= 1; i--) {
      hashR[i] = (hashR[i + 1] * BASE + s[i] - 'a' + 1) % RND_MOD;
      hashR[i] = (hashR[i + 1] * BASE1 + s[i] - 'a' + 1) % RND_MOD;
    } 
  }
  pair<int, int> fwd(int i, int j) {
    return {(hash[j] - hash[i - 1] * pow[j - i + 1] + RND_MOD * RND_MOD) % RND_MOD, (hash1[j] - hash1[i - 1] * pow1[j - i + 1] + RND_MOD * RND_MOD) % RND_MOD};
  }
  pair<int, int> bwd(int i, int j) {
    return {(hashR[i] - hashR[j + 1] * pow[j - i + 1] + RND_MOD * RND_MOD) % RND_MOD, (hashR1[i] - hashR1[j + 1] * pow1[j - i + 1] + RND_MOD * RND_MOD) % RND_MOD};
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, lt, rt;
    cin >> n >> lt >> rt;
    int l = 1, r = n;
    int k = lt;
    string s; 
    cin >> s;
    s = " " + s;
    int ret = 0;
    Hash hs(s, 31, 331);
    while(l <= r) {
      int mid = (l + r) >> 1;
      int cnt = 1;
      for(int i = mid + 1; i <= n; i++) {
        if(i + mid - 1 <= n && hs.fwd(i, i + mid - 1) == hs.fwd(1, mid)) {
          cnt++;
          i += mid - 1;
        }
      }
      if(cnt < k) {
        r = mid - 1;
      }
      else {
        l = mid + 1;
        ret = mid;
      }
    }
    cout << ret << '\n';
  }
}

