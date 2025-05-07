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

struct Query {
  int l, r, id, i, j;
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int a[n + 1];
    vector<pair<int, int>> diffPair;
    map<int, int> f;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    stack<int> st;
    for(int i = 1; i <= n; i++) {
      while(st.size() && a[st.top()] == a[i]) {
        st.pop();
      }
      if(st.size()) {
        diffPair.push_back({st.top(), i});
      }
      st.push(i);
    }
    int q;
    cin >> q;
    dbg(diffPair);
    for(int i = 0; i < q; i++) {
      int u, v;
      cin >> u >> v;
      // dbg(u, v);
      int pos = -1, l = 0, r = diffPair.size() - 1;
      while(l <= r) {
        int mid = (l + r) >> 1;
        if(diffPair[mid].second <= v) {
          pos = mid;
          l = mid + 1;
        }
        else {
          r = mid - 1;
        }
      }
      // dbg(pos);
      if(pos == -1 || diffPair[pos].first < u) {
        cout << "-1 -1\n";
        continue;
      }
      else {
        cout << diffPair[pos].first << ' ' << diffPair[pos].second << '\n';
      }
    }
    cout << '\n';
  }
}


