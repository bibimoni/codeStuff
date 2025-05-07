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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n; 
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> mp(n + 1, 0);
  for(int i = 2; i * i <= n; i++) {
    if(!mp[i]) {
      mp[i] = i;
      for(int j = i * i; j <= n; j += i) {
        if(!mp[j]) {
          mp[j] = i;
        }
      }
    }
  }
  for(int i = 2; i <= n; i++) {
    if(!mp[i]) {
      mp[i] = i;
    }
  }
  vector<bool> mark(n + 1, false);
  for(int i = 0; i < n - 1; i++) {
    int tmp = abs(a[i] - a[i + 1]);
    while(tmp > 1) {
      int p = mp[tmp];
      while(mp[tmp] == p) {
        mark[mp[tmp]] = true;
        tmp /= mp[tmp];
      }
    }
    if(tmp != 1) {
      mark[tmp] = true;
    }
  }
  int ans = 0;
  int minA =*min_element(a, a + n);
  for(int i = 2; i <= minA; i++) {
    if(mp[i] == i && !mark[i]) {
      ans++;
    }
  }
  cout << ans;
}

