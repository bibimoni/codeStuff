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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    string s, t; cin >> s >> t;
    if(s.size() != t.size()) {
      cout << "NO\n";
      continue;
    }
    map<int, int> f;
    bool ok = true;
    for(char i : s) f[i]++;
    for(char i : t) f[i]--;
    for(auto [_, v] : f) {
      if(v != 0) ok = false;
    }
    map<char, int> cnt1, cnt2;
    for(int i = 0; i < s.size(); i++) cnt1[s[i]] += (i & 1);
    for(int i = 0; i < t.size(); i++) cnt2[t[i]] += (i & 1);
    for(char i = 'a'; i <= 'z'; i++) {
      if(cnt1[i] != cnt2[i]) ok = false;
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}

