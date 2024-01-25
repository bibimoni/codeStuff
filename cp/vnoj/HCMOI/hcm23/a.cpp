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

const int N = 100005;
int ft[N] = {};

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
  int n; cin >> n;
  int a[n + 1]; vector<int> idx(n + 1);
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    idx[a[i]] = i;
    update(idx[a[i]], 1);
  }
  bool left = true; int currLeft = 1, currRight = n;
  for(int i = 0; i < n; i++) {
    if(left) {
      cout << get(idx[currLeft]) - 1 << '\n';
      update(idx[currLeft++], -1); 
    }
    else {
      cout << get(n) - get(idx[currRight] - 1) - 1 << '\n';
      update(idx[currRight--], -1);
    }
    left = !left;
  }
}


