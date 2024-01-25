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

const int N = (int) 1e5 + 5;

int ft[N];
void update(int id, int val) {
  for(; id < N; id += (id & -id)) ft[id] += val;
}
int get(int id) {
  int ans = 0; for(; id > 0; id -= (id & -id)) ans += ft[id]; return ans;
}
set<int> pos1;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1); int sum = 0;
    pos1.clear(); //PLEASE REMEMBER TO RESET GLOBAL VARIABLE YOU DUMB SHIT.
    for(int i = 1; i <= n; i++) ft[i] = 0;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      sum += a[i];
      update(i, a[i]);
      if(a[i] == 1) pos1.insert(i);
    }
    while(q--) {
      int type; cin >> type;
      if(type == 1) {
        dbg(a);
        int s; cin >> s;
        dbg("query 1", s);
        if(s > sum) {
          cout << "NO\n";
          continue;
        }
          dbg(s & 1, sum & 1);
        if((s & 1) == (sum & 1)) {
          cout << "YES\n";
        }
        else {
          if(pos1.size() == 0) {
            cout << "NO\n";
            continue;
          }
          int sumAfter = get(n) - get(*pos1.begin());
          int sumBefore = get(*pos1.rbegin() - 1);
          int maxAltParity = max(sumAfter, sumBefore);
          dbg(sumAfter, sumBefore);
          if(maxAltParity >= s) {
            cout << "YES\n";
          }
          else {
            cout << "NO\n";
          }
        }
      }
      else {
        int i, u; cin >> i >> u;
        sum += u - a[i];
        if(a[i] != u) {
          if(u == 1) {
            pos1.insert(i);
          }
          if(a[i] == 1) {
            pos1.erase(pos1.find(i));
          }
        }
        update(i, u - a[i]);
        a[i] = u;
      }
    }
  }
}

