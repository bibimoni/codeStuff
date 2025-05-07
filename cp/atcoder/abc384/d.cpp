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
  int n, s;
  cin >> n >> s;
  int olds = s;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> pre(n + 1);
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + a[i];
  }
  int sum = pre[n];
  map<int, int> idx;
  for (int i = 0; i <= n; i++) {
    idx[pre[i]] = i;
  }
  bool ok = false;
  if (s >= sum) {
    s = s - (s / sum) * sum;
    for (int i = n; i >= 1; i--) {
      if (s - (pre[n] - pre[i]) < 0) {
        if (s + sum <= olds) {
          s += sum;
        }
      }
      if (idx.count(s - (pre[n] - pre[i]))) {
        ok = true;
      }
    }
  } else {
    for (int i = 0; i <= n; i++) {
      if (idx.count(s - pre[i])) {
        ok = true;
      }
    }
  }
  if (ok) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  // suml + sumr + sum * k == s
  // 3 + 5 == 8
  // 8 % 3 == 5
  // s % (suml + sums) == sum
}


