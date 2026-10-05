#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick() {}
    Fenwick(int n_) { init(n_); }
    void init(int n_) { n = n_; bit.assign(n + 1, 0); }
    void add(int i, int d) { for (; i <= n; i += i & -i) bit[i] += d; }
    int sum(int i) const { int s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; }
    int rangeSum(int l, int r) const { if (l > r) return 0; return sum(r) - sum(l - 1); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, q;
        cin >> n >> q;
        Fenwick fw(n + q + 5);
        unordered_map<int, pair<int,int>> mp; // key -> (value, ts)
        mp.reserve(n + q * 2);
        set<pair<int,int>> byTs; // (ts, key)
        int cur = 0;
        for (int k = 1; k <= n; k++) {
            ++cur;
            mp[k] = {0, cur};
            byTs.insert({cur, k});
            fw.add(cur, 1);
        }
        for (int i = 0; i < q; i++) {
            int ty;
            cin >> ty;
            if (ty == 1) {
                int a, b;
                cin >> a >> b;
                auto it = mp.find(a);
                if (it != mp.end()) {
                    int ots = it->second.second;
                    byTs.erase({ots, a});
                    fw.add(ots, -1);
                    ++cur;
                    it->second = {b, cur};
                    byTs.insert({cur, a});
                    fw.add(cur, 1);
                } else {
                    // evict LRU
                    auto lit = byTs.begin();
                    int lru = lit->second, lts = lit->first;
                    byTs.erase(lit);
                    fw.add(lts, -1);
                    mp.erase(lru);
                    ++cur;
                    mp[a] = {b, cur};
                    byTs.insert({cur, a});
                    fw.add(cur, 1);
                }
            } else {
                int a;
                cin >> a;
                auto it = mp.find(a);
                if (it == mp.end()) {
                    cout << -1 << "\n";
                } else {
                    int v = it->second.first, ts = it->second.second;
                    int r = 1 + fw.rangeSum(ts + 1, cur);
                    cout << v << ' ' << r << "\n";
                    byTs.erase({ts, a});
                    fw.add(ts, -1);
                    ++cur;
                    it->second.second = cur;
                    byTs.insert({cur, a});
                    fw.add(cur, 1);
                }
            }
        }
    }
    return 0;
}
