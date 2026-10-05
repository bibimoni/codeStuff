#include <bits/stdc++.h>
using namespace std;
struct Fenwick {
    int n; vector<int> f;
    Fenwick(int n) : n(n), f(n + 1, 0) {}
    void add(int i, int v) { for (; i <= n; i += i & -i) f[i] += v; }
    int sum(int i) { int s = 0; for (; i > 0; i -= i & -i) s += f[i]; return s; }
};
int main() {
    int T; if (scanf("%d", &T) != 1) return 0;
    string out;
    while (T--) {
        int n, q; if (scanf("%d %d", &n, &q) != 2) break;
        int N = n + q + 2;
        Fenwick bit(N);
        set<int> live;                 // timestamps of the keys currently cached
        vector<int> keyAt(N + 1, 0);    // timestamp -> key
        unordered_map<int, pair<int, int>> mp; // key -> (value, timestamp)
        mp.reserve(4 * n + 16);
        for (int i = 1; i <= n; i++) { mp[i] = {0, i}; live.insert(i); keyAt[i] = i; bit.add(i, 1); }
        int timer = n;
        for (int qi = 0; qi < q; qi++) {
            int type, a; if (scanf("%d %d", &type, &a) != 2) break;
            if (type == 1) {
                int b; if (scanf("%d", &b) != 1) break;
                int newts = ++timer;
                auto it = mp.find(a);
                if (it != mp.end()) {
                    int old = it->second.second;
                    live.erase(old); bit.add(old, -1); keyAt[old] = 0;
                } else {
                    int lru = *live.begin();
                    live.erase(live.begin());
                    bit.add(lru, -1);
                    mp.erase(keyAt[lru]); keyAt[lru] = 0;
                }
                mp[a] = {b, newts};
                live.insert(newts); keyAt[newts] = a; bit.add(newts, 1);
            } else {
                auto it = mp.find(a);
                if (it == mp.end()) out += "-1\n";
                else {
                    int val = it->second.first, ts = it->second.second;
                    out += to_string(val); out += ' '; out += to_string(n - bit.sum(ts) + 1); out += '\n';
                    live.erase(ts); bit.add(ts, -1); keyAt[ts] = 0;
                    int newts = ++timer;
                    it->second.second = newts; live.insert(newts); keyAt[newts] = a; bit.add(newts, 1);
                }
            }
        }
    }
    fwrite(out.data(), 1, out.size(), stdout);
    return 0;
}
