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

vector<string> ans;

void gen(string t, int n) {
  for(int i = 0; i <= (n - 3) / 2; i++) {
    dbg(i);
    string m = "";
    m += t[0];
    int rem = n - 3 - 2 * i;
    for(int j = 1; j <= i; j++) m += "0";
    m += t[1];
    for(int j = 1; j <= i; j++) m += "0";
    m += t[2];
    for(int j = 1; j <= rem; j++) m += "0";
    ans.push_back(m);
  }
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    ans.clear();
    if(n == 1) {
      cout << "1\n";
    }
    if(n == 3) {
      cout << "169\n196\n961";
    }
    else {
      gen("169", n);
      gen("961", n);
      string m = "";
      m += "61009";
      for(int i = 1; i <= n - 5; i ++) m += "0";
      ans.push_back(m);
      for(int i = 0; i < n; i++) cout << ans[i] << '\n';
    }
    // multiset<vector<int>> s;
    // vector<int> squares;
    // map<vector<int>, vector<int>> f;
    // for(int i = 100000; i < 316222; i++) {
    //   squares.push_back(i * i);
    //   vector<int> num;
    //   int tmp = i * i;
    //   while(tmp) {
    //     num.push_back(tmp % 10);
    //     tmp /= 10;
    //   }
    //   sort(num.begin(), num.end());
    //   s.insert(num);
    //   f[num].push_back(i * i);
    // }
    // dbg(f[{0, 0, 0, 0, 0, 0, 0, 0, 1, 6, 9}]);
    // dbg(f);
  }
}


