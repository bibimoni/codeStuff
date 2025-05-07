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
#define int            long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<string> b(n);
  for(int i = 0; i < n; i++) {
    cin >> b[i];
  }
  auto cv = [&] (string t) -> int {
    return stoi(t, 0, 16);
  };
  double ans = 0;
  map<array<int, 3>, int> f;
  for(int i = 0; i < n; i++) {
    array<int, 3> tmp;
    for(int j = 1; j <= 3; j++) {
      int f = cv(a[i].substr(j * 2 - 1, 2)), s = cv(b[i].substr(j * 2 - 1, 2));
      tmp[j - 1] = (s - f + 256) % 256;
    }
    f[tmp]++; 
    ans = max(ans, (double) f[tmp]);
  }
  ans = ans / (double) n;
  cout << fixed << setprecision(2) << ans * 100 << "%";
}


