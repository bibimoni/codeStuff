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
      int n, m;
      cin >> n >> m;
      int N = n + m + 1;
      vector<int> a(N);
      for (int i = 0; i < N; i++) {
        cin >> a[i];
      }
      vector<int> b(N);
      for (int i = 0; i < N; i++) {
        cin >> b[i];
      }
      vector<int> cnt(2, 0);
      vector<int> types(N);
      int pos = -1, cur = 0;
      for (int i = 0; i < N - 1; i++) {
        int cur_type = 0;
        if (a[i] < b[i]) {
          cur_type = 1;
        } 
        if (cnt[cur_type] == (cur_type == 0 ? n : m)) {
          cur_type = 1 ^ cur_type;
          if (pos == -1) {
            pos = i;
          }
        }
        types[i] = cur_type;
        cur += (cur_type == 0 ? a[i] : b[i]);
        cnt[cur_type] += 1;
      }
      dbg(pos);
      for (int i = 0; i < N - 1; i++) {
        int ans = cur - (types[i] == 0 ? a[i] : b[i]);
        if (pos != -1 && i < pos && types[i] == 1 - types[pos]) {
          int bad = 1 ^ types[pos];
          int t = (bad == 0) ? (a[pos] - b[pos]) : (-a[pos] + b[pos]);
          ans += t + (bad == 0 ? a[n + m] : b[n + m]);
        } else {
          ans += (types[i] == 0 ? a[n + m] : b[n + m]);
        }
        cout << ans << " ";
      }
      cout << cur << "\n";
    }
  }


