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

template <class T>
class fenwick {
  vector<T> a;
  int n;

public:
  fenwick() {}

  fenwick(int n_) : n(n_) {
    // check initial value
    a.assign(n + 5, static_cast<T>(0));
  }

  T query(int r) {
    T q = 0; // check default value of query
    for (; r <= n; r += (r & -r)) {
      q += a[r]; // check query modification
    }
    return q;
  }

  void update(int r, T del) {
    for (; r > 0; r -= (r & -r)) {
      a[r] += del; //check update rule
    }
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<int> b(m + 1);
    for(int i = 1; i <= m; i++) {
      cin >> b[i];
    }
    sort(b.begin() + 1, b.end());
    int ans = 0;
    priority_queue<int> pq;
    for(int i = 1; i <= n; i++) {
      int l = lower_bound(b.begin() + 1, b.end(), a[i]) - b.begin();
      int r = upper_bound(b.begin() + 1, b.end(), a[i]) - b.begin();
      if(pq.size() && pq.top() > r) {
        ans += pq.top() - r;
        pq.pop();
        pq.push(r);
      }
      pq.push(l);
    }
    fenwick<int> ft(n + 2);
    auto s = a;
    sort(s.begin() + 1, s.end());
    s.erase(unique(s.begin() + 1, s.end()), s.end());
    for(int i = 1; i <= n; i++) {
      int e = lower_bound(s.begin() + 1, s.end(), a[i]) - s.begin() + 1;
      ans += ft.query(e + 1);
      ft.update(e, 1);
    }
    cout << ans << '\n';
  }
}

