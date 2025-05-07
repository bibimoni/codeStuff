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

int xnor(int a, int b) {
  return ~(a ^ b);
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    multiset<int> s;
    for(int i = 0; i < n; i++) {
      int x;
      cin >> x;
      s.insert(x);
    }
    int ans = 0;
    for(int i : s) {
      ans++;
      if(s.find(((1 << 31) - 1) ^ i) != s.end()) {
        s.erase(s.find(((1 << 31) - 1) ^ i));
      }
    }
    cout << ans << '\n';
  }
}

