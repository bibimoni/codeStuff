/**
 * Author: distiled
 */
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
#define int int64_t

const int N = 1e4 + 5;
const int K = 16;

int n, k;
vector<int> a, b;

vector<int> pos[N * K];
vector<int> BIT[N * K];

void fakeAdd(int u, int v, int x) {
  for (; u <= n * k; u += u & (-u)) {
    pos[u].push_back(v);
  }
}

void fakeQuery(int u, int v) {
  for (; u > 0; u -= u & (-u)) {
    pos[u].push_back(v);
  }
}

void compress() {
  for (int i = 1; i <= n * k; i++) {
    pos[i].push_back(0);
    sort(pos[i].begin(), pos[i].end());
    pos[i].erase(unique(pos[i].begin(), pos[i].end()), pos[i].end());
    BIT[i].assign(pos[i].size(), 0);
  }
}

void upd(int u, int v, int x) {
  for (int i = u; i <= n * k; i += i & (-i)) {
    for (int j = lower_bound(pos[i].begin(), pos[i].end(), v) - pos[i].begin();
         j < (int)BIT[i].size(); j += j & (-j)) {
      BIT[i][j] = x;
    }
  }
}

int query(int u, int v) {
  int sum = 0;
  for (int i = u; i > 0; i -= i & (-i)) {
    for (int j = lower_bound(pos[i].begin(), pos[i].end(), v) - pos[i].begin();
         j > 0; j -= j & (-j)) {
      sum = max(sum, BIT[i][j]);
    }
  }
  return sum;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
  a.assign(n * k + 1, 0);
  b.assign(n * k + 1, 0);

  vector<vector<int>> lst(n + 1, vector<int>());

  for (int i = 1; i <= n * k; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n * k; i++) {
    cin >> b[i];
    lst[b[i]].push_back(i);
  }

  vector<vector<int>> dp(n * k + 5, vector<int>(k, 0));

  for (int i = 1; i <= n * k; i++) {
    for (int j = 0; j < k; j++) {
      int jb = lst[a[i]][j];
      cerr << "WOW" << endl;
      fakeAdd(i, jb, 0);
      fakeAdd(i - 1, jb - 1, 0);
    }
  }

  fakeAdd(n * k, k, 0);
  compress();

  for (int i = 1; i <= n * k; i++) {
    for (int j = 0; j < k; j++) {
      int jb = lst[a[i]][j];
      upd(i, jb, query(i - 1, jb - 1) + 1);
    }
  }

  cout << query(n * k, k) << endl;
}
