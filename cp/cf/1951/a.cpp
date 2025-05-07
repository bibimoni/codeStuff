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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    string s;
    //1001001110
    //0000000000
    //100100101
    cin >> n >> s;
    int cnt11 = 0, cnt1 = 0;
    for(int i = 0; i < n; i++) {
      if(i < n - 1) {
        cnt11 += (s[i] == '1' && s[i + 1] == '1');
      }
      cnt1 += s[i] == '1';
    }
    if(cnt11 == 1 && cnt1 == 2) {
      cout << "NO\n";
    }
    else if(cnt1 % 2 == 0) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
}


