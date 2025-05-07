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
#define int int64_t

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> ids;    
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] != i) {
        ids.insert(i);
      }
    }
    auto mex = [&] (vector<int> b) -> int {
      int ret = 0;
      set<int> st(b.begin(), b.end());
      for (int num : st) {
        if (ret == num) {
          ret += 1;
        } else {
          break;
        }
      }
      return ret;
    };
    vector<int> ans;
    while (ids.size()) {
      int v = mex(a);
      if(v == n) {
        a[*ids.begin()] = n;
        ans.push_back(*ids.begin());
      } else {
        a[v] = v;
        ans.push_back(v);
        ids.erase(v);
      }
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] + 1 << " \n"[i == ans.size() - 1];
    }
  }
}

