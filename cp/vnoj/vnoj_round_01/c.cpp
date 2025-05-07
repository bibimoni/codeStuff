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
int start = 7937;
// Get primes not greater than n in O(nloglogn)
vector<bool> is((int) 1e7 + 5, 1);
vector<int> getprimes(int n) {
  vector<int> p;
  for (int i = 2; i <= n; i++) {
    if (is[i]) {
      p.push_back(i);
      for (int j = 2 * i; j <= n; j += i) is[j] = 0;
    }
  }
  return p;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  vector<int> primes = getprimes((int) 1e7);
  int best = 0, maxlen = 0;;
  //for(; start < 10000; start++) {
    //if(!is[start]) {
      //continue;
    //}
    //dbg(start);
    int gap = 2;
    int currSum = 0, prev = start;
    vector<int> ans;
    int mark = 1, cnt = 1;
    for(int i : primes) {
      if(i < start) {
        continue;
      }
      if((i - prev) % gap == 0) {
        ans.push_back(i);
        prev = i;
        currSum += i;
        if(currSum % (int) ans.size() == 0 && is[currSum / (int) ans.size()]) {
          mark = cnt;
          //dbg(currSum, mark)
        }
      }
      cnt++;
    }
    //dbg(mark);
    //dbg(accumulate(ans.begin(), ans.begin() + mark - 1, 0ll), mark);
    cout << mark << '\n';
    // if(mark > maxlen) {
      // maxlen = mark;
      // best = start;
    // }
    // int tmp = 0; cnt = 0;
    for(int i = 0; i < mark; i++) {
      // tmp += ans[i];
      // cnt++;
      cout << ans[i] << " ";
    }
    //dbg(tmp, cnt);
  //}
  //dbg(best, maxlen);
}


