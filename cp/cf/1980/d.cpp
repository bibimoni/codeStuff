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
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b;
    for(int i = 0; i < n - 1; i++) {
      b.push_back(__gcd(a[i], a[i + 1]));
    }
    int m = b.size();
    int cnt = 0;
    int id = -1;
    for(int i = 0; i < m - 1; i++) {
      cnt += (b[i] > b[i + 1]);
      if(b[i] > b[i + 1] && id == -1) {
        id = i;
      }
    }
    if(cnt == 0) {
      cout << "YES\n";
      continue;
    }
    auto tmp = a;
    b.clear();
    tmp.erase(tmp.begin() + n - 1);
    for(int i = 0; i < tmp.size() - 1; i++) {
      b.push_back(__gcd(tmp[i], tmp[i + 1]));
    }
    if(is_sorted(b.begin(), b.end())) {
      cout << "YES\n";
      continue;
    }
    for(int k = max(0ll, id - 5); k <= min(n - 1, id + 5); k++) {
      tmp = a;
      b.clear();
      tmp.erase(tmp.begin() + k);
      for(int i = 0; i < tmp.size() - 1; i++) {
        b.push_back(__gcd(tmp[i], tmp[i + 1]));
      }
      if(is_sorted(b.begin(), b.end()))
        break;
    }
    cout << (is_sorted(b.begin(), b.end()) ? "YES\n" : "NO\n");
  }
}


