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
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int j1 = 0, j2 = 0, ans = 0;
    multiset<int> st1, st2;
    int cnt1 = 0, cnt2 = 0;
    auto winsert = [&](multiset<int> &st, int val, int &cnt) -> void {
      if (st.count(val) == 0) {
        cnt += 1;
      }
      st.insert(val);
    };
    auto werase = [&](multiset<int> &st, int val, int &cnt) -> void {
      if (st.count(val) == 1) {
        cnt -= 1;
      }
      st.erase(st.find(val));
    };
    for (int i = 0; i < n; i++) {
      winsert(st1, a[i], cnt1);
      winsert(st2, a[i], cnt2);
      while (j1 < i && cnt1 > k) {
        werase(st1, a[j1], cnt1);
        j1 += 1;
      }
      while (j2 < i && cnt1 >= k) {
        werase(st2, a[j2], cnt2);
        if (cnt2 < k) {
          winsert(st2, a[j2], cnt2);
          break;
        }
        j2 += 1;
      }
      if (cnt1 == k && cnt2 == k) {
        dbg(j1, j2, st1, st2, i);
        ans += j2 - j1 + 1;
      }
    }
    cout << ans << '\n';
  }
}
