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
  int n, k;
  cin >> n >> k;
  int a[n + 1], sufMax[n + 2], preMin[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    sufMax[i] = preMin[i] = -1;
  }
  if(n <= 10) {
    int curr = 0, ans = 0;
    for(int i = 1; i < k; i++) {
      curr += a[i];
    }
    for(int i = k; i < n - k + 1; i++) {
      curr += a[i];
      int tmp = 0;
      for(int j = i + 1; j < i + k; j++) {
        tmp += a[j];
      }
      for(int j = i + k; j <= n; j++) {
        tmp += a[j];
        ans = max(ans, abs(tmp - curr));
        tmp -= a[j - k + 1];
      }
      curr -= a[i - k + 1];
    }
    cout << ans << '\n';
    return 0;
  }
  sufMax[n + 1] = -1;
  int curr = 0;
  for(int i = 1; i < k; i++)
    curr += a[i];
  for(int i = k; i <= n; i++) {
    curr += a[i];
    if(preMin[i - 1] == -1) {
      preMin[i] = curr;
    }
    else {
      preMin[i] = min(preMin[i - 1], curr);
    }
    curr -= a[i - k + 1];
  }
  curr = 0;
  for(int i = n; i > n - k + 1; i--)
    curr += a[i];
  for(int i = n - k + 1; i >= 1; i--) {
    curr += a[i];
    if(sufMax[i + 1] == -1) {
      sufMax[i] = curr;
    }
    else {
      sufMax[i] = max(sufMax[i + 1], curr);
    }
    curr -= a[i + k - 1];
  }
  int ans = 0;
  for(int i = k; i < n - k + 1; i++) {
    ans = max(ans, abs(preMin[i] - sufMax[i + 1]));
  }
  int preMax[n + 1], sufMin[n + 2];
  sufMin[n + 1] = -1;
  for(int i = 1; i <= n; i++) {
    preMax[i] = sufMin[i] = -1;
  }
  curr = 0;
  for(int i = 1; i < k; i++)
    curr += a[i];
  for(int i = k; i <= n; i++) {
    curr += a[i];
    if(preMax[i - 1] == -1) {
      preMax[i] = curr;
    }
    else {
      preMax[i] = max(preMax[i - 1], curr);
    }
    curr -= a[i - k + 1];
  }
  curr = 0;
  for(int i = n; i > n - k + 1; i--)
    curr += a[i];
  for(int i = n - k + 1; i >= 1; i--) {
    curr += a[i];
    if(sufMin[i + 1] == -1) {
      sufMin[i] = curr;
    }
    else {
      sufMin[i] = min(sufMin[i + 1], curr);
    }
    curr -= a[i + k - 1];
  }
  for(int i = k; i < n - k + 1; i++) {
    ans = max(ans, abs(preMax[i] - sufMin[i + 1]));
  }
  cout << ans << '\n';
}


