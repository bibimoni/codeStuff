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

  int a, b, c;
  cin >> a >> b >> c;
  cout << 100 << endl;
  for (int i = 1; i <= 50; i++)
    cout << a << " ";
  for (int i = 51; i <= 95; i++)
    cout << b << " ";
  for (int i = 96; i <= 99; i++)
    cout << c << " ";
  cout << (int)1e9 << endl;
}
