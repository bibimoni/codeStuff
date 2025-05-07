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
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++) 
        cin >> a[i][j];
    vector<vector<int>> b(n, vector<int>(m));
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++) 
        cin >> b[i][j];
    sort(a.begin(), a.end(), [&] (vector<int>& i, vector<int>& j) {
      return *min_element(i.begin(), i.end()) < *min_element(j.begin(), j.end());
    });
    sort(b.begin(), b.end(), [&] (vector<int>& i, vector<int>& j) {
      return *min_element(i.begin(), i.end()) < *min_element(j.begin(), j.end());
    });
    auto sortCol = [&] (vector<vector<int>> &arr) -> void {
      vector<vector<int>> ret = arr;
      vector<pair<int, int>> tmp(m);
      for(int i = 0; i < m; i++) {
        tmp[i] = {arr[0][i], i};
      }
      sort(tmp.begin(), tmp.end());
      for(int j = 0; j < m; j++) {
        vector<int> t(n);
        for(int i = 0; i < n; i++) {
          t[i] = arr[i][tmp[j].second];
        }
        // dbg(t);
        for(int i = 0; i < n; i++) {
          ret[i][j] = t[i];
        }
      }
      arr = ret;
    };
    sortCol(a);
    sortCol(b);
    cout << (a == b ? "YES\n" : "NO\n");
  }
}


