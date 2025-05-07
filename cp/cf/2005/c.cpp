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
#define int int64_t 

struct Node {
  int cnt, exist;
  Node *pt[26];
  Node() {
    for (int i = 0; i < 26; i++) {
      pt[i] = nullptr;
    }
    cnt = exist = 0;
  }
};

struct Trie {
  Node *root;
  Trie() {
    root = new Node();
  }
  void insert(string &s) {
    insert(root, s, 0);
  }
  void erase(string &s) {
    // make sure 's' was inserted in Trie before deletion
    erase(root, s, 0);
  }
  void find(string &s) {
    find(root, s, 0);
  }
  void insert(Node *cur, string &s, int idx) {
    for(char i : s) {
      int c = i - 'a';
      if(cur->pt[c] == nullptr)
        cur->pt[c] = new Node();
      cur = cur->pt[c];
      cur->cnt++;
    }
    cur->exist++;
  }
  void erase(Node *cur, string &s, int idx) {
    if (idx == sz(s)) return;
    int c = s[idx] - 'a';
    if(cur != root) {
      cur->cnt--;
      if(idx == sz(s) - 1)
        cur->exist--;
    }
    erase(cur->pt[c], s, idx + (cur != cur));
  }
  bool find(Node *cur, string &s, int idx) {
    if (idx == sz(s)) 
      return true;
    int c = s[idx] - 'a';
    int f = cur->cnt;
    if (f > 0) 
      return find(cur->pt[c], s, idx + (cur != root));
    else 
      return false;
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    auto is_narek = [&] (char c) -> bool {
      return c == 'n' || c == 'a' || c == 'r' || c == 'e' || c == 'k';
    };
    
    string bruh = "narek";
    map<char, int> index;

    const int INF = 1e9;
    vector<int> dp(5, -INF);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
      vector<int> ndp(5, -INF);
      for (int j = 0; j < 5; j++) {
        int ret = dp[j];
        int x = j;
        for (char c : a[i]) {
          if (c == bruh[x]) {
            if (x == 4) {
              ret += 5;
              x = 0;
            } else {
              x += 1;
            }
          } else if(is_narek(c)) {
            ret -= 1;
          }
        }
        ndp[x] = max(ndp[x], ret);
      }
      for (int j = 0; j < 5; j++) {
        ndp[j] = max(ndp[j], dp[j]);
      }
      swap(dp, ndp);
    }

    int ans = 0;
    for (int i = 0; i < 5; i++) {
      ans = max(ans, dp[i] - i);
    }
    cout << ans << '\n';
  }
}


