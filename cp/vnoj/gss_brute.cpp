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
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  const int INF = (int) 1e18;
  auto getMax = [&] (int l, int r) -> int {
    int curr = a[l], ans = a[l];
    for(int i = l + 1; i <= r; i++) {
      curr = max(curr + a[i], a[i]);
      ans = max(ans, curr);
    }
    return ans;
  };
  int m;
  cin >> m;
  ofstream ft("gss_brute");
  while(m--) {
    int l, r;
    cin >> l >> r;
    ft << getMax(l, r) << '\n';
  }
}

