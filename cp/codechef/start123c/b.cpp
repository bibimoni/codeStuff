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
    int tt;
    cin >> tt;
    while(tt--) {
      int n;
      cin >> n;
      int a[n];
      for(int &i : a) {
        cin >> i;
      }
      sort(a, a + n, [&] (int i, int j) {
        return i * 2 < j * 2;
      });
      swap(a[1], a[n - 1]);
      int ans = 0;
      for(int i = 0; i < n - 1; i++) {
        ans += a[i] + a[i + 1];
      }
      cout << ans << '\n';
    }
  }

