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
  freopen("CAU5.INP", "r", stdin);
  freopen("CAU5.OUT", "w", stdout);
  int n;
  cin >> n;
  int s[n];
  for(int &i : s) {
    cin >> i;
  }
  int ans[] = {0, 0, 0};
  sort(s, s + n);
  int totalTriangle = 0;
  for(int a = 2; a < n; a++) {
    for(int b = 1; b < a; b++) {
      int bound = b, l = 0, r = b - 1;
      //find the boundary of forming a triangle
      //c + b > a
      while(l <= r) {
        int c = (l + r) >> 1;
        if(s[c] + s[b] > s[a]) {
          r = c - 1;
          bound = c;
        }
        else {
          l = c + 1;
        }
      }
      totalTriangle += b - bound;
      if(bound == b) {
        continue;
      }
      //count number of acute triangle
      //c^2 + b^2 > a^2
      l = bound, r = b - 1; 
      int ret = b;
      while(l <= r) {
        int c = (l + r) >> 1;
        if(s[c] * s[c] + s[b] * s[b] > s[a] * s[a]) {
          r = c - 1;
          ret = c;
        }
        else {
          l = c + 1;
        }
      }
      ans[0] += b - ret;
      //count number of obtuse triangle
      //c^2 + b ^ 2 < a ^ 2
      l = bound, r = b - 1, ret = bound - 1;
      while(l <= r) {
        int c = (l + r) >> 1;
        if(s[c] * s[c] + s[b] * s[b] < s[a] * s[a]) {
          l = c + 1;
          ret = c;
        }
        else {
          r = c - 1;
        }
      } 
      ans[2] += ret - bound + 1;
    }
  }
  //count the number of right triangle
  ans[1] = totalTriangle - ans[0] - ans[2];
  for(int i : ans) {
    cout << i << ' ';
  }
}

