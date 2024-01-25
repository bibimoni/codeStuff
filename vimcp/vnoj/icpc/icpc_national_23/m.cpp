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
#define all(x)         x.begin(), x.end()
int n;
int ask(int id) {
  cout << "? ";
  string s = "";
  for(int i = 0; i < id; i++) s += "1";
  for(int i = id; i < n; i++) s += "0";
  cout << s << '\n';
  cout.flush();
  int in; cin >> in;
  return in;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  cin >> n;
  //less : 1, more : 0
  int mid, l = 0, r = n;
  int askR = ask(r), askL = ask(l);
  while(l + 1 < r) {
    mid = (l + r) >> 1;
    int askMid = ask(mid);
    if(askMid == askR) {
      r = mid;
    }
    else {
      l = mid;
    }
    //dbg(l, r, mid, askMid, askR, askL);
  }  
  mid = (askL ? l : r);
  string sensitive = "";
  for(int i = 0; i < mid; i++) {
    sensitive += "1";
  }
  for(int i = mid; i < n; i++){
    sensitive += "0";
  }
  string ans = "";
  for(int i = 0; i < n; i++) {
    string t = sensitive;
    t[i] = !(sensitive[i] - '0') + '0';
    cout << "? " << t << '\n';
    cout.flush();
    int in; cin >> in;
    if(in) {
      ans += sensitive[i];
    }
    else {
      ans += t[i];
    }
  }
  cout << "! " << ans;
}



