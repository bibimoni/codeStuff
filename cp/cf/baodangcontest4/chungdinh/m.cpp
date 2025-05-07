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
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int sum = accumulate(a.begin(), a.end(), 0ll);
  auto f = [&] (int x, vector<int> b) {
    int k = x;
    sort(b.begin(), b.end());
    int id = n, sad = 0;
    for(int i = 0; i < n; i++) {
      if(b[i] >= k) {
        id = i;
        break;
      } 
      sad += b[i];
    }
    int cnt = sum / k;
    sort(b.begin() + id, b.end(), [&] (int i, int j) {
      return i % k < j % k;
    });
    for(int i = id; i < n && cnt > 0; i++) {
      if(cnt >= b[i] / k) {
        cnt -= b[i] / k;
        sad += b[i] % k; 
        b[i] %= k;
      }
      else {
        sad = b[i] - cnt * k;
        b[i] -= cnt * k;
        cnt = 0;
        break;
      }
    }
    sort(b.begin(), b.end(), greater<int>());
    for(int i = 0; i < n && cnt > 0; i++) {
      if(cnt >= (b[i] / k) + (b[i] % k != 0)) {
        cnt -= (b[i] / k) + (b[i] % k != 0);
        sad -= max(b[i], b[i] - ((b[i] / k) + (b[i] % k != 0)) * k);
      }
      else {
        break;
      }
    }
    return sad;
  };
  int ans = sum;
  for(int i = 2; i * i <= sum; i++) {
    if(sum % i != 0) 
      continue;
    ans = min(ans, f(i, a));
    if(i * i != sum) {
      ans = min(ans, f(sum / i, a));
    }     
  }
    
  cout << min(ans, f(sum, a)) << '\n';
}

