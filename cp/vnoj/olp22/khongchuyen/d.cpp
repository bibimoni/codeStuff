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
#define pb             push_back
#define all(x)         x.begin(), x.end()
#define sz(x)          (int) x.size()
#define endl           '\n'
#define MULTI          int tt;cin>>ttwhile(tt--)
inline int nxt() { int n; cin >> n; return n; }

unordered_map<int, bool> base;
void genBase(int exp) {
  for(int curr = 1; curr < (int) 1e9 + 1; curr *= exp) {
    base[curr] = true;
  }
}

int _(int val, vector<int> a) {
  int l = 0, r = sz(a) - 1;
  int ans = 0;
  if(val <= 0) return 0;
  while(l <= r) {
    int mid = (l + r) >> 1;
    if(a[mid] > val) {
      r = mid - 1;
    }
    else {
      ans = max(ans, mid);
      l = mid + 1;
    }
  }
  if(a[ans] > val) return 0;
  return ans + 1;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  for(int i : {2, 3, 5}) genBase(i);
  int n, q; cin >> n >> q;
  vector<int> a; 
  for(int i = 0, x; i < n; i++) {
    cin >> x;
    if(base[x]) a.pb(x);
  }
  sort(all(a));
  while(q--) {
    int l, r; cin >> l >> r;
    if(sz(a) == 0) {
      cout << 0 << endl;
      continue;
    }
    int u = _(r, a), v = _(l - 1, a);
    cout << u - v << endl;
  }
}



