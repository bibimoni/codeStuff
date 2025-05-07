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

#define int            long long
#define all(x)         x.begin(), x.end()

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    string s; cin >> s;
    int maxLen = 0, cnt1 = 0, cnt2 = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
      if(s[i] == '#') {
        continue;
      }  
      int j = i;
      while(j + 1 < n && s[j + 1] != '#') j++;
      int len = j - i + 1;
      cnt1 += len == 1;
      cnt2 += len == 2;
      maxLen = max(len, maxLen);
      i = j;
    }
    if(maxLen >= 3) {
      cout << "2\n";
    }
    else {
      cout << cnt1 + cnt2 * 2 << '\n';
    }
    
  }
}


