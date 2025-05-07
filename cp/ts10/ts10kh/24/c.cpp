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

const int INF = 1e18;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  freopen("bai3.inp", "r", stdin);
  freopen("bai3.out", "w", stdout);  
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  vector<int> pre(n + 1, 0), cnt(n + 1, 0);
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    pre[i] = pre[i - 1] + a[i];
    cnt[i] = cnt[i - 1] + (a[i] % 2 == 0);
  }
  int id = 1, curr = -INF, cntE = 0;
  for(int i = k; i <= n; i++) {
    if(curr < pre[i] - pre[i - k]) {
      curr = pre[i] - pre[i - k];
      cntE = cnt[i] - cnt[i - k];
      id = i;
    }
    if(curr == pre[i] - pre[i - k] && cntE < cnt[i] - cnt[i - k]) {
      curr = pre[i] - pre[i - k];
      cntE = cnt[i] - cnt[i - k];
      id = i;
    }
  }  
  cout << id - k + 1 << ' ' << id << '\n';
}


