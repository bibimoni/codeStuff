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
#define all(x)         x.begin(), x.end()

const int N = (int) 1e4 + 5;

vector<int> check(N, 0);
int a[N], b[N];
int dp[N][N];
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m; cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < m; i++) {
    cin >> b[i];
  }
  vector<int> c;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(a[i] == b[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  int i = n - 1, j = m - 1;
  while(i != 0 || j != 0) {
    if(a[i] == b[j]) {
      c.push_back(a[i]);
      i--;
      j--;
    }
    else {
      if(dp[i - 1][j] > dp[i][j - 1] && i > 0) {
        i--;
      }
      else if(dp[i - 1][j] >= dp[i][j - 1] && j > 0) {
        j--;
      }
    }
  }
  if(a[0] == b[0]) c.push_back(a[0]);
  reverse(all(c));
  dbg(c);
  int prev = c[0]; int ans = 1; bool up = true;
  for(int i = 1; i < c.size(); i++) {
    if(up && prev < c[i]) ans++, prev = c[i], up = !up;     
    if(!up && prev > c[i]) ans++, prev = c[i], up = !up;
  }
  up = false; int ans1 = 1;
  for(int i = 1; i < c.size(); i++) {
    if(up && prev < c[i]) ans++, prev = c[i], up = !up;     
    if(!up && prev > c[i]) ans++, prev = c[i], up = !up;
  }
  dbg(ans, ans1);
  cout << (max(ans, ans1) >= 3 ? max(ans, ans1) : 0);
}


