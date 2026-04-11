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
  string s;
  cin >> s;
  if (s == "red") {
    cout << "SSS";
  } else if (s == "blue") {
    cout << "FFF";
  } else if (s == "green") {
    cout << "MMM";
  } else {
    cout << "Unknown";
  }
}
