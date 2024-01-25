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
    int n; cin >> n;
    string s; cin >> s;
    vector<int> cnt(26, 0);
    for(char i : s) cnt[i - 'a']++;
    int biggest = *max_element(cnt.begin(), cnt.end());
    if(2 * biggest >= n) {
      cout << 2 * biggest - n << '\n';
    }
    else {
      cout << n % 2 << '\n';
    }
  }
}


