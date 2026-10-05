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
  Trie() { root = new Node(); }
  void insert(string &s) { insert(root, s, 0); }
  void erase(string &s) {
    // make sure 's' was inserted in Trie before deletion
    erase(root, s, 0);
  }
  void find(string &s) { find(root, s, 0); }
  void insert(Node *cur, string &s, int idx) {
    for (char i : s) {
      int c = i - 'a';
      if (cur->pt[c] == nullptr)
        cur->pt[c] = new Node();
      cur = cur->pt[c];
      cur->cnt++;
    }
    cur->exist++;
  }
  void erase(Node *cur, string &s, int idx) {
    if (idx == sz(s))
      return;
    int c = s[idx] - 'a';
    if (cur != root) {
      cur->cnt--;
      if (idx == sz(s) - 1)
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
