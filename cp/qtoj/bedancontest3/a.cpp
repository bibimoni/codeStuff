/**
 * Author: distiled
 */

#pragma GCC optimize("Ofast,unroll-loops")

#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif

#define int            long long
const int MOD = 1234567891ll, N = (int) 1e5 + 5;
int a[N];

struct bucket {
  set<int> st;
  multiset<int> s;
  void insert(int x) {
    st.insert(x);
    s.insert(x);
  }
  int size() {
    return st.size();
  }
  void erase(int x) {
    s.erase(s.find(x));
    if(!s.count(x)) {
      st.erase(x);
    }
  } 
  bool has(int x) {
    return st.find(x) != st.end();
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, l, r; cin >> n >> l >> r;
  for(int i = 1; i <= n; i++) cin >> a[i];
  vector<int> dp(n + 1, 0), pref(n + 1, 0);
  map<int, bool> mark;
  dp[0] = 1;
  vector<pair<int, int>> range(n + 1);
  bucket tr, tl;
  int cr = n, cl = n;
  while(tr.size() < l && cr >= 1) {
    tr.insert(a[cr--]);
  }
  while(tl.size() < r && cl >= 1) {
    tl.insert(a[cl--]);
    while(tl.has(a[cl]) && cl >= 1) 
      tl.insert(a[cl--]);
  }
  for(int i = n; i >= 1; i--) {
    if(i < n) {
      tr.erase(a[i + 1]);
      tl.erase(a[i + 1]);
    }
    while(tr.size() < l && cr >= 1) {
      tr.insert(a[cr--]);
    }  
    while(tl.size() < r && cl >= 1) {
      tl.insert(a[cl--]);
      while(tl.has(a[cl]) && cl >= 1) 
        tl.insert(a[cl--]);
    }  
    if(tl.size() <= r && tr.size() >= l) {
      range[i] = {cl + 1, cr + 1};
    }
    else {
      range[i] = {-1, -1};
    }
    //dbg(tr.st, tl.st, cl, cr, i);
  }
  pref[0] = 1;
  for(int i = 1; i <= n; i++) {
    //dbg(range[i]);
    if(range[i] == (pair<int, int>) {-1, -1}) {
      pref[i] = pref[i - 1];
      continue;
    }
    auto [bl, br] = range[i];
    (dp[i] += pref[br - 1] - (bl - 2 >= 0 ? pref[bl - 2] : 0) + MOD) %= MOD;
    (pref[i] = pref[i - 1] + dp[i]) %= MOD;
  }

  cout << dp[n];
}

