/**
 * Author: distiled
 */
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector pre(n, 1);
  for (int i = 1; i < n; i++) {
    pre[i] = pre[i - 1] & (a[i] >= a[i - 1]);
  }
  vector suf(n, 1);
  for (int i = n - 2; i >= 0; i--) {
    suf[i] = suf[i + 1] & (a[i] <= a[i + 1]);
  }

  multiset<int> st;
  for (int i = 0; i < k - 1; i++) {
    st.insert(a[i]);
  }

  bool ok = false;
  for (int i = k - 1; i < n; i++) {
    st.insert(a[i]);
    bool p1 = (i == k - 1 || pre[i - k]);
    bool p2 = (i == n || suf[i + 1]);
    int prv = (i == k - 1 ? -1 : a[i - k]);
    int nxt = (i == n ? n + 1 : a[i + 1]);
    int mx = *st.rbegin();
    int mn = *st.begin();
    if (p1 && p2 && mx <= nxt && mn >= prv) {
      ok = true;
    }
    st.erase(st.find(a[i - k + 1]));
  }
  
  cout << (ok ? "Yes\n" : "No\n");
}
