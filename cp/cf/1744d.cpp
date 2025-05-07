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
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int cnt = n;
    for(int i = 0; i < n; i++) {
      while(a[i] % 2 == 0) {
        a[i] /= 2;
        cnt--;
      }
    }
    vector<int> pwr(n, 0);
    for(int i = 0; i < n; i++) {
      int t = i + 1;
      while(t % 2 == 0) {
        t /= 2;
        pwr[i]++;
      }
    }
    sort(pwr.begin(), pwr.end());
    int ans = 0;
    for(int j = n - 1; j >= 0; j--) {
      if(cnt <= 0)
        break;
      cnt -= pwr[j];
      ans += 1;
    }
    cout << (cnt <= 0 ? ans : -1) << '\n';
  }
}

