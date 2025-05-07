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
    vector<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
      int sum = a[i], cnt = 1;
      while (st.size() && st.back().first > sum / cnt) {
        sum += st.back().first * st.back().second;
        cnt += st.back().second;
        st.pop_back();
      }
      int add = sum / cnt;
      st.push_back({add, cnt - sum % cnt});
      if (sum % cnt != 0) {
        st.push_back({add + 1, sum % cnt});
      }
    }
    cout << st.back().first - st[0].first << '\n';
  }
}


