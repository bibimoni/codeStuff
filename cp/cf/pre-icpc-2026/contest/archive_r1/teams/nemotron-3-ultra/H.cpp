#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef pair<long long, int> pli;
typedef tree<pli, null_type, less<pli>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        
        ordered_set os;
        unordered_map<int, pair<long long, ordered_set::iterator>> mp;
        mp.reserve(n * 2);
        
        long long cur_time = -n;
        for (int i = 1; i <= n; ++i) {
            cur_time--;
            auto it = os.insert({cur_time, i}).first;
            mp[i] = {0, it};
        }
        
        while (q--) {
            int type;
            cin >> type;
            if (type == 1) {
                int a;
                long long b;
                cin >> a >> b;
                auto it = mp.find(a);
                if (it != mp.end()) {
                    // update value, move to MRU
                    auto oit = it->second.second;
                    os.erase(oit);
                    cur_time--;
                    oit = os.insert({cur_time, a}).first;
                    it->second = {b, oit};
                } else {
                    if ((int)mp.size() == n) {
                        // evict LRU
                        auto lru_it = prev(os.end());
                        mp.erase(lru_it->second);
                        os.erase(lru_it);
                    }
                    cur_time--;
                    auto oit = os.insert({cur_time, a}).first;
                    mp[a] = {b, oit};
                }
            } else {
                int a;
                cin >> a;
                auto it = mp.find(a);
                if (it == mp.end()) {
                    cout << -1 << '\n';
                } else {
                    long long val = it->second.first;
                    auto oit = it->second.second;
                    long long rank = os.order_of_key(*oit) + 1;
                    cout << val << ' ' << rank << '\n';
                    // move to MRU
                    os.erase(oit);
                    cur_time--;
                    oit = os.insert({cur_time, a}).first;
                    it->second = {val, oit};
                }
            }
        }
    }
    return 0;
}