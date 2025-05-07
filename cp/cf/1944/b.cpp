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
    int n, k;
    cin >> n >> k;
    vector<int> a(2 * n);
    for(int i = 0; i < 2 * n; i++) {
      cin >> a[i];
    }
    vector<int> posL(n + 1, 0);
    for(int i = 0; i < n; i++) {
      posL[a[i]]++;
    }
    vector<int> posR(n + 1, 0);
    for(int i = n; i < 2 * n; i++) {
      posR[a[i]]++;
    }
    vector<int> ansL, ansR;
    vector<int> others;
    for(int i = 1; i <= n; i++) {
      if(posL[i] == 2) {
        ansL.push_back(i);
      }
      if(posR[i] == 2) {
        ansR.push_back(i);
      }
      else if(posL[i] == 1 && posR[i] == 1) {
        others.push_back(i);
      }
    }
    int cnt = 0;
    for(int i = 0; i < min(ansL.size(), ansR.size()); i++) {
      if(cnt + 2 > 2 * k)
        break;
      cout << ansL[i] << ' ' << ansL[i] << ' ';
      cnt += 2;
    }
    int rem = 2 * k - cnt;
    for(int i = 0; i < rem; i++) {
      cout << others[i] << ' ';
    }
    cout << '\n';
    cnt = 0;
    for(int i = 0; i < min(ansL.size(), ansR.size()); i++) {
      if(cnt + 2 > 2 * k)
        break;
      cout << ansR[i] << ' ' << ansR[i] << ' ';
      cnt += 2;
    }
    rem = 2 * k - cnt;
    for(int i = 0; i < rem; i++) {
      cout << others[i] << ' ';
    }
    cout << '\n';
  }
}


