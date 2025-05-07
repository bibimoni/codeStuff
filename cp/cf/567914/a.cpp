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
  int n, m;
  cin >> m >> n;
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  auto findRect = [&] (vector<int> &a) {
    stack<pair<int, int>> st;
    st.push({0, -1});
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
      while(st.size() && st.top().first >= a[i]) {
        st.pop();
      }
      if(!st.size()) {
        ans[i] += a[i];
      }
      else {
        int w = i - st.top().second;
        ans[i] += w * a[i];
      }
      st.push({a[i], i});
    }
    st = stack<pair<int, int>>();
    st.push({0, n});
    for(int i = n - 1; i >= 0; i--) {
      while(st.size() && st.top().first >= a[i]) {
        st.pop();
      }
      if(st.size()) {
        int w = st.top().second - i - 1;
        ans[i] += w * a[i];
      }
      st.push({a[i], i});
    }
    return *max_element(ans.begin(), ans.end());
  };
  int ret = findRect(h);
  for (int i = 0; i < n; i++) {
    h[i] = m - h[i];
  }
  ret = max(ret, findRect(h));
  cout << ret << '\n';
}

