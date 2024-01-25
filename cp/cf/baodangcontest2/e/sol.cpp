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
  int n; cin >> n;
  string s; cin >> s;
  map<char, vector<int>> f;
  for(int i = 0; i < n; i++) {
    int cnt = 0, j = i;
    while(s[j] == s[i]) j++;
    f[s[i]].push_back(j - i);
    i = j - 1;
  }
  int maxlen = 0;
  for(char c = 'A'; c <= 'Z'; c++) {
    vector<int> tmp = f[c];
    if(!tmp.size()) continue;
    sort(tmp.begin(), tmp.end());
    int last = tmp[tmp.size() - 1];
    maxlen = max(last - 1, maxlen);
    if(tmp.size() > 1) {
      int prev = tmp[tmp.size() - 2];
      if(prev == last) maxlen = max(last, maxlen);
    }
  }      
  if(maxlen > 0) cout << maxlen;
  else cout << "-1";
}

