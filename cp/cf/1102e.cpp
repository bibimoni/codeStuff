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

const int MOD = 998244353;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  int a[n];
  map<int, int> f;
  for(int &i : a) {
    cin >> i;
    f[i]++;
  }
  int cnt = 0, ans = 1;
  set<int> s;
  for(int i = 0; i < n; i++) {
    s.insert(a[i]);
    f[a[i]]--;
    if(!f[a[i]]) {
      if(s.size()) {
        s.erase(a[i]);
      }
    }
    cnt += !s.size();
    if(cnt >= 2 && !s.size()) {
      (ans *= 2) %= MOD;
    }
  }
  cout << ans;
}

