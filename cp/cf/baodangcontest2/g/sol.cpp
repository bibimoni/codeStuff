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
const int MOD = (int) 998244353;
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n; cin >> n;
  string t; cin >> t;
  vector<int> cnt;
  int curr = 0;
  string s;
  for(char i : t) {
    if(i == 'a') {
      curr++;
      s += i;
    }
    else if(i == 'c' && (s.size() && s.back() == 'a')) {
      cnt.push_back(curr);
      curr = 0;
      s += i; 
    }
  }
  if(curr != 0) cnt.push_back(curr);
  n = cnt.size();
  if(n == 0) {
    cout << "0";
    return 0;
  }
  vector<int> ans(n, 0);
  ans[0] = cnt[0];
  for(int i = 1; i < n; i++) {
    (ans[i] = ans[i - 1] * cnt[i] + cnt[i]) %= MOD;
    //curr += curr * cnt[i] + cnt[i];
    //curr %= MOD;
  }
  cout << accumulate(ans.begin(), ans.end(), 0ll);
}