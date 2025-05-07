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
#define all(x)         x.begin(), x.end()

const int N = (int) 2e5 + 5, INF = (int) 1e18;
int pref[N], ft[N], k;

void update(int id, int val) {
  while(id < N) {
    ft[id] += val;
    id += (id & -id);
  }
}

int get(int id) {
  int ans = 0; 
  while(id > 0) {
    ans += ft[id];
    id -= (id & -id);
  }
  return ans;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, q; cin >> n >> k >> q;
  int minL = INF, maxR = 0;
  for(int l, r, i = 0; i < n; i++) {
    cin >> l >> r;
    pref[l]++; pref[r + 1]--;
    minL = min(minL, l); maxR = max(maxR, r);
  }
  for(int i = 1; i < N; i++) {
    pref[i] += pref[i - 1];
    update(i, pref[i] >= k);
  }
  while(q--) {
    int l, r; cin >> l >> r;
    //dumb
    cout << (get(r) - get(l - 1)) << '\n';
    //faster way is:
    //cout << cnt[r] - cnt[l - 1] << '\n';
  }
}


