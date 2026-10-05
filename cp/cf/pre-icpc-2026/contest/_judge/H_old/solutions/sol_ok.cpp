// OK: independent correct implementation, policy-based ordered set for both
// order statistics and eviction. O((n+q) log(n+q)) per test case.
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using OST = tree<pair<int, int>, null_type, less<pair<int, int>>,
                 rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        unordered_map<int, pair<long long, int>> mp;   // key -> {value, ts}
        mp.reserve(2 * (n + q) + 10);
        OST ost;                                        // (ts, key)
        int timer = 0;
        for (int k = 1; k <= n; k++) { mp[k] = {0LL, ++timer}; ost.insert({timer, k}); }
        const int sz = n;
        while (q--) {
            int type; long long a; cin >> type >> a;
            if (type == 1) {
                long long b; cin >> b;
                auto it = mp.find((int)a);
                if (it != mp.end()) {
                    ost.erase({it->second.second, (int)a});
                    it->second = {b, ++timer};
                } else {
                    auto lru = *ost.begin();
                    ost.erase(lru);
                    mp.erase(lru.second);
                    mp[(int)a] = {b, ++timer};
                }
                ost.insert({timer, (int)a});
            } else {
                auto it = mp.find((int)a);
                if (it == mp.end()) { cout << -1 << '\n'; continue; }
                long long val = it->second.first;
                int ts = it->second.second;
                int le = (int)ost.order_of_key({ts, INT_MAX});  // active ts <= ts
                cout << val << ' ' << sz - le + 1 << '\n';
                ost.erase({ts, (int)a});
                it->second = {val, ++timer};
                ost.insert({timer, (int)a});
            }
        }
    }
    return 0;
}
