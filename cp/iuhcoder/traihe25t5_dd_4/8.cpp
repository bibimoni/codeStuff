#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> t(m);
  int ans = m;
  for (int i = 0; i < m; i++) {
    cin >> t[i];
    ans += t[i];
  }

  vector<int> p(m);
  iota(p.begin(), p.end(), 1);
  set<int> st{p.begin(), p.end()};
  vector<int> examdays;
  for (int i = n - 1; i >= 0; i--) {
    if (st.find(a[i]) != st.end()) {
      st.erase(a[i]);
      examdays.push_back(i);
    }
  }

  bool ok = true;
  int has = 0;
  int j = 0;
  sort(examdays.begin(), examdays.end());
  for (int idx : examdays) {
    int req = t[a[idx] - 1];
    has += idx - j;
    if (req > has) {
      ok = false;
      break;
    }
    has -= req;
    j = idx + 1;
  }

  if (!ok) {
    cout << "-1\n";
  } else {
    cout << ans;
  }
}
