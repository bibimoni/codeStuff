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
#define int long long

vector<int> z_function(const string& s) {
  int n = (int) s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r)
      z[i] = min (r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]])
      ++z[i];
    if (i + z[i] - 1 > r)
      l = i, 
      r = i + z[i] - 1;
  }
  return z;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> jump(n + 1, n);
    for(int i = n - 1; i >= 0; i--) {
      if(s[i] != 'a')
        jump[i] = i;
      jump[i] = min(jump[i + 1], jump[i]);
    }
    if(jump[0] == n) {
      cout << n - 1 << '\n';
      continue;
    }
    int id = jump[0];
    string t = s.substr(id);
    auto zfunc = z_function(t);
    int ans = 0;
    for(int l = 1; l <= n - id; l++) {
      bool ok = true;
      int curr = id + l, gap = id;
      while(curr < n) {
        if(jump[curr] >= n)
          break;
        gap = min(gap, jump[curr] - curr);
        curr = jump[curr];
        if(zfunc[curr - id] < l) {
          ok = false;
          break;
        }
        curr += l;
      }
      if(!ok)
        continue;
      ans += gap + 1;
    }
    cout << ans << '\n'; 
  }
}


