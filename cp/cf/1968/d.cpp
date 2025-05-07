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
    int n, k, pb, ps;
    cin >> n >> k >> pb >> ps;
    vector<int> p(n + 1), a(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> p[i];
    }
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    auto bestScore = [&] (int s) -> int {
      int u = p[s], score = a[s] * k;
      int totScore = a[s];
      int moves = 0;
      while(u != s && moves < k) {
        moves++;
        score = max(a[u] * (k - moves) + totScore, score);
        totScore += a[u];
        u = p[u];
      }
      return score;
    };
    int bs = bestScore(ps), bb = bestScore(pb);
    if(bb > bs) {
      cout << "Bodya\n";
    }
    else if(bb < bs) {
      cout << "Sasha\n";
    }
    else {
      cout << "Draw\n";
    }
  }
}


