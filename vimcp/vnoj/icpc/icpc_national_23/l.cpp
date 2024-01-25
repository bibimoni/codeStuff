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

const int N = (int) 1e4 + 5;
int n, m, k, a[N];

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  cin >> n >> m >> k;
  for(int i = 1; i <= m; i++) cin >> a[i];
  vector<int> ans(n + 1, 0);
  for(int i = 1; i <= m; i++) {
    int l = i;
    vector<int> cnt(n + 1, 0), num(m + 1, 0);
    for(int j = l; j <= min(l + k - 1, m); j++) {
      ans[a[j]] = max(ans[a[j]], num[cnt[a[j]] + 1] + 1);
      num[++cnt[a[j]]]++;
    }
    for(int k = 1; k <= n; k++) {
      ans[k] = max(ans[k], num[cnt[k] + 1] + 1);
    }
  }
  for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
}



