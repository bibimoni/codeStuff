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
int n, a, b, ans = 0;

void Try(int i, int sa, int sb) {
  if(i == a + b) {
    if(max(sa, sb) >= n && abs(sa - sb) >= 2) ans++;
    return;
  }
  if(i < a + b) {
    if(max(sa, sb) >= n && abs(sa - sb) >= 2) return;
  }
  if(sa < a) Try(i + 1, sa + 1, sb);
  if(sb < b) Try(i + 1, sa, sb + 1);
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt; cin >> tt;
  while(tt--) {
    cin >> n >> a >> b;
    ans = 0;
    Try(0, 0, 0);
    cout << ans << '\n';
  }
}



