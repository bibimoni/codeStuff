/**
 * File              : B.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 25.06.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define int long long
#define mod 1000000007
#define endl '\n'
#define TLE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI int t;cin>>t;while(t--)
#define MAXN (int) 1e6 + 5
int nxt() {int n; cin >> n; return n;}

signed main() {
  TLE;
  int n; cin >> n;
  int total = 0;
  int a[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    total += a[i];
  }
  int ans = total;
  int l = 1; 
  int curr = 0;
  int half = total >> 1;
  for(int r = 1; r <= n; r++) {
    curr += a[r];
    ans = min(ans, abs(2 * curr - total));
    while(curr > half && r >= l) {
      l++;
      curr -= a[l - 1];
      ans = min(ans, abs(2 * curr - total));
    }
  }
  cout << ans;
}

