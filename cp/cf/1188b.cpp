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
    for (; r > 0; r -= (r & -r)) {
      q += a[r]; // check query modification
    }
    return q;
  }

  void update(int r, T del) {
    for (; r <= n; r += (r & -r)) {
      a[r] += del; //check update rule
    }
  }
};
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, p, k;
  cin >> n >> p >> k;
  int a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n);
  for(int i = 0; i < n; i++) {
    (b[i] = a[i]) %= p;
    (b[i] = b[i] % p * a[i] % p) %= p;
    (b[i] = b[i] % p * a[i] % p) %= p;
    (b[i] = b[i] % p * a[i] % p) %= p;
    (b[i] = b[i] - (k % p * a[i] % p) % p + p) %= p;    
  }
  map<int, int> f;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    ans += f[b[i]];
    f[b[i]]++;
  }
  cout << ans;
}

