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
    int n; cin >> n;
    vector<int> a(n);
    vector<int> cnt(n);
    vector<int> pos[n];
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
      cnt[a[i]]++;
      pos[a[i]].push_back(i);
    }
    bool ok = true;
    vector<int> t0, t2;
    for(int i = 0; i < n; i++) {
      if(cnt[i] == 0) {
        t0.push_back(i);
      }
      if(cnt[i] == 2) {
        t2.push_back(i);
      }
      if(cnt[i] > 2) {
        ok = false;
        break;
      }
    }
    if(t0.size() < t2.size()) {
      ok = false;
    }
    vector<int> p = a, q = a;
    for(int i = 0; i < min(t0.size(), t2.size()); i++) {
      if(t0[i] > t2[i]) {
        ok = false;
        break;
      }
      p[pos[t2[i]][0]] = t0[i];
      q[pos[t2[i]][1]] = t0[i];
    }
    if(!ok) {
      cout << "NO\n";
      continue;
    }

    cout << "YES\n";
    for(int i = 0; i < n; i++) {
      cout << p[i] + 1 << " \n"[i == n - 1];
    }
    for(int i = 0; i < n; i++) {
      cout << q[i] + 1 << " \n"[i == n - 1];
    }
  }
}


