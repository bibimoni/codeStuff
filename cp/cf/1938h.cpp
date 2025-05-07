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

const int INF = (int) 2e9;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> a(n);
  int total = 0, total1 = 0;;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    total += a[i].size();
  }
  auto get = [&] (string &s, int type) -> int {
    int ret = 0;
    for(char c : s) {
      ret += ((c - '0') == type);
    } 
    return ret;
  };
  bool oneType = true;
  vector<array<int, 3>> save(n);
  for(int i = 0; i < n; i++) {
    if(get(a[i], 1) != a[i].size() && get(a[i], 1) != 0) {
      oneType = false;
    }
    total1 += get(a[i], 1);
    if(a[i].size() > 2 * get(a[i], 1)) {
      //0 > 1
      save[i] = {0, get(a[i], 0), i};
    }
    else {
      save[i] = {1, get(a[i], 1), i};
    }
  }
  if(oneType) {
    cout << 0;
    return 0;
  }
  int total0 = total - total1;
  // dbg(save);
  sort(save.begin(), save.end(), [&] (array<int, 3> i, array<int, 3> j) {
    if(i[0] != j[0]) {
      return i[0] < j[0];
    }
    else {
      return i[1] < j[1];
    }
  });
  int ans = INF;
  if(save[0][0] == save[n - 1][0]) {
    //move 0
    for(int i = 0; i < n; i++) {
      ans = min(ans, total0 - get(a[i], 0) + get(a[i], 1));
    }
    //move1
    for(int i = 0; i < n; i++) {
      ans = min(ans, total1 + get(a[i], 0) - get(a[i], 1));      
    }
  }
  else {
    int tmp = 0;
    for(int i = 0; i < n; i++) {
      tmp += a[save[i][2]].size() - save[i][1];
    }
    ans = min(ans, tmp);
  }
  cout << ans;
}

