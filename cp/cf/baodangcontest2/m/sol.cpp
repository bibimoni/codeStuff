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
const int INF = (int) 1e18;
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  vector<int> coprime[1001];
  for(int i = 1; i <= 1000; i++) {
    for(int j = 1; j <= 1000; j++) {
      if(__gcd(i, j) == 1) {
        coprime[i].push_back(j);
      } 
    }
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<int> pref(n + 1, 0);
    for(int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] + a[i];
    }
    vector<int> pos(1001, 0), pos1(1001, 0);
    int ans = -INF;
    bool check = false;
    for(int i = 1; i <= n; i++) {
      if(abs(a[i]) == 1) {
        check = true;
        ans = max(ans, a[i]);
      }
      for(auto c : coprime[abs(a[i])]) {
        if(pos[c] != 0) {
          ans = max(ans, pref[i] - pref[pos[c] - 1]);
          check = true;
        }
        if(pos1[c] != 0) {
          ans = max(ans, pref[i] - pref[pos1[c] - 1]);
          check = true;
        }
      }
      int t;
      if(a[i] >= 0) {
        t = pos[a[i]];
      }
      else {
        t = pos1[-a[i]];
      }
      if(!t || pref[i] - pref[t - 1] < a[i]) { 
        if(a[i] >= 0) {
          pos[a[i]] = i;
        }
        else {
          pos1[-a[i]] = i;
        }
      }
    }
    if(!check) {
      cout << "NOT FOUND\n";
    }
    else {
      cout << ans << '\n';
    }
  }
}

