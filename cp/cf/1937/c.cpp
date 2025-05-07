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

char ask(int i1, int i2, int i3, int i4) {
  cout << "? " << i1 << ' ' << i2 << ' ' << i3 << ' ' << i4 << '\n';
  cout.flush();
  char in;
  cin >> in;
  cout.flush();
  return in;
}


signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    if(n == 2) {
      cout << "! 0 1\n";
      cout.flush();
      continue;
    }
    int idMax = 0;
    for(int i = 1; i < n; i++) {
      char ans = ask(idMax, idMax, i, i);
      if(ans == '<') {
        idMax = i; 
      }
    }
    vector<int> a;
    a.push_back(0);
    int prev = 0;
    for(int i = 1; i < n; i++) {
      char ans = ask(idMax, prev, idMax, i);
      if(ans == '=') {
        a.push_back(i);
      }
      else if(ans == '<') {
        a.clear();
        a.push_back(i);
        prev = i;
      }
    }
    int curr = a[0];
    for(auto i : a) {
      char ans = ask(curr, curr, i, i);
      if(ans == '>') {
        curr = i;
      }
    }
    cout << "! " << idMax << ' ' << curr << '\n';
    cout.flush();
  }
}


