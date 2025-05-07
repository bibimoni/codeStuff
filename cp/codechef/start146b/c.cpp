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
    vector<int> p(n);
    vector<int> base;
    if (n >= 5) {
      base = {1, 3, 2};
    } else if (n < 5) {
      base = {1, 2};
    }
    for (int i = 0, j = 0; i < min(n, int(6)); i += 2, j += 1) {
      p[i] = base[j];
    }
    for (int cur = 4, i = 6; i < n; i += 2, cur += 1) {
      p[i] = cur;
    }
    int mx = *max_element(p.begin(), p.end()) + 1;
    for (int i = 1; i < n; i += 2, mx += 1) {
      p[i] = mx;
    }
    bool ok = true;
    for (int i = 1; i < n - 1; i++) {
      ok &= (p[i] >= (p[i + 1] - p[i - 1]) * (p[i + 1] - p[i - 1]));
    }
    dbg(p);
    set<int> st(p.begin(), p.end());
    mx = *max_element(p.begin(), p.end());
    assert(ok == true && mx == n && st.size() == n);
    for (int i = 0; i < n; i++) {
      cout << p[i] << " \n"[i == n - 1];
    }
  }
}


