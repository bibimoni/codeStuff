#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cur;
int qcnt;

int ask(char d) {
    printf("? %c\n", d);
    fflush(stdout);
    int r;
    if (scanf("%d", &r) != 1) exit(1);
    qcnt++;
    return r;
}

ll depth(ll v) { return 63 - __builtin_clzll(v); }

ll lca(ll u, ll v) {
    while (u != v) {
        if (u > v) u >>= 1;
        else v >>= 1;
    }
    return u;
}

bool exists(ll x) {
    ll l = lca(cur, x);
    while (cur != l) {
        ask('B');
        cur >>= 1;
    }
    ll dL = depth(l), dX = depth(x);
    for (ll d = dL; d < dX; d++) {
        int bit = (int)((x >> (dX - d - 1)) & 1);
        int r = ask(bit ? 'R' : 'L');
        if (!r) return false;
        cur = cur * 2 + bit;
    }
    return true;
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 1;
    while (T--) {
        cur = 1;
        qcnt = 0;
        ll lo = 1, hi = (ll)1e18;
        while (lo < hi) {
            ll mid = lo + (hi - lo + 1) / 2;
            if (exists(mid)) lo = mid;
            else hi = mid - 1;
        }
        printf("! %lld\n", lo);
        fflush(stdout);
        if (qcnt > 8000) { fprintf(stderr, "QUERY OVERFLOW %d\n", qcnt); exit(1); }
    }
    return 0;
}
