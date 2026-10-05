#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (ll)4e18;
struct Seg {
    int n;                       // number of leaves
    vector<ll> mnF, mnG, mnFG, lzF, lzG;
    Seg(int n) : n(n) {
        mnF.assign(4 * n, 0); mnG.assign(4 * n, 0); mnFG.assign(4 * n, INF);
        lzF.assign(4 * n, 0); lzG.assign(4 * n, 0);
    }
    void build(int p, int l, int r, const vector<ll> &F, const vector<ll> &G) {
        lzF[p] = lzG[p] = 0;
        if (l == r) { mnF[p] = F[l]; mnG[p] = G[l]; mnFG[p] = INF; return; }
        int m = (l + r) / 2;
        build(p * 2, l, m, F, G); build(p * 2 + 1, m + 1, r, F, G);
        pull(p);
    }
    void pull(int p) {
        mnF[p] = min(mnF[p * 2], mnF[p * 2 + 1]);
        mnG[p] = min(mnG[p * 2], mnG[p * 2 + 1]);
        mnFG[p] = min(mnFG[p * 2], min(mnFG[p * 2 + 1], mnF[p * 2] + mnG[p * 2 + 1]));
    }
    void apply(int p, ll df, ll dg) {
        mnF[p] += df; mnG[p] += dg; mnFG[p] += df + dg; lzF[p] += df; lzG[p] += dg;
    }
    void push(int p) { if (lzF[p] || lzG[p]) { apply(p * 2, lzF[p], lzG[p]); apply(p * 2 + 1, lzF[p], lzG[p]); lzF[p] = lzG[p] = 0; } }
    void rangeAdd(int p, int l, int r, int ql, int qr, ll df, ll dg) {
        if (ql <= l && r <= qr) { apply(p, df, dg); return; }
        push(p);
        int m = (l + r) / 2;
        if (ql <= m) rangeAdd(p * 2, l, m, ql, qr, df, dg);
        if (qr > m) rangeAdd(p * 2 + 1, m + 1, r, ql, qr, df, dg);
        pull(p);
    }
    void pointAdd(int p, int l, int r, int pos, ll df, ll dg) {
        if (l == r) { apply(p, df, dg); return; }
        push(p);
        int m = (l + r) / 2;
        if (pos <= m) pointAdd(p * 2, l, m, pos, df, dg);
        else pointAdd(p * 2 + 1, m + 1, r, pos, df, dg);
        pull(p);
    }
    void query(int p, int l, int r, int ql, int qr, ll &f, ll &g, ll &fg) {
        if (ql <= l && r <= qr) { f = min(f, mnF[p]); g = min(g, mnG[p]); fg = min(fg, mnFG[p]); return; }
        push(p);
        int m = (l + r) / 2;
        if (ql <= m) query(p * 2, l, m, ql, qr, f, g, fg);
        if (qr > m) query(p * 2 + 1, m + 1, r, ql, qr, f, g, fg);
    }
    void getTriple(int ql, int qr, ll &f, ll &g, ll &fg) {
        f = g = INF; fg = INF;
        if (ql <= qr) query(1, 1, n, ql, qr, f, g, fg);
    }
};
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, q; scanf("%d %d", &n, &q);
        vector<ll> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
        // Fenwick over a
        vector<ll> bit(n + 1, 0);
        auto addA = [&](int i, ll d) { for (; i <= n; i += i & -i) bit[i] += d; };
        auto sumA = [&](int i) { ll s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; };
        for (int i = 1; i <= n; i++) addA(i, a[i]);
        int N2 = 2 * n;
        auto SS = [&](int i) -> ll { return i - 1 <= n ? sumA(i - 1) : sumA(n) + sumA(i - 1 - n); };
        auto isl = [&](int i) { return (i - 1) % n + 1; };
        vector<ll> F(N2 + 1), G(N2 + 1);
        for (int i = 1; i <= N2; i++) { ll s = SS(i); F[i] = s + b[isl(i)]; G[i] = b[isl(i)] - s; }
        Seg seg(N2);
        seg.build(1, 1, N2, F, G);
        ll T = sumA(n);
        for (int qi = 0; qi < q; qi++) {
            int type; scanf("%d", &type);
            if (type == 2) {
                int x; ll w; scanf("%d %lld", &x, &w);
                ll d = w - a[x]; a[x] = w;
                if (d) { addA(x, d); seg.rangeAdd(1, 1, N2, x + 1, N2, d, -d); }
            } else if (type == 3) {
                int x; ll w; scanf("%d %lld", &x, &w);
                ll e = w - b[x]; b[x] = w;
                if (e) { seg.pointAdd(1, 1, N2, x, e, e); seg.pointAdd(1, 1, N2, x + n, e, e); }
            } else {
                int s, tt; scanf("%d %d", &s, &tt);
                ll ans = INF;
                if (tt == n + 1) {
                    ll f, g, fg;
                    seg.getTriple(s, s + n - 1, f, g, fg);
                    ll ss = SS(s);
                    ans = min(ans, f - ss);
                    seg.getTriple(1, s - 1, f, g, fg);
                    ans = min(ans, ss + g);
                    seg.getTriple(s + 1, n, f, g, fg);
                    ans = min(ans, ss + T + g);
                } else {
                    ll ss = SS(s), st = SS(tt);
                    ans = min(ans, st - ss);
                    ans = min(ans, ss + T - st);
                    ll f, g, fg;
                    seg.getTriple(s, tt, f, g, fg);
                    ans = min(ans, st - ss + fg);
                    seg.getTriple(tt + 1, n, f, g, fg);
                    ll g1 = g;
                    seg.getTriple(s + 1, tt, f, g, fg);
                    ans = min(ans, ss + st + g1 + g);
                    seg.getTriple(1, s - 1, f, g, fg);
                    ans = min(ans, ss + st + g + fg);
                }
                fprintf(stderr,"Q s=%d t=%d T=%lld ss=%lld st=%lld ans=%lld\n",s,tt,T,SS(s),SS(tt),ans);
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}
