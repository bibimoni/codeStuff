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

const int RMOD = 870709207, MOD = (int) 1e9 + 7;

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
  Hash(string &s, int BASE, int _RND_MOD) : RND_MOD(_RND_MOD) {
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
      hash[i] = (hash[i - 1] * BASE + s[i] - 'A' + 1) % RND_MOD;
    }
    for(int i = n; i >= 1; i--) {
      hashR[i] = (hashR[i + 1] * BASE + s[i] - 'A' + 1) % RND_MOD;
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
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (n % 2 == 0) {
    cout << "No Solution";
    return 0;
  }
  s = " " + s;
  Hash hash_1(s, 31, RMOD);
  Hash hash_2(s, 331, MOD);
  auto get_hash = [&] (int l, int r) -> pair<int, int> {
    return pair<int, int>{
      hash_1.fwd(l, r),
      hash_2.fwd(l, r)
    };
  };
  auto cmp_hash = [&] (int l, int r, int l1, int r1) -> bool {
    return get_hash(l, r) == get_hash(l1, r1);
  };
  int half = n / 2;
  int mid = (n / 2) + 1; 
  int idx = -1;
  set<pair<int, int>> hh;
  // 1 and n
  if (cmp_hash(2, 1 + half, 2 + half, n)) {
    hh.insert(get_hash(2, 1 + half));
    idx = 1;
  }
  if (cmp_hash(1, half, 1 + half, n - 1)) {
    hh.insert(get_hash(1, half));
    idx = n;
  }
  if (cmp_hash(1, half, mid + 1, n)) {
    hh.insert(get_hash(1, half));
    idx = mid;
  }
  // 2 to n - 1
  for (int i = 2; i * 2 <= n; i++) {
    int n1 = i - 1;
    int n2 = mid - i;
    assert(n1 + n2 == half);
    // dbg(1, n1, i + 1, i + n2);
    // dbg(mid + 1, mid + n1, mid + n1 + 1, n);
    if (cmp_hash(1, n1, mid + 1, mid + n1) && cmp_hash(i + 1, i + n2, mid + n1 + 1, n)) {
      hh.insert(get_hash(mid + 1, n));
      idx = i;
    }
  }
  for (int i = mid + 1; i < n; i++) {
    int n1 = i - mid;
    int n2 = n - i;
    assert(n1 + n2 == half);
    // dbg(1, n1, n1 + 1, half);
    // dbg(mid, mid + n1 - 1, i + 1, n);
    if (cmp_hash(1, n1, mid, mid + n1 - 1) && cmp_hash(n1 + 1, half, i + 1, n)) {
      hh.insert(get_hash(1, half));
      idx = i;
    }
  }
  if (hh.size() == 0) {
    cout << "No Solution";
  } else if (hh.size() == 1) {
    string ans;
    for (int i = 1; i <= n; i++) {
      if (idx == i) {
        continue;
      }
      ans += s[i];
    }
    cout << ans.substr(ans.size() / 2);
  } else {
    cout << "Multiple Solutions";
  }
}


