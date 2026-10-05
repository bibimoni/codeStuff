#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<int> bit;
    BIT(int n) : n(n), bit(n+1, 0) {}
    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }
    int sum(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) res += bit[idx];
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        int max_pos = n + q + 5;
        BIT bit(max_pos);
        unordered_map<long long, pair<long long, int>> mp;
        mp.reserve(n * 2);
        set<pair<int, long long>> ordered; // (position, key)
        
        for (int i = 1; i <= n; ++i) {
            mp[i] = {0, i};
            ordered.insert({i, i});
            bit.add(i, 1);
        }
        int cur_pos = n;
        
        while (q--) {
            int type;
            cin >> type;
            if (type == 1) {
                long long a, b;
                cin >> a >> b;
                auto it = mp.find(a);
                if (it != mp.end()) {
                    // update existing
                    long long val = it->second.first;
                    int pos = it->second.second;
                    ordered.erase({pos, a});
                    bit.add(pos, -1);
                    cur_pos++;
                    it->second = {b, cur_pos};
                    ordered.insert({cur_pos, a});
                    bit.add(cur_pos, 1);
                } else {
                    // insert new
                    if ((int)mp.size() == n) {
                        // evict LRU
                        auto [pos_lru, key_lru] = *ordered.begin();
                        ordered.erase(ordered.begin());
                        bit.add(pos_lru, -1);
                        mp.erase(key_lru);
                    }
                    cur_pos++;
                    mp[a] = {b, cur_pos};
                    ordered.insert({cur_pos, a});
                    bit.add(cur_pos, 1);
                }
            } else {
                long long a;
                cin >> a;
                auto it = mp.find(a);
                if (it == mp.end()) {
                    cout << -1 << '\n';
                } else {
                    long long val = it->second.first;
                    int pos = it->second.second;
                    int total = mp.size();
                    int rank = total - bit.sum(pos) + 1;
                    cout << val << ' ' << rank << '\n';
                    // make MRU
                    ordered.erase({pos, a});
                    bit.add(pos, -1);
                    cur_pos++;
                    it->second.second = cur_pos;
                    ordered.insert({cur_pos, a});
                    bit.add(cur_pos, 1);
                }
            }
        }
    }
    return 0;
}