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
#define int int64_t 

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  vector<int> cnt(26, 0), sum(26, 0);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += cnt[s[i] - 'A'] * i - sum[s[i] - 'A'];
    cnt[s[i] - 'A'] += 1;
    sum[s[i] - 'A'] += i + 1;
  }
  cout << ans << '\n';
}


