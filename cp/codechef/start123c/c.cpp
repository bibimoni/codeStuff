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
    int n, q;
    cin >> n >> q;
    int a[n];
    int sum = 0;
    for(int &i : a) {
      cin >> i;
      sum += i * 2;
    }
    while(q--) {
      int x;
      cin >> x;
      pair<int, int> id({-1, -1});
      for(int i = 0; i < n - 1; i++) {
        if(id != pair<int, int>({-1, -1}))
          break;
        for(int j = i + 1; j < n; j++) {
          if(sum - a[i] - a[j] == x) {
            id = {i, j};
            break;
          }
        }
      }
      vector<int> res(n);
      res[0] = a[id.first], res[n - 1] = a[id.second];
      if(id == pair<int, int>({-1, -1})) {
        cout << "-1\n";
        continue;
      }
      int k = 1;
      for(int i = 0; i < n; i++) {
        if(i != id.first && i != id.second)
          res[k++] = a[i];
      }
      for(int i : res) {
        cout << i << ' ';
      }
      cout << "\n";
    }
  }
}

