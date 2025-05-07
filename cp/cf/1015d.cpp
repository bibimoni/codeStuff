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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, s, k;
  cin >> n >> k >> s;
  if(k * (n - 1) < s || s < k) {
    cout << "NO\n";
    return 0;
  }
  vector<int> ans;
  int left = s / (n - 1) - (s % (n - 1) == 0);
  while((k - left) > s - (n - 1) * left) {
    left--;
  }
  k -= left;
  for(int i = 0; i < left; i++) {
    ans.push_back((i % 2 == 0 ? n : 1));
  }
  s -= (n - 1) * left;
  bool ok = true;
  int curr = (left % 2 == 0 ? 1 : n);
  if(curr == n) {
    int curr = n;
    for(int i = 0; i < k - 1; i++) {
      ans.push_back((i % 2 == 0 ? --curr : ++curr));
      s--;
    }
    if(curr - s < 1 || curr - s > n)
      ok = false;
    ans.push_back(curr - s);
  }
  else {
    int curr = 1;
    for(int i = 0; i < k - 1; i++) {
      ans.push_back((i % 2 == 0 ? ++curr : --curr));
      s--;
    }
    if(curr + s < 1 || curr + s > n)
      ok = false;
    ans.push_back(curr + s);
  }
  if(!ok) {
    cout << "NO\n";
  }
  else {
    cout << "YES\n";
    for(int i : ans) {
      cout << i << ' ';
    }
  }
}

