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
const int N = (int) 1e5 + 5, MOD = (int) 1e9 + 7;

// rolling hash with one-based indexing
//
// usage Hash(s, BASE)
//
// query
//   hash.fwd(l, r) //get forward hash
//   hash.bwd(l, r) //get backward hash

struct Hash {
  int hash[N], hashR[N], pow[N];
  Hash(string &s, int BASE) {
    int n = s.size() - 1;
    hash[0] = 0;
    hashR[0] = 0;
    pow[0] = 1;
    for(int i = 1; i <= n; i++) {
      pow[i] = (pow[i - 1] * BASE) % MOD;
    }
    for(int i = 1; i <= n; i++) {
      hash[i] = (hash[i - 1] * BASE + s[i] - 'a' + 1) % MOD;
    }
    for(int i = n; i >= 1; i--) {
      hashR[i] = (hashR[i + 1] * BASE + s[i] - 'a' + 1) % MOD;
    } 
  }
  int fwd(int i, int j) {
    return (hash[j] - hash[i - 1] * pow[j - i + 1] + MOD * MOD) % MOD;
  }
  int bwd(int i, int j) {
    return (hashR[i] - hashR[j + 1] * pow[j - i + 1] + MOD * MOD) % MOD;
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  string s; cin >> s;
  int n = s.size();
  s = " " + s;
  Hash hash(s, 73471);
  Hash hash1(s, 100007);
  string good;
  cin >> good;
  int k;
  cin >> k;
  vector<int> pref(n + 1, 0);
  for(int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + (good[s[i] - 'a'] == '0');
  }
  vector<pair<int, int>> st;
  for(int i = 1; i <= n; i++) {
    for(int j = i; j >= 1; j--) {
      if(pref[i] - (j - 1 < 0 ? 0 : pref[j - 1]) > k) {
        break;
      }
      st.push_back({hash.fwd(j, i), hash1.bwd(j, i)});
    }
  }
  sort(st.begin(), st.end());
  int ans = (st.size() >= 1);
  for(int i = 1; i < st.size(); i++) {
    if(st[i] != st[i - 1]) {
      ans++;
    }
  }
  cout << ans;
}

