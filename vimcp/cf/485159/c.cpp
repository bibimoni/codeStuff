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

const int N = (int) 1e5 + 5;

struct BIT {
  int ft[N];
  void update(int id, int val) {
    while(id < N) {
      ft[id] = max(ft[id], val);
      id += (id & -id);
    } 
  }
  int get(int id) {
    int ans = 0;
    while(id > 0) {
      ans = max(ft[id], ans);
      id -= (id & -id);
    }
    return ans;
  }
};

vector<BIT> bi(32);
int dp[N];

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n; cin >> n;
  int a[n];
  vector<int> s;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    dp[i] = 1;
    s.push_back(a[i]);
  }
  sort(all(s));
  s.erase(unique(all(s)), s.end());
  int div[] = {2, 3, 5, 7, 11};
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int p = lower_bound(all(s), a[i]) - s.begin() + 1;
    int mask = 0; 
    for(int j = 0; j < 5; j++) {
      if(a[i] % div[j] == 0) mask |= (1 << j);
    }
    if(i != 0) {
      for(int j = 0; j < 32; j++) {
        if((mask & j) == 0) {
          dp[i] = max(dp[i], bi[j].get(p - 1) + 1);
        }
      }
    }
    bi[mask].update(p, dp[i]);
    ans = max(ans, dp[i]);
  }
  cout << ans;
}


