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
    cin >> n;
    if(n == 1) {
      cout << "1\n";
      continue;
    }
    if(n % 2 != 0) {
      cout << "-1\n";
      continue;
    }
    vector<int> pa(n);
    iota(pa.begin(), pa.end(), 1);
    vector<int> pb = pa;
    for(int i = 1; i < n; i += 2) {
      swap(pb[i], pb[i - 1]);
    }
    bool ok = false;
    auto checkPerm = [&] (vector<int> &p) {
      for(int i = 1; i < n; i++) {
        int curr = p[i];
        for(int j = i - 1; j >= 0; j--) {
          curr += p[j];
          if(curr % (i - j + 1) == 0)
            return false;
        }
      }
      return true;
    };
    if(checkPerm(pa)) {
      ok = true;
      for(int i : pa) 
        cout << i << " ";
    } 
    else if(checkPerm(pb)) {
      ok = true;
      for(int i : pb) {
        cout << i << " ";
      }
    }
    if(!ok) {
      cout << "-1";
    }
    cout << "\n";
  }
}



