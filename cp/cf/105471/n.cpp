/**
 * Author: distiled
 */
#include <bits/stdc++.h>
#include <string>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<string> a(5);
  for (int k = 0; k < 5; k++) {
    getline(cin, a[k]);
  }
  dbg("hi");

  auto isNum = [&](char v) -> bool {
    return ('1' <= v && v <= '9') || v == '-';
  };

  char var;
  vector<int> nums;
  auto extract = [&](string s) -> void {
    int i = 0;
    while (s[i] != ' ') {
      i += 1;
    }
    i += 1;
    var = s[i];
    dbg(var);

    while (s[i] != '(') {
      i += 1;
    }
    i += 1;

    dbg(i);
    assert(isNum(s[i]));
    int cur = 0;
    while (s[i] != ',') {
      cur = cur * 10 + (s[i] - '0');
      i += 1;
    }
    nums.push_back(cur);
    cur = 0;
    i += 1;
    dbg(s[i]);
    while (s[i] != ',' && s[i] != ')') {
      cur = cur * 10 + (s[i] - '0');
      dbg(s[i], i);
      i += 1;
    }
    dbg(cur);
    nums.push_back(cur);
    cur = 0;

    if (s[i] == ')') {
      nums.push_back(1);
    } else {
      i += 1;
      bool neg = false;
      while (s[i] != ',' && s[i] != ')') {
        if (s[i] == '-') {
          neg = true;
          i += 1;
          continue;
        }
        cur = cur * 10 + (s[i] - '0');
        i += 1;
      }
      nums.push_back(cur * (neg ? -1 : 1));
    }
  };

  char var2;
  bool b1 = false;
  bool b2 = false;
  bool b3 = false;
  int n1 = -1;
  int n2 = -1;
  int n3 = -1;
  char x1 = '@';
  char x2 = '@';
  char x3 = '@';
  auto extracts = [&](string s) -> void {
    int i = 0;
    while (s[i] != ' ') {
      i += 1;
    }
    i += 1;
    var2 = s[i];
    dbg(var2);

    while (s[i] != '(') {
      i += 1;
    }
    i += 1;

    if (isNum(s[i])) {
      bool neg = false;
      n1 = 0;
      b1 = true;
      while (s[i] != ',' && s[i] != ')') {
        if (s[i] == '-') {
          neg = true;
          i += 1;
          continue;
        }
        n1 = n1 * 10 + (s[i] - '0');
        i += 1;
      }
      dbg("Hi", neg, n1);
      n1 *= (neg ? -1 : 1);
    } else {
      x1 = s[i];
      i += 1;
    }
    i += 1;

    if (isNum(s[i])) {
      bool neg = false;
      n2 = 0;
      b2 = true;
      while (s[i] != ',' && s[i] != ')') {
        if (s[i] == '-') {
          neg = true;
          i += 1;
          continue;
        }
        n2 = n2 * 10 + (s[i] - '0');
        i += 1;
      }
      n2 *= (neg ? -1 : 1);
    } else {
      x2 = s[i];
      i += 1;
    }
    dbg(i, s[i]);
    if (s[i] == ')') {
      b3 = true;
      n3 = 1;
      return;
    }
    i += 1;

    if (isNum(s[i])) {
      n3 = 0;
      b3 = true;
      bool neg = false;
      while (s[i] != ',' && s[i] != ')') {
        if (s[i] == '-') {
          neg = true;
          i += 1;
          continue;
        }
        n3 = n3 * 10 + (s[i] - '0');
        i += 1;
      }
      n3 *= (neg ? -1 : 1);
      i += 1;
    } else {
      x3 = s[i];
      i += 1;
    }
  };

  extract(a[1]);
  extracts(a[2]);
  dbg(nums, var);
  dbg(n1, n2, n3, x1, x2, x3);
  int varans = '@';
  int ttt = 0;
  while (a[3][ttt] != '=') {
    ttt += 1;
  }
  ttt += 1;
  dbg(ttt);
  varans = a[3][ttt];

  int ans = 0;
  if (nums[2] < 0) {
    nums[1] += 1;
  } else {
    nums[1] -= 1;
  }
  dbg("hi");
  for (int x = nums[0]; nums[0] <= nums[1] ? x <= nums[1] : x >= nums[1];
       x += nums[2]) {
    vector<int> nnn(3);
    if (b1) {
      nnn[0] = n1;
    } else {
      nnn[0] = x;
    }

    if (b2) {
      nnn[1] = n2;
    } else {
      nnn[1] = x;
    }

    if (b3) {
      nnn[2] = n3;
    } else {
      nnn[2] = x;
    }
    dbg(nnn);
    if (nnn[2] < 0) {
      nnn[1] += 1;
    } else {
      nnn[1] -= 1;
    }

    int aa = nnn[0];
    int bb = nnn[1];
    int cc = nnn[2];
    if (cc > 0 && aa <= bb) {
      int step = (bb - aa) / cc;
      if (varans == var) {
        ans += (step + 1) * x;
      } else {
        ans += (step + 1) * aa + cc * ((step + 1) * step / 2);
      }
    }
    if (cc < 0 && bb <= aa) {
      int step = (bb - aa) / cc;
      if (varans == var) {
        ans += (step + 1) * x;
      } else {
        ans += (step + 1) * aa + cc * ((step + 1) * step / 2);
      }
    }
  }
  cout << ans << '\n';
}
