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

#define int            long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  freopen("ADN.INP", "r", stdin);
  freopen("ADN.OUT", "w", stdout);
  string s; cin >> s;
  int n = s.size();
  s = " " + s;
  if(n == 1) {
    cout << "0\n";
    return 0;
  }
  for(int i = 1; i <= n; i++) {
    if(i == 1 && s[i] == '?') s[i] = s[i + 1]; 
    else if(i == n && s[i] == '?') s[i] = s[i - 1];
    else if(i > 1 && i < n && s[i] == '?') {
      int j = i;
      while(s[j] == '?') j++;
      if(s[j] == s[i - 1]) for(int i1 = i; i1 < j; i1++) s[i1] = s[i - 1];
      i = j;
    }
  }
  vector<pair<char, int>> compress;
  for(int i = 1; i <= n; i++) {
    int j = i;
    while(s[j] == s[i]) j++;
    compress.push_back({s[i], j - i});
    i = j - 1;
  }
  n = compress.size();
  vector<int> dp(n, 0); dp[0] = compress[0].second * (compress[0].second + 1) / 2;
  for(int i = 1; i < n; i++) {
    for(int k = max(-1ll, i - 3); k < i; k++) {
      bool canMerge = true;
      char curr = '0';
      for(int j = k + 1; j <= i; j++) {
        if(compress[j].first == '?') continue;
        if(curr == '0') curr = compress[j].first;
        if(curr != compress[j].first) canMerge = false;
      }
      if(!canMerge) continue;
      int totalLength = 0;
      for(int j = k + 1; j <= i; j++) {
        totalLength += compress[j].second;
      }
      int prev = (k == -1 ? 0 : dp[k]);
      dp[i] = max(prev + totalLength * (totalLength + 1) / 2, dp[i]);
    }
  }
  cout << (s.size() * (s.size() - 1) / 2) - dp[n - 1];
}

