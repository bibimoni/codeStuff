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
  int n;
  cin >> n;
  vector<int> a(n);
  set<int> st;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    st.insert(a[i]);
  }
  int m;
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    st.insert(b[i]);
  }
  int mxa = *max_element(a.begin(), a.end());
  int mxb = *max_element(b.begin(), b.end());
  //lower_bound(# distict elements) <= ans <= m * n
  if (mxa == mxb) {
    cout << "NO\n";
  } else {
    cout << st.size() << '\n';
  }
}

