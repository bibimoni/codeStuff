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
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    bool ok = true;
    {
      int cnt = 0;
      for(char i : s) {
        if((int) i - 'a' < k) {
          cnt++;
        }
      }
      if(cnt == 0) {
        cout << "NO\n";
        cout << string(n, 'a') << '\n';
        ok = false;
      }
    }
    if(!ok) {
      continue;
    }
    int groups = 0;
    map<char, int> f;
    vector<char> last;
    for(char i : s) {
      f[i]++;
      if(f.size() == k) {
        last.push_back(i);
        groups++;
        f.clear();
      }
    }
    if(groups >= n) {
      cout << "YES\n";
      continue;
    }
    cout << "NO\n";
    if(!f.size()) {
      for(char i : last) {
        cout << i;
      }
      for(int i = last.size() + 1; i <= n; i++) {
        cout << s[m - 1];
      }
      cout << '\n';
      continue;
    }
    char tmp;
    vector<bool> has(26);
    for(auto [c, _] : f) {
      has[c - 'a'] = true;
    }
    for(int i = 0; i < k; i++) {
      if(!has[i]) {
        tmp = (char) i + 'a';
      }
    }
    for(char i : last) {
      cout << i;
    }
    for(int i = last.size() + 1; i <= n; i++) {
      cout << tmp;
    }
    cout << '\n';
  }
}


