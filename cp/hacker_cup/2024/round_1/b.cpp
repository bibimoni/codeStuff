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

pair<vector<int>, vector<int>> spf(int n) {
  n++;
  vector<int> a(n, 1);
  a[1] = 0;
  a[0] = 0;
  for (int i = 2; i < n; i++) {
    if (a[i] == 1) {
      for (int j = i * i; j < n; j += i) {
        a[j] = 0;
      }
    }
  }
  vector<int> pr;
  for (int i = 2; i < n; i++) {
    if (a[i] == 1) {
      pr.push_back(i);
    }
  }
  return {a, pr};
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  freopen("prime_subtractorization_input.txt", "r", stdin);
  freopen("b.txt", "w", stdout);
  int tt;
  cin >> tt;
  const int N = int(1e7 + 5);
  auto [fac, pr] = spf(N);
  vector<int> pre(N);
  for (int i = 5; i < N; i++) {
    pre[i] = pre[i - 1] + (fac[i - 2] && fac[i]);
  }
  for (int ttt = 1; ttt <= tt; ttt++) {
    int n;
    cin >> n;
    cout << "Case #" << ttt << ": ";
    if (n <= 4) {
      cout << "0\n";
      continue;
    }
    cout << pre[n] + 1 << '\n';
  }
}


