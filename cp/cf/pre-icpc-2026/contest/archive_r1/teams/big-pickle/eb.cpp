// brute force for E: count pairs (permutation, orientation) valid
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
int main() {
    int n;
    scanf("%d", &n);
    vector<array<int, 3>> es;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        es.push_back({u - 1, v - 1, w});
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    ll cnt = 0;
    do {
        vector<int> pos(n);
        for (int i = 0; i < n; i++) pos[p[i]] = i;
        // enumerate orientations of flexible edges
        int flex = 0;
        for (auto &e : es) if (e[2] == 0) flex++;
        bool any = true;
        for (int m = 0; m < (1 << flex) && any; m++) {
            bool good = true;
            int fi = 0;
            for (auto &e : es) {
                int u = e[0], v = e[1], w = e[2];
                bool uBeforeV;
                if (w == 1) uBeforeV = true;
                else if (w == 2) uBeforeV = false;
                else uBeforeV = (m >> fi++) & 1;
                if (pos[u] > pos[v]) uBeforeV = !uBeforeV;
                if (!uBeforeV) { good = false; break; }
            }
            if (good) cnt++;
        }
    } while (next_permutation(p.begin(), p.end()));
    printf("%lld\n", cnt % MOD);
}
