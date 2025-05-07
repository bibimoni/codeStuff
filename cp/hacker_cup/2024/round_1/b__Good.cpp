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
  const int N = int(1e7 + 5);
  auto [_, pr] = spf(N);
  int tt;
  cin >> tt;
  for (int ttt = 1; ttt <= tt; ttt++) {
    int n;
    cin >> n;
    set<int> s;
    set<pair<int, pair<int, int>>> st;
    for (int a : pr) {
      if (a > n) {
        break;
      }
      for (int b : pr) {
        if (b > n) {
          break;
        }
        for (int c : pr) {
          if (c > n) {
            break;
          }
          if (b > c && b - c == a) {
            if (s.find(a) == s.end()) {
              st.insert({a, {b, c}});
            }
            s.insert(a);
          }
        }
      }
    }
    // dbg(st);
    cout << "Case #" << ttt << ": ";
    cout << s.size() << '\n';
  } 
}

