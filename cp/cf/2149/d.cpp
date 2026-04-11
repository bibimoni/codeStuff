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
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s + " ";

    vector<int> ans(n + 1);
    int st = 0, cura = 0, sum = 0;
    int st2 = 0, curb = 0, sum2 = 0;
    for (int i = 1; i <= n; i++) {
      if (s[i] == 'a') {
        sum2 += st2 * curb;
        ans[i] += sum2;
        curb = 0;
        st2 += 1;

        cura += 1;
      } else {
        sum += st * cura;
        ans[i] += sum;
        cura = 0;
        st += 1;

        curb += 1;
      }
    }

    st = 0, cura = 0, sum = 0;
    st2 = 0, curb = 0, sum2 = 0;
    for (int i = n; i >= 1; i--) {
      if (s[i] == 'a') {
        sum2 += st2 * curb;
        ans[i] += sum2;
        curb = 0;
        st2 += 1;

        cura += 1;
      } else {
        sum += st * cura;
        ans[i] += sum;
        cura = 0;
        st += 1;

        curb += 1;
      }
    }

    cout << *min_element(ans.begin() + 1, ans.end()) << '\n';
  }
}
