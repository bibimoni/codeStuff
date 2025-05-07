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

const int N = (int) 1e5 + 5, INF = (int) 2e9;

struct Node {
  Node *pt[2];
  int minVal;
  Node() {
    for (int i = 0; i < 2; i++) {
      pt[i] = nullptr;
    }
    minVal = INF;
  }
};

template <int BITS>
struct Trie {
  Node *root;
  Trie() {
    root = new Node();
  }
  void insert(int x) {
    insert(root, x);
  }
  int max_xor(int x, int bound) {
    return max_xor(root, x, bound);
  }
  void insert(Node *cur, int x) {
    for(int i = BITS; i >= 0; i--) {
      int c = (x >> i) & 1;
      if(cur->pt[c] == nullptr) {
        cur->pt[c] = new Node();
      }
      cur = cur->pt[c];
      cur->minVal = min(cur->minVal, x);
    }
  }
  int max_xor(Node *cur, int x, int bound) {
    int res = 0;
    for(int i = BITS; i >= 0; i--) {
      int c = (x >> i) & 1;
      if(cur->pt[c ^ 1] != nullptr && cur->pt[c ^ 1]->minVal <= bound) {
        res += ((c ^ 1) << i);
        cur = cur->pt[c ^ 1];
      }
      else {
        if(cur->pt[c] == nullptr || cur->pt[c]->minVal > bound) {
          return -1;
        }
        cur = cur->pt[c];
        res += (c << i);
      }
    }
    return res;
  }
};

vector<int> divs[N];

Trie<19> tries[N];

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  for(int i = 1; i < N; i++) {
    for(int j = i; j < N; j += i) {
      divs[j].push_back(i);
    }
  }
  int q;
  cin >> q;
  while(q--) {
    int type;
    cin >> type;
    if(type == 1) {
      int u;
      cin >> u;
      for(int d : divs[u]) {
        tries[d].insert(u);
      }
    }
    else if(type == 2) {
      int x, k, s;
      cin >> x >> k >> s;
      if(x % k != 0) {
        cout << "-1\n";
      }
      else {
        cout << tries[k].max_xor(x, s - x) << '\n';
      }
    }
  }
}

