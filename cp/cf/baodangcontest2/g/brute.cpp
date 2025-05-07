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
int n; string s;
int ans = 0;
map<vector<int>, bool> f;
void Try(int i, vector<int> t) {
  if(i == n) {
    if(!t.size()) return;
    if(t.size() == 1) {
      ans++;
      return;
    }
    for(int j = 1; j < t.size(); j++) {
      bool hasC = false;
      for(int k = t[j - 1] + 1; k < t[j]; k++) {
        if(s[k] == 'c') hasC = true;
      }
      if(!hasC) return;
    }
    ans++;
    return;
  }
  Try(i + 1, t);
  t.push_back(i);
  if(s[i] == 'a') Try(i + 1, t);
}
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  cin >> n;
  cin >> s;
  Try(0, {});
  cout << ans;
}