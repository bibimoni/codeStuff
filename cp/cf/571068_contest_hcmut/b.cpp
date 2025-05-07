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

const int N = 1e5 + 5, M = 1e4 + 5;
const int MOD1 = 1e9 + 7, MOD2 = 1e9 + 3;
const int BASE1 = 31, BASE2 = 331;
int n, m;
vector<pair<int, int>> hash1;
string a[M];
int lena[M];
vector<pair<int, int>> hasha[M];
pair<int, int> pwr[N];

void toHash(string &h, vector<pair<int, int>> &ha) {
  if (ha.size() < h.size()) {
    ha.resize(h.size());
  }
  ha[0] = {0, 0};
  for (int i = 1; i < (int)h.size(); i++) {
    ha[i].first = (ha[i - 1].first * BASE1 + h[i] - 'a' + 1) % MOD1;
    ha[i].second = (ha[i - 1].second * BASE2 + h[i] - 'a' + 1) % MOD2;
  }
}

pair<int, int> getHash(int l, int r, vector<pair<int, int>> &ha) {
  return pair<int, int>{(ha[r].first - ha[l - 1].first * pwr[r - l + 1].first + MOD1 * MOD1) % MOD1,
    (ha[r].second - ha[l - 1].second * pwr[r - l + 1].second + MOD2 * MOD2) % MOD2};
}

bool cmpHash(pair<int, int> &h1, pair<int, int> &h2) {
  return h1 == h2;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  // freopen("minstr.inp", "r", stdin);
  // freopen("minstr.out", "w", stdout);
  cin >> n >> m;
  string s;
  cin >> s;
  s += s;
  s = " " + s;
  pwr[0] = {1, 1};
  for (int i = 1; i < N; i++) {
    pwr[i].first = (pwr[i - 1].first * BASE1) % MOD1;
    pwr[i].second = (pwr[i - 1].second * BASE2) % MOD2;
  }
  toHash(s, hash1);
  vector<int> lens;
  map<pair<int, int>, int> f;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    lens.push_back(a[i].size());
    lena[i] = a[i].size();
    a[i] = " " + a[i];
    toHash(a[i], hasha[i]);
  }
  auto check = [&] (int l) -> bool {
    int k = l + 1;
    dbg(l);
    if (k > n) {
      return true;
    }
    set<pair<int, int>> st;
    for (int i = 0; i < m; i++) {
      if (lena[i] < k) { 
        continue;
      }
      for (int j = 1; j + k - 1 <= lena[i]; j++) {
        st.insert(getHash(j, j + k - 1, hasha[i]));
      }
    }
    if (!st.size()) {
      return true;
    }
    vector<int> cands;
    for (int i = 1; i + k - 1 <= 2 * n; i++) {
      pair<int, int> hh = getHash(i, i + k - 1, hash1);
      if (st.find(hh) != st.end()) {
        cands.push_back(i);
      }
    }
    if (!cands.size()) {
      return true;
    }
    for (int i = 1; i <= n; i++) {
      int st = i, end = i + n - k;
      int pos = lower_bound(cands.begin(), cands.end(), st) - cands.begin();
      if (pos < cands.size() && cands[pos] <= end) {
        continue;
      }
      return true;
    }
    return false;
  };
  int lo = 0, hi = n, ret = 0;
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    if (check(mid)) {
      hi = mid - 1;
      ret = mid;
    } else {
      lo = mid + 1;
    }
  }
  cout << ret;
}
