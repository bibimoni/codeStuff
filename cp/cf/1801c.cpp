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
const int INF = (int) 2e9, N = 2e5 + 5;
template <class T>
class fenwick {
  vector<T> a;
  int n;

public:
  fenwick() {}

  fenwick(int n_) : n(n_) {
    // check initial value
    a.assign(n, static_cast<T>(0));
  }

  T query(int r) {
    T q = 0; // check default value of query
    for (; r > 0; r -= (r & -r)) {
      q = max(q, a[r]); // check query modification
    }
    return q;
  }

  void update(int r, T del) {
    for (; r <= n; r += (r & -r)) {
      a[r] = max(a[r], del); //check update rule
    }
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    int k[n + 1];
    vector<vector<int>> albums(n + 1);
    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0);
    vector<int> s;
    vector<int> maxIn(n + 1, 0); maxIn[0] = 0; 
    for(int i = 1; i <= n; i++) {
      cin >> k[i];
      int curr = -1;
      for(int j = 0; j < k[i]; j++) {
        int x; cin >> x;
        albums[i].push_back(x);
        maxIn[i] = max(maxIn[i], x);
        s.push_back(x);
      }
    }
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    sort(p.begin(), p.end(), [&] (int i, int j) {
      return maxIn[i] < maxIn[j];
    });
    int bound = 0;
    for(int i = 1; i <= n; i++) {
      int id = p[i];
      for(int j = 0; j < k[id]; j++) {
        albums[id][j] = lower_bound(s.begin(), s.end(), albums[id][j]) - s.begin() + 1;        
        bound = max(bound, albums[id][j]);
      }
    }
    fenwick<int> ft(bound + 1);
    int ans = 0;
    for(int id = 1; id <= n; id++) {
      int i = p[id];
      vector<int> seg;
      int currMax = -1;
      for(int j = 0; j < k[i]; j++) {
        if(albums[i][j] > currMax) {
          currMax = albums[i][j];
          seg.push_back(currMax);
        }
      }
      int curr = 0;
      for(int j = 0; j < seg.size(); j++) {
        curr = max(curr, ft.query(seg[j] - 1) + (int) seg.size() - j);
      }
      ft.update(seg.back(), curr);
      ans = max(ans, curr);
    }   
    cout << ans << '\n';
  }
}

