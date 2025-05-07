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
  string s; cin >> s;
  vector<int> cnt;
  int curr = 0;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == '1') {
      cnt.push_back(curr);
      curr = 0;
    }
    else {
      curr++;
    }
  }
  if(curr) cnt.push_back(curr);
  int n = cnt.size();
  if(n < 2) {
    cout << "0\n";
    return 0;
  }
  else if(n < 3) {
    cout << cnt[0] * cnt[1];
    return 0;
  }
  int ans1 = 0, ans2 = 0,
    curr1 = (1ll << cnt[0]) - 1, curr2 = (1ll << cnt[1]) - 1;
  bool ok1 = false, ok2 = false;
  for(int i = 1; i < n; i += 2) {
    if(cnt[i] == 0) continue;
    ans1 += curr1 * ((1ll << cnt[i]) - 1);
    curr1 += curr1 * ((1ll << cnt[i]) - 1);
  }
  for(int i = 2; i < n; i += 2) {
    if(cnt[i] == 0) continue;
    ans2 += curr2 * ((1ll << cnt[i]) - 1);
    curr2 += curr2 * ((1ll << cnt[i]) - 1);
  }
  int ans = 0;
  ans += ans1;
  ans += ans2;
  cout << ans;
}

