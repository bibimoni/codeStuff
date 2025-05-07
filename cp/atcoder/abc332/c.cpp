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
const int INF = (int) 1e18;
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m; cin >> n >> m;
  string s; cin >> s;
  int l = 0, r = s.size();
  int ans = INF;
  while(l <= r) {
    int mid = (l + r) >> 1;
    int currA = mid, currM = m;
    bool ok = true;
    for(char i : s) {
      if(i == '0') {
        currA = mid, currM = m;
      }
      else if(i == '1') {
        if(currM > 0) currM--;
        else if(currA > 0) currA--;
        else ok = false;
      }
      else if(i == '2') {
        if(currA > 0) currA--;
        else ok = false;
      }
    }
    if(!ok) {
      l = mid + 1;
    }
    else {
      r = mid - 1;
      ans = min(ans, mid);
    }
  }
  cout << ans;
}


