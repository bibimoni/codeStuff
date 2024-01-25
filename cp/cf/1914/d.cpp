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

bool check(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
  return a.second != b.second && b.second != c.second && a.second != c.second;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    vector<pair<int, int>> a(n), b(n), c(n);
    for(int i = 0, x; i < n; i++) cin >> x, a[i] = {x, i};
    for(int i = 0, x; i < n; i++) cin >> x, b[i] = {x, i};
    for(int i = 0, x; i < n; i++) cin >> x, c[i] = {x, i};

    sort(a.begin(), a.end(), [&] (pair<int, int> m1, pair<int, int> m2) {return m1.first > m2.first;});
    sort(b.begin(), b.end(), [&] (pair<int, int> m1, pair<int, int> m2) {return m1.first > m2.first;});
    sort(c.begin(), c.end(), [&] (pair<int, int> m1, pair<int, int> m2) {return m1.first > m2.first;});
    int ans = 0;
    if(check(a[0], b[0], c[0])) ans = max(ans, a[0].first + b[0].first + c[0].first);
    if(n >= 2) {
      int p[] = {0, 1, 1};
      do {  
        int t1 = p[0], t2 = p[1], t3 = p[2];
        if(check(a[t1], b[t2], c[t3])) ans = max(ans, a[t1].first + b[t2].first + c[t3].first);
      } while(next_permutation(p, p + 3));
      int p1[] = {0, 0, 1};
      do {  
        int t1 = p1[0], t2 = p1[1], t3 = p1[2];
        if(check(a[t1], b[t2], c[t3])) ans = max(ans, a[t1].first + b[t2].first + c[t3].first);
      } while(next_permutation(p1, p1 + 3));
      if(check(a[1], b[1], c[1])) ans = max(ans, a[1].first + b[1].first + c[1].first);
    }
    if(n >= 3) {
      int p[] = {1, 1, 2};
      do {  
        int t1 = p[0], t2 = p[1], t3 = p[2];
        if(check(a[t1], b[t2], c[t3])) ans = max(ans, a[t1].first + b[t2].first + c[t3].first);
      } while(next_permutation(p, p + 3));
      int m[] = {0, 1, 2};
      do {  
        int t1 = m[0], t2 = m[1], t3 = m[2];
        if(check(a[t1], b[t2], c[t3])) ans = max(ans, a[t1].first + b[t2].first + c[t3].first);
      } while(next_permutation(m, m + 3));
      int m1[] = {0, 2, 2};
      do {  
        int t1 = m1[0], t2 = m1[1], t3 = m1[2];
        if(check(a[t1], b[t2], c[t3])) ans = max(ans, a[t1].first + b[t2].first + c[t3].first);
      } while(next_permutation(m1, m1 + 3));
      int m2[] = {0, 0, 2};
      do {  
        int t1 = m2[0], t2 = m2[1], t3 = m2[2];
        if(check(a[t1], b[t2], c[t3])) ans = max(ans, a[t1].first + b[t2].first + c[t3].first);
      } while(next_permutation(m2, m2 + 3));
      int m3[] = {1, 2, 2};
      do {  
        int t1 = m3[0], t2 = m3[1], t3 = m3[2];
        if(check(a[t1], b[t2], c[t3])) ans = max(ans, a[t1].first + b[t2].first + c[t3].first);
      } while(next_permutation(m3, m3 + 3));
      if(check(a[2], b[2], c[2])) ans = max(ans, a[2].first + b[2].first + c[2].first);
    }
    cout << ans << '\n';
  }
}


