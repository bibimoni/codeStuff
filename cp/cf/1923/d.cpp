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

const int INF = (int) 2e9;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int a[n + 1];
    int left[n + 1], right[n + 1], pref[n + 1], ans[n + 1];
    pref[0] = 0;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      right[i] = left[i] = -1;
      ans[i] = INF;
      pref[i] = pref[i - 1] + a[i];
    }
    stack<int> st;
    for(int i = 1; i < n; i++) {
      while(st.size() && a[st.top()] == a[i])
        st.pop();
      if(st.size())
        left[i + 1] = st.top();
      st.push(i);
    }
    st = stack<int>();
    for(int i = n; i > 1; i--) {
      while(st.size() && a[st.top()] == a[i])
        st.pop();
      if(st.size())
        right[i - 1] = st.top();
      st.push(i);
    }
    for(int i = 1; i <= n; i++) {
      if(i > 1 && a[i - 1] > a[i]) {
        ans[i] = 1;
        continue;
      }
      if(i < n && a[i + 1] > a[i]) {
        ans[i] = 1;
        continue;
      }
      //right
      if(right[i] != -1) {
        int l = right[i], r = n;
        while(l <= r) {
          int mid = (l + r) >> 1;
          if(pref[mid] - pref[i] > a[i]) {
            r = mid - 1;
            ans[i] = min(mid - i, ans[i]);
          } 
          else {
            l = mid + 1;
          }
        }
      }
      //left
      if(left[i] != -1) {
        int r = left[i], l = 1;
        while(l <= r) {
          int mid = (l + r) >> 1;
          if(pref[i - 1] - pref[mid - 1] > a[i]) {
            l = mid + 1;
            ans[i] = min(i - mid, ans[i]);
          }
          else {
            r = mid - 1;
          }
        }
      }
    }
    for(int i = 1; i <= n; i++) {
      cout << (ans[i] == INF ? -1 : ans[i]) << " \n"[i == n];
    }
  }
}


