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
    vector<int> a(n + 1);
    vector<int> cnt2(n + 1, 0), cnt1(n + 1, 0);
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      cnt2[i] = cnt2[i - 1] + (a[i] == 2);
      cnt1[i] = cnt1[i - 1] + (a[i] == 1);
    }
    int q;
    cin >> q;
    while(q--) {
      int l, r, k;
      cin >> l >> r >> k;
      int len = r - l + 1;
      int c1 = cnt1[r] - cnt1[l - 1], c2 = cnt2[r] - cnt2[l - 1];
      int diff = abs(c2 - c1);
      int rem = len - c1 - c2;
      int tmp = min(k, rem);
      k = min(k, len);
      if(tmp < diff) {
        if(c1 < c2)
          c1 += tmp;
        else 
          c2 += tmp;
        k = min(len / 2 - min(c1, c2), k);
        if(c2 < c1) 
          swap(c1, c2);
        c1 += k;
      }
      else {
        c1 = max(c1, c2);
        c2 = max(c1, c2);
        tmp -= diff;
        int half = tmp / 2;
        c1 += half;
        c2 += tmp - half;
      }
      cout << c1 * c2 << '\n';
    }
  }
}


