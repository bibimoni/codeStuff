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
    int n, k;
    cin >> n >> k; 
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<string> mustHave;
    for(int i = 0; i < k; i++) {
      string t = string(k, '0');
      t[i] = '1';
      mustHave.push_back(t);
    }
    vector<int> mark(k, 0);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < k; j++) {
        if(a[i] == mustHave[j]) {
          mark[j] = 1;
          break;
        }
      }
    }
    cout << (accumulate(mark.begin(), mark.end(), 0ll) == k ? "YES\n" : "NO\n");
  }
}


