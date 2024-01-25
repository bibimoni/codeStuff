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
#define pb             push_back
#define all(x)         x.begin(), x.end()
#define sz(x)          (int) x.size()
#define endl           '\n'
#define MULTI          int tt;cin>>tt;while(tt--)
inline int nxt() { int n; cin >> n; return n; }


signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  map<int, int> pwr;
  int tmp = 1;
  while(tmp <= 20) {
    pwr[tmp] = true;
    tmp *= 2;
  }
  MULTI {
    int n; cin >> n;
    int a[n]; for(int i = 0; i < n; i++) cin >> a[i];
    bool check = true;
    for(int i = 0; i < n - 1; i++) {
      if(a[i] > a[i + 1]) {
        if(!pwr[i + 1]) {
          check = false;
          break;
        }
      }
    }
    cout << (check ? "YES" : "NO") << endl;
  }
}



