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
  const int DIGITS = 40;
  vector<int> d(DIGITS + 2, 0);
  int cur = 90;
  for (int i = 4; i <= DIGITS; i += 2) {
    d[i - 1] = cur;
    d[i] = cur;
    cur *= 10;
  }
  int n;
  cin >> n;
  if (n <= 10) {
    cout << n - 1;
    return 0;
  } else if (n <= 19) {
    cout << n - 10 << n - 10;
    return 0;
  }
  n -= 19;
  cur = 3;
  while (n - d[cur] >= 0) {
    n -= d[cur];
    cur += 1;
  }
  n -= 1;
  vector<int> ans(cur);
  ans[0] = ans[int(ans.size()) - 1] = 1;
  int m = ans.size() / 2;
  for (int i = m; i < ans.size(); i++) {
    ans[i] += n % 10;
    if (i != int(ans.size()) - i - 1) {
      ans[int(ans.size()) - i - 1] += n % 10;
    }
    n /= 10;
  }
  for (int i : ans) {
    cout << i;
  }
}


