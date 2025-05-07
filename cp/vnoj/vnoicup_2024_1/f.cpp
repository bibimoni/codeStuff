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

void Try(int i, int n, string curr, map<string, int> &f, string &s) {
  if(i == n) {
    if(curr == "")
      return;
    f[curr]++;
    return;
  }
  Try(i + 1, n, curr, f, s);
  curr.push_back(s[i]);
  Try(i + 1, n, curr, f, s);
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  int k;
  cin >> k;
  while(tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<string, int> f;
    Try(0, n, "", f, s);
    int ans = 0;
    for(auto [_, v] : f) {
      if(k == v) {
        ans++;
      }
    }
    cout << ans << '\n';
  }
}

