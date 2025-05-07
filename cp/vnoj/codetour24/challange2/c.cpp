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
  int n = (int) s.size();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r)
      z[i] = min (r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]])
      ++z[i];
    if (i + z[i] - 1 > r)
      l = i, r = i + z[i] - 1;
  }
  return z;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  auto zfunc = z_function(s);
  vector<pair<int, int>> ids;
  int cnt = 0, ans = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == ')')
      cnt++;
    else 
      cnt--;
    ans += cnt == 0;
    if(cnt == 0) {
      ids.push_back({i, ans}); 
    }
  }
  for(auto [id, cnt] : ids) {
    int l = id + 1;
    int curr = id + 1;
    bool ok = false;
    while(curr < n) {
      if(zfunc[curr] < l) 
        break;
      curr += l;
      if(curr == n) {
        ok = true;
      }
    }
    if(ok) {
      ans = cnt;
      break;
    }
  }
  cout << ans;
}


