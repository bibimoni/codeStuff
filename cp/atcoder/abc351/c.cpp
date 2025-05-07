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
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> ans;
  ans.push_back(a[0]);
  for(int i = 1; i < n; i++) {
    ans.push_back(a[i]);
    while(ans.size() >= 2 && ans[ans.size() - 2] == ans.back()) {
      int tmp = ans.back() + 1;
      ans.pop_back();
      ans.pop_back();
      ans.push_back(tmp);
    }
  }
  cout << (int) ans.size();
}


