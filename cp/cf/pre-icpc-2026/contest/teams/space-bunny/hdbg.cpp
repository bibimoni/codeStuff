#include <bits/stdc++.h>
using namespace std;
struct Fenwick {
    int n; vector<int> f;
    Fenwick(int n) : n(n), f(n + 1, 0) {}
    void add(int i, int v) { for (; i <= n; i += i & -i) f[i] += v; }
    int sum(int i) { int s = 0; for (; i > 0; i -= i & -i) s += f[i]; return s; }
};
int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int n, q; scanf("%d %d", &n, &q);
        int N = n + q + 5;
        Fenwick fw(N);
        int maxSlots = n + q + 2;
        vector<long long> val(maxSlots, 0), key(maxSlots, 0);
        vector<int> ts(maxSlots, 0);
        vector<int> nxt(maxSlots, -1), prv(maxSlots, -1);
        unordered_map<long long, int> mp;
        mp.reserve(4 * q + 16);
        int head = -1, tail = -1, cur = 0, timer = n;
        auto pushBack = [&](int s) {
            prv[s] = -1; nxt[s] = tail;
            if (tail != -1) prv[tail] = s; else if (head == -1) head = s;
            tail = s;
        };
        auto unlink = [&](int s) {
            if (prv[s] != -1) nxt[prv[s]] = nxt[s]; else head = nxt[s];
            if (nxt[s] != -1) prv[nxt[s]] = prv[s]; else tail = prv[s];
            prv[s] = nxt[s] = -1;
        };
        for (int i = 1; i <= n; i++) {
            int s = cur++;
            val[s] = 0; key[s] = i; ts[s] = i;
            mp[(long long)i] = s;
            pushBack(s);
            fw.add(ts[s], 1);
        }
        char outbuf[1 << 16]; int op = 0;
        auto emit = [&](const char *s) { while (*s) { if (op == (1 << 16)) fwrite(outbuf, 1, op, stdout), op = 0; outbuf[op++] = *s++; } };
        char tmp[64];
        for (int i = 0; i < q; i++) {
            int type; long long a; scanf("%d %lld", &type, &a); fprintf(stderr, "Q%d type=%d a=%lld\n", i, type, a);
            if (type == 1) {
                long long b; scanf("%lld", &b);
                auto it = mp.find(a);
                if (it != mp.end()) {
                    int s = it->second;
                    val[s] = b;
                    unlink(s); pushBack(s);
                    fw.add(ts[s], -1); ts[s] = ++timer; fw.add(ts[s], 1);
                } else {
                    int v = head;
                    mp.erase(key[v]);
                    unlink(v);
                    fw.add(ts[v], -1);
                    int s = cur++;
                    key[s] = a; val[s] = b; ts[s] = ++timer;
                    mp[a] = s; pushBack(s); fw.add(ts[s], 1);
                }
            } else {
                auto it = mp.find(a);
                if (it == mp.end()) { emit("-1\n"); continue; }
                int s = it->second;
                int r = 1 + (n - fw.sum(ts[s]));
                snprintf(tmp, sizeof tmp, "%lld %d\n", val[s], r);
                emit(tmp);
                unlink(s); pushBack(s);
                fw.add(ts[s], -1); ts[s] = ++timer; fw.add(ts[s], 1);
            }
        }
        fwrite(outbuf, 1, op, stdout); op = 0;
    }
    return 0;
}
