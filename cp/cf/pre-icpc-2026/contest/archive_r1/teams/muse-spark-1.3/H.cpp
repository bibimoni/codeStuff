#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<int> b;
    BIT(int n = 0) { init(n); }
    void init(int n_) { n = n_; b.assign(n + 1, 0); }
    void add(int i, int v) { for (; i <= n; i += i & -i) b[i] += v; }
    int sum(int i) const { int s = 0; for (; i > 0; i -= i & -i) s += b[i]; return s; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, q;
        cin >> n >> q;
        BIT bit(n + q + 5);
        unordered_map<int, pair<int,int>> mp; // key -> (time, value)
        mp.reserve(n + q * 2);
        map<int,int> t2k; // time -> key
        int timer = 0;
        for (int k = 1; k <= n; k++) {
            ++timer;
            mp[k] = {timer, 0};
            t2k[timer] = k;
            bit.add(timer, 1);
        }
        for (int i = 0; i < q; i++) {
            int ty;
            cin >> ty;
            if (ty == 1) {
                int a, b;
                cin >> a >> b;
                auto it = mp.find(a);
                ++timer;
                if (it != mp.end()) {
                    int ot = it->second.first;
                    bit.add(ot, -1);
                    t2k.erase(ot);
                    it->second = {timer, b};
                    t2k[timer] = a;
                    bit.add(timer, 1);
                } else {
                    // evict LRU
                    auto lit = t2k.begin();
                    int ot = lit->first, ok = lit->second;
                    bit.add(ot, -1);
                    t2k.erase(lit);
                    mp.erase(ok);
                    mp[a] = {timer, b};
                    t2k[timer] = a;
                    bit.add(timer, 1);
                }
            } else {
                int a;
                cin >> a;
                auto it = mp.find(a);
                if (it == mp.end()) {
                    cout << -1 << '\n';
                } else {
                    int ot = it->second.first, val = it->second.second;
                    int r = n - bit.sum(ot) + 1;
                    cout << val << ' ' << r << '\n';
                    // move to front
                    ++timer;
                    bit.add(ot, -1);
                    t2k.erase(ot);
                    it->second.first = timer;
                    t2k[timer] = a;
                    bit.add(timer, 1);
                }
            }
        }
    }
    return 0;
}
