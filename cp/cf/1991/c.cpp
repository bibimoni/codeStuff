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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int mn = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end());
    vector<int> ans;
    while (mn != mx) {
      if (ans.size() == 40) {
        break;
      }
      int val = (mn + mx) / 2;
      vector<int> na(n);
      int cnt = 0;
      for (int num : a) {
        na[cnt] = abs(num - val);
        cnt += 1;
      }
      ans.push_back(val);
      swap(a, na);
      mn = *min_element(a.begin(), a.end());
      mx = *max_element(a.begin(), a.end());
    }
    if (mn != mx || ans.size() > 40) {
      cout << "-1\n";
      continue;
    }
    if (mn != 0) {
      ans.push_back(mn);
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " \n"[i == ans.size() - 1];
    }
  }
}


