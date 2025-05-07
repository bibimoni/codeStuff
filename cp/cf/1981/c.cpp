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
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int st = -1;
    for(int i = 0; i < n; i++) {
      if(a[i] != -1) {
        st = i;
        for(int j = i - 1; j >= 0; j--) {
          a[j] = a[j + 1] * 2;
        }
        break;
      }
    }
    int en = -1;
    for(int i = n - 1; i >= 0; i--) {
      if(a[i] != -1) {
        en = i;
        for(int j = i + 1; j < n; j++) {
          a[j] = a[j - 1] * 2;
        }
        break;
      }
    }
    if(st == -1) {
      int curr = 1;
      while(n--) {
        cout << curr << " \n"[n == 0];
        curr *= 2;
      }
      continue;
    }
    for(int i = 0; i < n; i++) {
      if(a[i] == -1)
        continue;
      if(i <= st || i > en)
        continue;
      if(a[st] > a[i]) {
        int mark = -1;
        for(int j = st + 1; j < i; j++) {
          if(a[j - 1] == 1) {
            mark = j - 1;
            break;
          }
          a[j] = a[j - 1] / 2;
          if(a[j] * 2 == a[i]) {
            mark = j;
            break;
          }
        }
        if(mark == -1) {
          st = i;
          continue;
        }
        int cnt = 0;
        for(int j = mark + 1; j < i; j++) {
          if(cnt & 1)
            a[j] = a[j - 1] / 2;
          else  
            a[j] = a[j - 1] * 2;
          cnt++;
        }
      }
      else {
        int mark = -1;
        for(int j = i - 1; j > st; j--) {
          if(a[j + 1] == 1) {
            mark = j + 1;
            break;
          }
          a[j] = a[j + 1] / 2;
          if(a[j] * 2 == a[st]) {
            mark = j;
            break;
          }
        }
        if(mark == -1) {
          st = i;
          continue;
        }
        int cnt = 0;
        for(int j = mark - 1; j > st; j--) {
          if(cnt & 1)
            a[j] = a[j + 1] / 2;
          else
            a[j] = a[j + 1] * 2;
          cnt++;
        }
      }
      st = i;
    }
    bool ok = true;
    for(int i = 0; i < n - 1; i++) {
      if(a[i] / 2 != a[i + 1] && a[i + 1] / 2 != a[i])
        ok = false;
    }
    if(!ok) {
      cout << "-1\n";
    }
    else {
      for(int i : a) {
        cout << i << ' ';
      }
      cout << '\n';
    }
  }
}


