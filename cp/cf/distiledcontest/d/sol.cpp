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
#define all(x)         x.begin(), x.end()

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  string s; cin >> s;
  int x = s[0] - 'a' + 1;
  int y = s[1] - '0';
  int d[] = {-1, -1, 0, 1, 1, 0, -1, 1, -1};
  int ans = 0;
  for(int i = 0; i < 8; i++) {
    int uX = x + d[i];
    int uY = y + d[i + 1];
    if(uX >= 1 && uX <= 8 && uY >= 1 && uY <= 8) ans++;
  }
  cout << ans;
}

