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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(x);
    for(int i = 0; i < x; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    auto check = [&] (int f, int s, int i) {
      return (s - f == 2 && i < x - 1) || (f + n - s == 2 && i == x - 1);
    };
    auto get = [&] (int f, int s, int i) {
      if(i < x - 1) {
        return s - f - 1;
      }
      else {
        return f + n - s - 1;
      }
    };
    int ans = x - 2;
    for(int i = 0; i < x; i++) {
      if(i < x - 1 && check(a[i], a[i + 1], i)) {
        ans++;
      }
      if(i == x - 1 && check(a[0], a[x - 1], i)) {
        ans++;
      }
    }
    for(int i = 0; i < x && y > 0; i++) {
      if(i < x - 1 && get(a[i], a[i + 1], i) % 2 == 1) {
        int g = min(get(a[i], a[i + 1], i) / 2, y);
        dbg(g);
        y -= g;
        ans += g + 1;
      }
    }
    for(int i = 0; i < x && y > 0; i++) {
      if(i < x - 1 && get(a[i], a[i + 1], i) % 2 == 0) {
        int g = min(get(a[i], a[i + 1], i) / 2, y);
        dbg(g);
        y -= g;
        ans += g;
      }
    }
    cout << ans << '\n';
  }
}

