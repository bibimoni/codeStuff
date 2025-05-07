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
  int k;
  cin >> k;
  string s, t;
  cin >> s >> t;
  string diff = "";
  for (int i = k - 1; i >= 0; i--) {
    if (t[i] < s[i]) {
      diff += char((26 + t[i] - '0') - int(s[i] - '0') + 'a');
      t[i - 1] -= 1;
    } else {
      diff += char((t[i] - s[i]) + 'a');
    }
  }
  reverse(diff.begin(), diff.end());
  string half = "";
  for (int i = k - 1; i >= 0; i--) {
    half += char((diff[i] - 'a') / 2 + 'a');
    if ((diff[i] - 'a') % 2 != 0 && i < k - 1) {
      half[half.size() - 2] = char((half[half.size() - 2] - 'a' + 13) + 'a');
    }
  }
  reverse(half.begin(), half.end());
  string ans = "";
  int cnt = 0;
  for (int i = k - 1; i >= 0; i--) {
    int v = int(half[i] - 'a' + s[i] - 'a' + cnt);
    ans += char(v % 26 + 'a');
    cnt = v / 26;
  }
  if (cnt > 0) {
    ans += char(cnt + 'a');
  }
  reverse(ans.begin(), ans.end());
  cout << ans;
}

