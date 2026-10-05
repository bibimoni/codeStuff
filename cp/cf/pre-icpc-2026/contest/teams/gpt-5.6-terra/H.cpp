#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using Tree = tree<pair<long long, long long>, null_type, less<pair<long long, long long>>,
                  rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        Tree order;
        unordered_map<long long, pair<long long, long long>> data;
        data.reserve(2 * n + 2 * q);
        long long timer = n;
        for (int key = 1; key <= n; ++key) {
            data[key] = {0, key};
            order.insert({key, key});
        }
        while (q--) {
            int type;
            long long key;
            cin >> type >> key;
            if (type == 1) {
                long long value;
                cin >> value;
                auto it = data.find(key);
                if (it == data.end()) {
                    auto victim = *order.begin();
                    data.erase(victim.second);
                    order.erase(victim);
                } else {
                    order.erase({it->second.second, key});
                }
                data[key] = {value, ++timer};
                order.insert({timer, key});
            } else {
                auto it = data.find(key);
                if (it == data.end()) {
                    cout << -1 << '\n';
                    continue;
                }
                long long time = it->second.second;
                cout << it->second.first << ' ' << (order.size() - order.order_of_key({time, LLONG_MAX}) + 1) << '\n';
                order.erase({time, key});
                it->second.second = ++timer;
                order.insert({timer, key});
            }
        }
    }
}
