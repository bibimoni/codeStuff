/**
 * File              : B.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 21.09.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </home/distiled/templates/debug.h>
#else
#define dbg(x...)
#endif

#define int           long long
#define all(x)        x.begin(), x.end()
#define sz(x)         (int) x.size()
#define MOD           1000000007
#define endl          '\n'
#define MULTI         int t;cin>>t;while(t--)
#define INF           (int) 1e18
#define MAXN          (int) 1e6 + 5

int nxt() {int n; cin >> n; return n;}

map<int, int> f;
vector<pair<int, int>> r;

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, before = INF; cin >> n;
  for(int i = 0, l = nxt(), r = nxt(); i < n; i++) {
    before = min(before, l);
    f[l]++; 
    f[r]--;
  }
  int curr = 0, ans = 0, check;
  for(auto [lmao, t] : f) {
    curr += t;
    if(ans < curr) {
      ans = curr;
      check = lmao; 
    }
    if(before != t) {
      r.push_back({before, lmao});
    }
    before = lmao;
  }
  dbg(check);
  cout << ans << endl;
 for(auto [l, r] : r) {
   dbg(l, r);
    if(l == check) {
      cout << l << ' ' << r;
      break;
    }
  }
}

