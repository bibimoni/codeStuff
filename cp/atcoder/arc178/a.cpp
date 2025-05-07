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
  int n, m;
  cin >> n >> m;
  vector<int> a(m + 1);
  vector<int> pos(n + 1);
  bool cant = false;
  for(int i = 1; i <= m; i++) {
    cin >> a[i];
    pos[a[i]] = 1;
    if(a[i] == 1 || a[i] == n) {
      cant = true;
    }
  }
  if(cant) {
    cout << -1;
    return 0;
  }
  vector<int> ans(n + 1);
  ans[1] = 1;
  set<int> nums;
  for(int i = 2; i <= n; i++) {
    nums.insert(i);
  }
  int sum = 1;
  for(int i = 2; i <= n; i++) {
    ans[i] = *nums.begin();
    sum += *nums.begin();
    if(pos[i] && i * (i + 1) == 2 * sum) {
      ans[i] = *next(nums.begin());
      sum += -*nums.begin() + *next(nums.begin());
      nums.erase(*next(nums.begin()));
    }
    else {
      nums.erase(*nums.begin());
    }
  }
  for(int i = 1; i <= n; i++)
    cout << ans[i] << ' ';
}


