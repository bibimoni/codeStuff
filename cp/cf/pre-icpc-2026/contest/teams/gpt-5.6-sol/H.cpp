#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    vector<int> f;
    Fenwick(int n) : f(n + 1) {}
    void add(int i, int v) { for (; i < (int)f.size(); i += i & -i) f[i] += v; }
    int sum(int i) const { int s = 0; for (; i; i -= i & -i) s += f[i]; return s; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        Fenwick bit(n + q + 2);
        unordered_map<long long, pair<long long, int>> cache;
        cache.reserve((n + q) * 2);
        set<pair<int, long long>> order;
        for (int key = 1; key <= n; ++key) {
            cache[key] = {0, key};
            order.insert({key, key});
            bit.add(key, 1);
        }
        int timer = n;
        auto touch = [&](long long key) {
            int old = cache[key].second;
            bit.add(old, -1);
            order.erase({old, key});
            cache[key].second = ++timer;
            bit.add(timer, 1);
            order.insert({timer, key});
        };
        while (q--) {
            int type;
            long long a;
            cin >> type >> a;
            if (type == 1) {
                long long b;
                cin >> b;
                if (!cache.count(a)) {
                    auto [ts, key] = *order.begin();
                    order.erase(order.begin());
                    bit.add(ts, -1);
                    cache.erase(key);
                    cache[a] = {b, ++timer};
                    order.insert({timer, a});
                    bit.add(timer, 1);
                } else {
                    cache[a].first = b;
                    touch(a);
                }
            } else if (!cache.count(a)) {
                cout << -1 << '\n';
            } else {
                int ts = cache[a].second;
                cout << cache[a].first << ' ' << n - bit.sum(ts) + 1 << '\n';
                touch(a);
            }
        }
    }
}
