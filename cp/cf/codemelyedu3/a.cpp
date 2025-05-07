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

int dest;
vector<int> ans;
void Try(int curr, vector<int> steps) {
  if(curr > dest || ans.size()) return;
  if(curr == dest) {
    ans = steps;
    return;
  }
  vector<int> tmp = steps; tmp.push_back(curr * 2);
  Try(curr * 2, tmp);
  tmp = steps; tmp.push_back(curr * 10 + 1);
  Try(curr * 10 + 1, tmp);
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int start; cin >> start >> dest;
  Try(start, {start});
  if(ans.size()) {
    cout << "YES\n" << ans.size() << '\n';
    for(int i : ans) cout << i << ' ';
  }
  else {
    cout << "NO\n";
  }
}

