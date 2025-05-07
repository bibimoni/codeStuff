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

template <class T>
class Fenwick {
  vector<T> a;
  int n;

public:
  Fenwick() {}

  Fenwick(int n_) : n(n_) {
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
  const int N = int(2e5);
  Fenwick<int> ft(N + 5);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    multiset<int> st;
    vector<int> s;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      st.insert(a[i]);
    }
    vector<int> b(n + 1);
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
      if (st.find(b[i]) == st.end()) {
        ok = false;
      } else {
        st.erase(st.find(b[i]));
      }
    }
    ok &= st.size() == 0;
    if (!ok) {
      cout << "NO\n";
      continue;
    }
    auto inv = [&] (vector<int> &arr) -> int {
      int ret = 0;
      for (int i = n; i >= 1; i--) {
        ret += ft.query(arr[i] - 1);
        ft.update(arr[i], 1);
      }
      for (int i = 1; i <= n; i++) {
        ft.update(arr[i], -1);
      }
      return ret;
    };
    cout << (abs(inv(a) - inv(b)) % 2 == 0 ? "YES\n" : "NO\n");
  }
}


