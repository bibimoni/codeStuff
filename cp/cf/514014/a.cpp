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


// x x x x x x x x x
//  [    ]
//[    ]
//        [   ]

//1 2 2 1 1 1 0 0 0
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> cnt((int) 1e6 + 5);
  for(int i = 0; i < n; i++) {
    int s, f;
    cin >> s >> f;
    cnt[s]++;
    cnt[f + 1]--;
  }
  int ans = 0;
  for(int i = 1; i <= (int) 1e6; i++) {
    cnt[i] += cnt[i - 1];
    ans = max(ans, cnt[i]);
  }
  cout << ans << '\n';
}

