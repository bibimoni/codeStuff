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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> blockids;
  vector<int> blocksz;
  for (int i = 0; i < n; i++) {
    if ((i == 0 || s[i - 1] == '0') && s[i] == '1') {
      blockids.push_back(i);
      blocksz.push_back(1);
    } else if (s[i] == '1') {
      blocksz[blockids.size() - 1] += 1;
    }
  }
  string ans = string(blocksz[k - 2] + blocksz[k - 1], '1');
  int rem = blockids[k - 1] - blockids[k - 2] - blocksz[k - 2];
  ans += string(rem, '0');
  string add = blockids[k - 1] + blocksz[k - 1] < int(s.size()) ? s.substr(blockids[k - 1] + blocksz[k - 1]) : "";
  ans = s.substr(0, blockids[k - 2]) + ans + add;
  cout << ans << '\n';

}


