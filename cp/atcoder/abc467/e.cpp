/**
 * Author: distiled
 */
#include <bits/stdc++.h>
#include <numeric>
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
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n - 1);
  for (int i = 0; i < n - 1; i++) {
    cin >> b[i];
  }

  vector<int> x(n);
  for (int i = 1; i < n; i++) {
    x[i] = b[i - 1] - x[i - 1];
  }
  
  auto cost = [&](int i, int s) -> int64_t {
    int co = i % 2 == 0 ? 1 : -1;
    return (x[i] + co * s - a[i] + int(1e9) * m) % m;
  };

  auto find_s = [&](int i) -> int64_t {
    int rco = i % 2 == 0 ? -1 : 1;
    int val = (x[i] - a[i] + int(1e9) * m) % m;
    return (val * rco + m) % m;
  };
  
  auto wrap_s = [&](int i) -> int {
    if (i %  2 == 0) return find_s(i);
    else return (find_s(i) + 1) % m;
  };

  // auto find_s = [&](int i) -> int64_t {
  //   int rco = i % 2 == 0 ? -1 : 1; 
  //   return (rco * x[i] + int64_t(1e9) * m) % m;
  // };

  vector<int> idx(n); 
  iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(), [&](int i, int j) {
    return wrap_s(i) < wrap_s(j);  
  });
  dbg(idx);
  
  int s = 0, cur = 0;
  for (int i = 0; i < n; i++) {
    cur += cost(i, s);
    dbg(find_s(i));
  }

  int id = 0;
  while(id < n && wrap_s(idx[id]) == 0) {
    id += 1;
  }
  int ans = cur;
  for (; id < n; id++) {
    int i = idx[id]; 
    int gap = wrap_s(i) - s - 1;
    assert(gap >= 0);
    int n_even = ((n - 1) / 2) + 1; // include 0
    int n_odd = n - n_even;
    cur += (n_even - n_odd) * gap;
    int j = id;
    while (j < n && wrap_s(i) == wrap_s(idx[j])) {
      dbg(idx[j]);
      if (idx[j] % 2 == 0) {
        cur -= m;
      } else {
        cur += m;  
      }
      j += 1;
    }
    cur += n_even;
    cur -= n_odd;
    dbg(cur, n_even, n_odd, gap, find_s(i));
    ans = min(ans, cur);
    id = j - 1;
    s = wrap_s(i);
  } 

  cout << ans << '\n';
}
