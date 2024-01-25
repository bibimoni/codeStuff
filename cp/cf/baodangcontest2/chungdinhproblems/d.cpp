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
  //k = 3
  //1 2 3 4
  //3 2 1 4
  //3
  //2 1 4
  //4 1 2
  //4
  int k, q; cin >> k >> q;
  deque<int> dq, dq1;
  int state = 0;
  while(q--) {
    int type; cin >> type;
    if(type == 1) {
      int x; cin >> x; 
      if(dq1.size() < k) {
        if(!state) {
          dq1.push_back(x);
        }
        else {
          dq1.push_front(x);
        }
      }
      else {
        dq.push_back(x);
      }
    }
    if(type == 2) {
      if(!dq1.size()) {
        cout << "-1\n";
        continue;
      }
      if(!state) {
        cout << dq1.front() << '\n';
        dq1.pop_front();
        if(dq.size()) {
          dq1.push_back(dq.front());
          dq.pop_front();
        } 
      }
      else {
        cout << dq1.back() << '\n';
        dq1.pop_back();
        if(dq.size()) {
          dq1.push_front(dq.front());
          dq.pop_front();
        }
      }
    }
    if(type == 3) {
      if(dq1.size() == k) {
        state ^= 1;
      }
    }
    dbg(state, type, dq, dq1);
  }
}

