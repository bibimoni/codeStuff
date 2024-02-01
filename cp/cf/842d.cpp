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

const int N = (int) 3e5 + 5;

int a[N];

struct Node {
  Node *pt[2];
  int cnt = 0;
  Node() {
    for(int i = 0; i < 2; i++) {
      pt[i] = nullptr;
    }
    cnt = 0;
  }
};

template<int BITS>
struct Trie {
  Node *root;
  Trie() {
    root = new Node();
  }
  void insert(int x) {
    insert(root, x);
  }
  int query(int x) {
    return query(root, x);
  }
  void insert(Node *cur, int x) {
    for(int i = BITS; i >= 0; i--) {
      int c = (x >> i) & 1;
      if(cur->pt[c] == nullptr) {
        cur->pt[c] = new Node();
      }
      cur = cur->pt[c];
      cur->cnt++;
    }
  }
  int query(Node *cur, int x) {
    int res = 0;
    for(int i = BITS; i >= 0; i--) {
      int c = (x >> i) & 1;
      dbg(i, res);
      if(cur->pt[c] != nullptr && cur->pt[c]->cnt == (1 << i)) {
        cur = cur->pt[c ^ 1];
        res += (1ll << i);
      }
      else {
        cur = cur->pt[c];
      }
      if(cur == nullptr) {
        return res;
      }
    }
    return res;
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m; 
  cin >> n >> m;
  vector<int> a(n);
  for(int &i : a) {
    cin >> i;
  }
  Trie<19> trie;
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  for(int i : a) {
    trie.insert(i);
  }
  int currXor = 0;
  while(m--) { 
    int x;
    cin >> x;
    currXor ^= x;
    cout << trie.query(currXor) << '\n';
  }
}

