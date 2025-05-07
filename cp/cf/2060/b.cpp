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
#define int int64_t 

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;3
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector cards(vector(n, vector(m, 0)));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> cards[i][j];
      }
      sort(cards[i].begin(), cards[i].end());
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&] (int i, int j) {
      return cards[i][0] < cards[j][0];
    });

    bool ok = true;
    int init = -1;
    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n; i++) {
        ok &= cards[p[i]][j] > init;
        init = cards[p[i]][j];
      }
    }
    if (!ok) {
      cout << "-1\n";
    } else {
      for (int i = 0; i < n; i++) {
        cout << p[i] + 1 << " \n"[i == n - 1];
      }
    }
  }
} 


