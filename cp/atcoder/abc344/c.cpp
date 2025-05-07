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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m, l;
  cin >> n;
  vector<int> a(n);
  for(int &i : a) {
    cin >> i;
  }
  cin >> m;
  vector<int> b(m);
  for(int &i : b) {
    cin >> i;
  }
  cin >> l;
  vector<int> c(l);
  for(int &i : c) {
    cin >> i;
  }
  set<int> possibleSum;
  for(int ia : a)
    for(int ib : b)
      for(int ic : c)
        possibleSum.insert(ia + ib + ic);
  int tt;
  cin >> tt;
  while(tt--) {
    int x; cin >> x;
    cout << (possibleSum.find(x) != possibleSum.end() ? "Yes\n" : "No\n");
  }
}


