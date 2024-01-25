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
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    stack<pair<int, int>> st;
    st.push({0, -1});
    int ans[n];
    memset(ans, 0, sizeof ans);
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
    cout << *max_element(ans, ans + n);
  }

    