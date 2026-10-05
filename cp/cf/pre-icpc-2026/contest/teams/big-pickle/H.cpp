// H - Humble RLU Cache: LRU with order queries.
// timestamp = last touch; order = active - (number of active timestamps < mine)
#include <bits/stdc++.h>
using namespace std;
struct Fen {
    int n; vector<int> t;
    Fen(int n) : n(n), t(n + 1, 0) {}
    void add(int i, int v) { for (; i <= n; i += i & -i) t[i] += v; }
    int sum(int i) const { int s = 0; for (; i > 0; i -= i & -i) s += t[i]; return s; }
};
int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    string out;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<array<long long, 3>> Q(q);
        vector<long long> keys;
        keys.reserve(n + q);
        for (int i = 1; i <= n; i++) keys.push_back(i);
        for (int i = 0; i < q; i++) {
            cin >> Q[i][0] >> Q[i][1];
            keys.push_back(Q[i][1]);
            if (Q[i][0] == 1) cin >> Q[i][2];
        }
        sort(keys.begin(), keys.end());
        keys.erase(unique(keys.begin(), keys.end()), keys.end());
        int K = keys.size();
        auto idx = [&](long long v) { return int(lower_bound(keys.begin(), keys.end(), v) - keys.begin()); };
        vector<long long> val(K, 0);
        vector<int> ts(K, -1);            // current timestamp, -1 = not in cache
        Fen fw(n + q + 2);
        for (int i = 1; i <= n; i++) {     // key i inserted, key 1 is LRU
            int c = idx(i);
            val[c] = 0; ts[c] = i; fw.add(i, 1);
        }
        const int active = n;     // cache always holds exactly n entries
        int timer = n;
        deque<pair<int, int>> dq;         // (key index, timestamp) in increasing timestamp order
        for (int i = 1; i <= n; i++) dq.push_back({idx(i), i});
        for (int i = 0; i < q; i++) {
            int type = (int)Q[i][0];
            int c = idx(Q[i][1]);
            if (type == 1) {
                if (ts[c] >= 0) {
                    fw.add(ts[c], -1);
                } else {
                    // evict LRU
                    while (!dq.empty() && ts[dq.front().first] != dq.front().second) dq.pop_front();
                    int e = dq.front().first;
                    dq.pop_front();
                    fw.add(ts[e], -1);
                    ts[e] = -1;
                }
                val[c] = Q[i][2];
                ts[c] = ++timer;
                fw.add(ts[c], 1);
                dq.push_back({c, ts[c]});
            } else {
                if (ts[c] < 0) { out += "-1\n"; continue; }
                int order = active - fw.sum(ts[c] - 1);
                out += to_string(val[c]);
                out += ' ';
                out += to_string(order);
                out += '\n';
                fw.add(ts[c], -1);
                ts[c] = ++timer;
                fw.add(ts[c], 1);
                dq.push_back({c, ts[c]});
            }
        }
    }
    fwrite(out.data(), 1, out.size(), stdout);
}
