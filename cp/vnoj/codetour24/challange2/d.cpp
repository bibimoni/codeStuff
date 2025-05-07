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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  map<char, int> a, b;
  for(int i = 0; i < n; i++) {
    char x;
    cin >> x;
    a[x]++;
  }
  for(int i = 0; i < n; i++) {
    char x;
    cin >> x;
    b[x]++;
  }
  int ans = 0; 
  {
    int t = min(a['R'], b['S']);
    ans += t;
    a['R'] -= t; 
    b['S'] -= t;
  }
  {
    int t = min(a['P'], b['R']);
    ans += t;
    a['P'] -= t; 
    b['R'] -= t;
  }
  {
    int t = min(a['S'], b['P']);
    ans += t;
    a['S'] -= t; 
    b['P'] -= t;
  }
  {
    int t = min(b['R'], a['S']);
    ans -= t;
    b['R'] -= t; 
    a['S'] -= t;
  }
  {
    int t = min(b['P'], a['R']);
    ans -= t;
    b['P'] -= t; 
    a['R'] -= t;
  }
  {
    int t = min(b['S'], a['P']);
    ans -= t;
    b['S'] -= t; 
    a['P'] -= t;
  }
  cout << ans;
}


