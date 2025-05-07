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
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 1; i < n; i++) {
      cin >> c[i];
    }
    vector<int> a(n);
    for (int i = 1; i < n; i++) {
      cin >> a[i];
    }
    int i = n - 1;
    while (i >= 0 && a[i] == 0) {
      i -= 1;
    }
    int ans = 0;
    for (; i > 0;) {
      ans += 1;
      int nj = i;
      for (int j = i - 1; j >= i - c[i]; j--) {
        nj = j;
        if (a[j] == 1) {
          break;
        }
      }
      i = nj;
    }
    cout << ans << '\n';
  }


