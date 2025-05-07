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

const int N = (int) 5005, LG = 20;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n; cin >> n;
  vector<int> a(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> b(n + 1);
  b[1] = -1;
  priority_queue<int> pq;
  for(int i = 2; i <= n; i++) {
    for(int j = i; j >= 1; j--) {
      if(a[i] > a[j]) {
        b[i] = max(b[i], a[i] + a[j]);
      }
    }
  }
  int ans = 0;
  for(int i = 3; i <= n; i++) {
    for(int j = 2; j < i; j++) {
      if(b[j] == -1 || a[i] < a[j]) {
        continue;
      }
      ans = max(a[i] + b[j], ans);
    }
  }
  cout << ans;
}


