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
    int n;
    string s;
    cin >> n;
    cin >> s;
    //{a, 3} {c, 1} {x} {c, 2} {x} {c, 4} {a, 2} {x} {c, 4}
    //a4bc1a2bc3
    s = "#" + s;
    int cntC = 0, cntA = 0;
    int lastB = -1, firstB = -1;
    vector<int> cntsA(n + 1, 0), cntsC(n + 1, 0);
    for(int i = 1; i <= n; i++) {
      cntsA[i] = cntsA[i - 1] + (s[i] == 'a');
      cntsC[i] = cntsC[i - 1] + (s[i] == 'c');
    }
    for(int i = 1; i <= n; i++) {
      if(s[i] == 'b' && (i == 1 || s[i - 1] != 'b'))
        lastB = i;
    }
    for(int i = n; i >= 1; i--) {
      if(s[i] == 'b' && (i == n || s[i + 1] != 'b'))
        firstB = i;
    }
    vector<int> valid(n + 1, 0);
    int curr = -1;
    for(int i = 1; i <= n; i++) {
      if(s[i] == 'b')
        curr = i;
      else if(s[i] == 'c' && curr != -1)
        valid[i] = (cntsA[curr - 1] > 0);
    }
    curr = -1;
    for(int i = n; i >= 1; i--) {
      if(s[i] == 'b')
        curr = i;
      else if(s[i] == 'a' && curr != -1) 
        valid[i] = (cntsC[n] - cntsC[curr] > 0);
    }
    if(lastB == -1 || firstB == -1) {
      cout << "0\n";
      continue;
    }
    for(int i = 1; i < lastB; i++) {
      cntA += (s[i] == 'a') * valid[i];
    }
    for(int i = n; i > firstB; i--) {
      cntC += (s[i] == 'c') * valid[i];
    }
    cout << min(cntA, cntC) << '\n';
  }
}


