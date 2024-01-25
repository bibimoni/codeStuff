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
  int n; cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int days = 0;
  vector<int> events;
  map<int, bool> f;
  bool valid = true;
  int currSum = 0;
  for(int i = 0; i < n; i++) {
    //enter twice
    if(a[i] > 0 && f[a[i]]) {
      if(currSum) {
        valid = false;
        break;
      }
      f.clear();
      events.push_back(days);
      days = 0;
    }
    //haven't enter yet
    else if(a[i] < 0 && !f[-a[i]]) {
      valid = false;
      break;
    }
    if(a[i] > 0) {
      f[a[i]] = true;
    }
    days++;
    currSum += a[i];
  }
  if(days) {
    if(currSum) {
      valid = false;
    }
    else {
      events.push_back(days);
    }
  }
  if(valid) {
    cout << events.size() << '\n';
    for(int i : events) {
      cout << i << ' ';
    }
    cout << '\n';
  }
  else {
    cout << "-1\n";
  }
}

