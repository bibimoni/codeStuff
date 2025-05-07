struct Node {
  int cnt[2];
  Node *pt[2];
  Node() {
    for (int i = 0; i < 2; i++) {
      cnt[i] = 0;
      pt[i] = nullptr;
    }
  }
};

template <int BITS> struct Trie {
  Node *root;
  Trie() { root = new Node(); }
  void insert(int x) { insert(root, x, BITS - 1); }
  void erase(int x) { erase(root, x, BITS - 1); }
  int max_xor(int x) { return max_xor(root, x, BITS - 1); }
  bool insert(Node *cur, int x, int b) {
    if (b == -1)
      return true;
    bool c = (x & (1LL << b)) ? 1 : 0;
    if (cur->pt[c] == nullptr) {
      cur->pt[c] = new Node();
    }
    cur->cnt[c]++;
    return insert(cur->pt[c], x, b - 1);
  }
  void erase(Node *cur, int x, int b) {
    if (b == -1) {
      return;
    }
    bool c = (x & (1LL << b)) ? 1 : 0;
    cur->cnt[c]--;
    erase(cur->pt[c], x, b - 1);
  }
  int max_xor(Node *cur, int x, int b) {
    if (b == -1) {
      return 0;
    }
    bool c = (x & (1LL << b)) ? 1 : 0;
    c ^= 1;
    if (cur->cnt[c]) {
      return (1LL << b) + max_xor(cur->pt[c], x, b - 1);
    } else {
      return max_xor(cur->pt[c ^ 1], x, b - 1);
    }
  }
};
