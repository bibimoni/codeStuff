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

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

inline long long rnd(long long l, long long r) { 
  uniform_int_distribution<long long> dis(l, r); 
  return dis(rng); 
}

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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = " " + s;  
    vector<int> bases = {61, 67, 331, 73};
    int base = bases[rnd(0, 3)], base2 = bases[rnd(0, 3)];
    string kGood = " ", kGood2 = " ";
    for(int i = 0; i * k < n; i++) {
      kGood += (i & 1 ? string(k, '1') : string(k, '0'));
      kGood2 += (i & 1 ? string(k, '0') : string(k, '1'));
    }
    Hash good(kGood, base), hs(s, base), good2(kGood2, base);
    Hash good1(kGood, base2), hs1(s, base2), good21(kGood2, base2);
    auto equal = [&] (int i) -> bool {
      return pair<int, int>({good.fwd(1, n - i + 1), good1.fwd(1, n - i + 1)}) 
        == pair<int, int>({hs.fwd(i, n), hs1.fwd(i, n)});
    };
    auto equal2 = [&] (int i) -> bool {
      return pair<int, int>({good2.fwd(1, n - i + 1), good21.fwd(1, n - i + 1)}) 
        == pair<int, int>({hs.fwd(i, n), hs1.fwd(i, n)});
    };
    int id = n + 1;
    for(int i = 2; i <= n; i++) {
      if(equal(i)) {
        id = i;
        break;
      }
    }
    string add = s.substr(1, id - 1);
    reverse(add.begin(), add.end());
    string t = " " + s.substr(id, n - id + 1) + add;
    if(t != kGood) {
      id = n + 1;
      for(int i = 2; i <= n; i++) {
        if(equal2(i)) {
          id = i;
          break;
        }
      }
      add = s.substr(1, id - 1);
      reverse(add.begin(), add.end());
      s = " " + s.substr(id, n - id + 1) + add;
    }
    cout << (t == kGood || s == kGood2 ? id - 1 : -1) << '\n';
  }
}


