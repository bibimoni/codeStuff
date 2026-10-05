/**
 * Author: distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#define table(...)
#endif
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n = 16;
  map<string, vector<string>> mp;
  vector<string> s(n);
  map<string, int> id;
  for (int i = 0; i < n; i++) {
    string name;
    cin >> name >> s[i];
    mp[s[i]].push_back(name);
  }

  vector<int> cnt(n);
  int idx = 0;
  for (string t : s) {
    int win = true;
    int beat = 0;
    table(s[idx]);
    for (int i = 0; i < int(t.size()); i++) {
      char c = t[i];
      int cur = 16 - beat;
      if (win) {
        if (c == '1') {
          beat += cur / 2;
          cur /= 2;
        } else {
          if (t[i + 1] == '0') {
            if (beat > 0)
              beat -= cur / 2;
            break;
          }
          cur /= 2;
          i += 1;
          win = false;
        }
      } else {
        if (c == '0') {
          break; 
        } else if (t[i + 1] == '1') {
          beat += cur / 2;
          cur /= 2;
          i += 1;
        } else {
          break;
        }
      }
      dbg(i,beat, cur, win);
    }
    cnt[idx] = beat;
    idx += 1;
  }

  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](int i, int j) {
    return cnt[i] > cnt[j];
  });

  table(cnt);
  vector<string> cur;
  for (int i = 0; i < n; i++) {
    // dbg(cnt[p[i]]);
    cur.push_back(mp[s[p[i]]].back());
    mp[s[p[i]]].pop_back();
    sort(cur.begin(), cur.end());
    if (i < 4) {
      for (string str : cur) {
        cout << i + 1 << " " << str << "\n";
      }
      cur.clear();
    } else if (i < 6) {
      if (i == 5) {
        for (string str : cur) {
          cout << "5-6 "<< str << "\n";
        }
        cur.clear();
      }
    } else if (i < 8) {
      if (i == 7) {
        for (string str : cur) {
          cout <<  "7-8 " << str << "\n";
        }
        cur.clear();
      }
      // cout << "7-8 ";
    } else if (i < 12) {
      if (i == 11) {
        for (string str : cur) {
          cout << "9-12 " << str << "\n";
        }
        cur.clear();
      }
      // cout << "9-12 ";
    } else {
      if (i == 15) {
        for (string str : cur) {
          cout << "13-16 " << str << "\n";
        }
        cur.clear();
      }
    }
  }

}
