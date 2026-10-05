#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;
    void init(int n_) { n = n_; bit.assign(n + 1, 0); }
    void add(int i, int v) { for (; i <= n; i += i & -i) bit[i] += v; }
    int sum(int i) { int r = 0; for (; i > 0; i -= i & -i) r += bit[i]; return r; }
    int kth(int k) {
        int idx = 0;
        int logn = 1;
        while (logn * 2 <= n) logn *= 2;
        for (int d = logn; d; d >>= 1)
            if (idx + d <= n && bit[idx + d] < k) { k -= bit[idx + d]; idx += d; }
        return idx + 1;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    string out;
    out.reserve(1 << 20);
    while (t--) {
        int n, q;
        scanf("%d %d", &n, &q);
        int T = q + n + 5;
        Fenwick fw; fw.init(T);
        unordered_map<long long, int> key2ts;
        unordered_map<long long, long long> key2val;
        key2ts.reserve(2 * n + q + 10);
        key2val.reserve(2 * n + q + 10);
        vector<long long> ts2key(T + 1, 0);
        int cur = 1, sz = 0;
        for (long long k = 1; k <= n; k++) {
            key2ts[k] = cur;
            key2val[k] = 0;
            ts2key[cur] = k;
            fw.add(cur, 1);
            cur++; sz++;
        }
        while (q--) {
            int ty; scanf("%d", &ty);
            if (ty == 1) {
                long long a, b; scanf("%lld %lld", &a, &b);
                auto it = key2ts.find(a);
                if (it != key2ts.end()) {
                    fw.add(it->second, -1);
                } else {
                    if (sz == n) {
                        int ts = fw.kth(1);
                        long long k = ts2key[ts];
                        fw.add(ts, -1);
                        key2ts.erase(k);
                        sz--;
                    }
                    sz++;
                }
                key2ts[a] = cur;
                key2val[a] = b;
                ts2key[cur] = a;
                fw.add(cur, 1);
                cur++;
            } else {
                long long a; scanf("%lld", &a);
                auto it = key2ts.find(a);
                if (it == key2ts.end()) {
                    out += "-1\n";
                } else {
                    int ts = it->second;
                    long long v = key2val[a];
                    int r = sz - fw.sum(ts) + 1;
                    out += to_string(v);
                    out += ' ';
                    out += to_string(r);
                    out += '\n';
                    // refresh to MRU
                    fw.add(ts, -1);
                    key2ts[a] = cur;
                    ts2key[cur] = a;
                    fw.add(cur, 1);
                    cur++; // sz unchanged
                }
            }
        }
    }
    fwrite(out.data(), 1, out.size(), stdout);
    return 0;
}
