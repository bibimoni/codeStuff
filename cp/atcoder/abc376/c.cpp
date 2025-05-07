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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end(), greater<int>());
  vector<int> c(n - 1);
  for (int i = 0; i < n - 1; i++) {
    cin >> c[i];
  }
  sort(c.begin(), c.end(), greater<int>());
  int idx = a[n - 1];
  int cnt = 0;
  int id = 0;
  for (int i = 0; i < n; i++) {
    if (id < n - 1 && c[id] < a[i]) {
      cnt += 1;
      idx = a[i];
    } else {
      id += 1;
    }
  }
  if (cnt > 1) {
    cout << "-1\n";
  } else {
    cout << idx;
  }
}


