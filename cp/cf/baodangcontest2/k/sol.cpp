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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, X; 
  cin >> n >> X;
  int a[n];
  for(int &i : a) {
    cin >> i;
  }
  int pre[n], suf[n];
  memset(pre, -1, sizeof pre);
  memset(suf, -1, sizeof suf);
  for(int i = 1; i < n; i++) {
    for(int j = 0; j < i; j++) {
      if(a[i] >= a[j])
        pre[i] = max(a[i] + a[j], pre[i]);
    }
  }
  for(int i = n - 2; i >= 0; i--) {
    for(int j = n - 1; j > i; j--) {
      if(a[i] <= a[j]) {
        suf[i] = max(a[i] + a[j], suf[i]);
      }
    }
  }
  int ans = 0;
  for(int i = 1; i < n - 2; i++) {
    for(int j = i + 1; j < n - 1; j++) {
      if(a[j] >= a[i] && pre[i] != -1 && suf[j] != -1) {
        ans = max(pre[i] + suf[j], ans);
      }
    }
  }
  cout << (X - ans <= 0 ? 0 : X - ans);
}

