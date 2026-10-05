// brute force for H: naive list cache
#include <bits/stdc++.h>
using namespace std;
int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int n, q; scanf("%d %d", &n, &q);
        // LRU first
        vector<pair<long long, long long>> c; // key, val
        for (int i = 1; i <= n; i++) c.push_back({i, 0});
        for (int i = 0; i < q; i++) {
            int type; long long a; scanf("%d %lld", &type, &a);
            int idx = -1;
            for (int j = 0; j < (int)c.size(); j++) if (c[j].first == a) idx = j;
            if (type == 1) {
                long long b; scanf("%lld", &b);
                if (idx != -1) c[idx].second = b;
                else { c.erase(c.begin()); c.push_back({a, b}); }
                if (idx != -1) { auto e = c[idx]; c.erase(c.begin() + idx); c.push_back(e); }
            } else {
                if (idx == -1) { printf("-1\n"); continue; }
                printf("%lld %d\n", c[idx].second, (int)c.size() - idx);
                auto e = c[idx]; c.erase(c.begin() + idx); c.push_back(e);
            }
        }
    }
}
