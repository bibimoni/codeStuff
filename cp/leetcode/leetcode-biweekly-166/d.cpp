#include <bits/stdc++.h>
using namespace std;

class Dsu {
  vector<int> parent, siz;
  int count_cp;

public:
  vector<vector<int>> e;
  Dsu() {}

  Dsu(int n) {
    count_cp = n - 1; // Dsu uf(n + 1) so we need to subtract 1
    parent.resize(n);
    e.resize(n);
    for (int i = 0; i < n; i++) {
      e[i].push_back(i);
    }
    siz.assign(n, 1);
    iota(parent.begin(), parent.end(), 0ll);
  }

  int find(int v) {
    if (v == parent[v]) {
      return v;
    }
    return parent[v] = find(parent[v]);
  }

  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      if (siz[a] < siz[b]) {
        swap(a, b);
      }
      for (int x : e[b]) {
        e[a].push_back(x);
      }
      parent[b] = a;
      siz[a] += siz[b];
      count_cp -= 1;
      return true;
    } else {
      return false;
    }
  }

  int size(int u) { return siz[find(u)]; }

  int size() { return count_cp; }

  bool same(int u, int v) { return find(u) == find(v); }
};

class Solution {
public:
  long long maxAlternatingSum(vector<int> &nums, vector<vector<int>> &swaps) {
    int n = int(nums.size());
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      a[i] = nums[i - 1];
    }

    Dsu dsu(n + 1);
    for (auto p : swaps) {
      dsu.unite(p[0] + 1, p[1] + 1);
    }

    long long ans = 0;
    for (int u = 1; u <= n; u++) {
      if (dsu.find(u) != u) {
        continue;
      }

      vector<int> elem;
      int co = 0;
      for (int x : dsu.e[u]) {
        co += int(x % 2 != 0);
        elem.push_back(a[x]);
      }
      sort(elem.begin(), elem.end(), greater<>());
      int id = 0;
      while (co--) {
        ans += elem[id];
        id += 1;
      }
      while (id < (int)elem.size()) {
        ans -= elem[id];
        id += 1;
      }
    }

    return ans;
  }
};
