/**
 * Author: distiled
 * Time complexity: O(nm) 
 */
#include<bits/stdc++.h>
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
  string good, user;  
  getline(cin, good);
  getline(cin, user);
  int n = good.size(), m = user.size();

  // find LCS (no seperator)
  auto findLCS = [&] () -> string {
    string a = "";
    for (int i = 0; i < n; i++) {
      if (good[i] == ' ') {
        continue;
      }
      a += good[i];
    }
    string b = "";
    for (int i = 0; i < m; i++) {
      if (user[i] == ' ') {
        continue;
      }
      b += user[i];
    }
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
    for (int i = 1; i <= int(a.size()); i++) {
      for (int j = 1; j <= int(b.size()); j++) {
        if (a[i - 1] == b[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    int i = a.size(), j = b.size();
    string same = "";
    while (i > 0 && j > 0) {
      if (a[i - 1] == b[j - 1]) {
        same += a[i - 1];
        i -= 1;
        j -= 1;
      } else {
        if (dp[i - 1][j] > dp[i][j - 1]) {
          i -= 1;
        } else {
          j -= 1;
        }
      }
    }
    return same;
  };

  string same = findLCS(); //get LCS
  reverse(same.begin(), same.end());

  auto get = [&] (string &a) -> vector<int> {
    vector<int> ret(a.size());
    for(int j = 0, i = 0; i < int(a.size()); i++) {
      if (a[i] == same[j]) {
        j += 1;
        ret[i] = 1;
      }
    }
    return ret;
  };

  // mark which character is in the LCS
  vector<int> m_good = get(good);
  vector<int> m_user = get(user);

  // add " or ~ in between the words
  auto getAns = [&] (vector<int> &p, string &a, char sep) -> pair<string, vector<int>> {
    string ret = "";
    vector<int> valid;
    int st = 0;
    for (int i = 0; i < int(a.size()); i++) {
      if (a[i] == ' ') {
        ret += a[i];
        valid.push_back(0);
        continue;
      }
      if (p[i] == st) {
        ret += sep;
        valid.push_back(0);
        st ^= 1;
      } 
      if (p[i] == 1) {
        valid.push_back(1);
      } else {
        valid.push_back(0);
      }
      ret += a[i];
      if ((i + 1 == int(a.size()) && st == 1) 
        || (i < int(a.size()) - 1 && p[i + 1] == st && st == 1) 
        || (i < int(a.size()) - 1 && a[i + 1] == ' ' && st == 1)) {
        ret += sep;
        valid.push_back(0);
        st ^= 1;
      }
    }
    return {ret, valid};
  };

  //merge 2 answer together
  auto [ans1, valid1] = getAns(m_good, good, '\"');
  auto [ans2, valid2] = getAns(m_user, user, '~');
  string ans = "";
  for (int j = 0, i = 0; i < int(ans1.size()); i++) {
    if (valid1[i] == 0) {
      ans.push_back(ans1[i]);
    } else {
      while (j < int(ans2.size()) && valid2[j] == 0) {
        if (ans2[j] != ' ' || (ans.size() && ans.back() != ' ')) {
          ans.push_back(ans2[j]);
        }
        j += 1;
      }
      ans.push_back(ans1[i]);
      j += 1;
    }
    if (i == int(ans1.size()) - 1) {
      while (j < int(ans2.size())) {
        ans.push_back(ans2[j]);
        j += 1;
      }
    }
  }
  cout << ans << '\n';
}

