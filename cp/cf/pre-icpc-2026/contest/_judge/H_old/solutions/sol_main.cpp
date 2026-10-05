// MA: O((n+q) log(n+q)) per test case.
// Per key: value + timestamp of last touch. Fenwick over active timestamps gives
// the recency order; std::set gives the LRU key for eviction.
#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n; vector<int> f;
    explicit Fenwick(int n) : n(n), f(n + 1, 0) {}
    void add(int i, int d) { for (; i <= n; i += i & -i) f[i] += d; }
    int sum(int i) const { int s = 0; for (; i > 0; i -= i & -i) s += f[i]; return s; }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        unordered_map<int, pair<long long, int>> mp;   // key -> {value, ts}
        mp.reserve(2 * (n + q) + 10);
        set<pair<int, int>> ord;                        // (ts, key), min = LRU
        Fenwick fw(n + q);
        int timer = 0;
        for (int k = 1; k <= n; k++) {
            mp[k] = {0LL, ++timer};
            ord.insert({timer, k});
            fw.add(timer, 1);
        }
        const int sz = n;                               // cache is always full
        string out;
        while (q--) {
            int type; long long a; cin >> type >> a;
            if (type == 1) {
                long long b; cin >> b;
                auto it = mp.find((int)a);
                if (it != mp.end()) {
                    fw.add(it->second.second, -1);
                    ord.erase({it->second.second, (int)a});
                    it->second = {b, ++timer};
                } else {
                    auto lru = ord.begin();
                    fw.add(lru->first, -1);
                    mp.erase(lru->second);
                    ord.erase(lru);
                    mp[(int)a] = {b, ++timer};
                }
                ord.insert({timer, (int)a});
                fw.add(timer, 1);
            } else {
                auto it = mp.find((int)a);
                if (it == mp.end()) { out += "-1\n"; continue; }
                long long val = it->second.first;
                int ts = it->second.second;
                int rank = sz - fw.sum(ts) + 1;         // order 1 = most recently used
                out += to_string(val); out += ' ';
                out += to_string(rank); out += '\n';
                fw.add(ts, -1);                          // refresh: becomes MRU
                ord.erase({ts, (int)a});
                it->second = {val, ++timer};
                ord.insert({timer, (int)a});
                fw.add(timer, 1);
            }
        }
        cout << out;
    }
    return 0;
}
