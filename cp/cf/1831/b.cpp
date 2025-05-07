/*
 * Author: distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
#define int int64_t 


void solve() {
  int n; cin>>n;
  vector<int> cnt1(2*n+1, 0), cnt2(2*n+1, 0);
  vector<int> a(n+2, 0);


  int pre= 0;

  auto process= [&](vector<int> &cnt) {
    for(int i=1;i<=n;++i) cin>>a[i];
  int Count= 0;
  for(int i=1;i<=n+1;++i) {
    if (a[i] != a[i-1]) {
      int x= a[i-1];
        cnt1[x]= max(cnt[i], Count);
      Count= 1;
    }
    else ++Count;
  }
  };

  process(cnt1);
  process(cnt2);
  
  int ans= 0;
  for(int i=1;i<=2*n;++i) ans= max(ans, cnt1[i] + cnt2[i]);

  cout<<ans<<'\n';
  
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  
  int t= 1;
  cin>>t;
  while(t--) solve();
}



