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
const int MOD = (int) 1e9 + 7;
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  string t; cin >> t;
  vector<int> cnt;
  int ans = 0, curr = 0;
  string s;
  for(char i : t) {
    if(i == 'a') {
      curr++;
      s += i;
    }
    else if(i == 'b' && (s.size() && s.back() == 'a')) {
      cnt.push_back(curr);
      curr = 0;
      s += i; 
    }
  }
  if(curr != 0) cnt.push_back(curr);
  int n = cnt.size();
  if(n == 0) {
    cout << "0";
    return 0;
  }
  dbg(s, cnt);
  ans += cnt[0]; curr = cnt[0];
  for(int i = 1; i < n; i++) {
    (ans += curr * cnt[i] + cnt[i]) %= MOD;
    curr += curr * cnt[i] + cnt[i];
    curr %= MOD;
  }
  cout << ans;
}

