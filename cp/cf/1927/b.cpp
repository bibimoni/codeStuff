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
    string s = "";
    int n;
    cin >> n;
    int a[n];
    for(int &i : a) {
      cin >> i;
    }
    char curr = 'a';
    map<char, int> f;
    for(int i = 0; i < n; i++) {
      if(a[i] == 0) {
        s += curr;
        f[curr]++;
        curr++; 
      }
      else {
        for(char j = 'a'; j <= 'z'; j++) {
          if(f[j] == a[i]) {
            s += j;
            f[j]++;
            break;
          }
        }
      }
    }
    cout << s << '\n';
  }
}


