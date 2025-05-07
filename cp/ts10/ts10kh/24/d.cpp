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
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> pre;
  int init = 1, curr = 2;
  while(init <= 1e18) {
    pre.push_back(init);
    init += curr * curr;
    curr++;  
  }
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    int l = 0, r = pre.size() - 1, ret = 1;
    while(l <= r) {
      int mid = (l + r) >> 1;
      if(pre[mid] > a[i]) {
        r = mid - 1;
      }
      else {
        ret = mid + 1;
        l = mid + 1;
      }
    }
    cout << ret << " \n"[i == n - 1];
  }
}


