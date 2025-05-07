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

const int INF = (int) 2e9;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1, 0);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> dp(n + 1, INF);
  dp[0] = 0;
  multiset<pair<int, int>> st;
  for(int i = 0; i <= n; i++) {
    while(st.size() && (*st.begin()).second < i) {
      st.erase(st.begin());
    }
    if(st.size()) {
      dp[i] = min(dp[i], (*st.begin()).first);
    }
    st.insert({dp[i] + 1, i + a[i]});
    if(i + 1 <= n && a[i] >= a[i + 1]) {
      dp[i + 1] = min(dp[i + 1], dp[i] + 1);
    }
    // dbg(st);
  }
  if(dp[n] >= INF) 
    cout << "CANNOT GET DESTINATION";
  else 
    cout << dp[n];
}


