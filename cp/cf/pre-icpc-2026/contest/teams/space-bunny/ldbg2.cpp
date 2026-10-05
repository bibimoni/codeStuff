#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (ll)4e18;
struct Node { ll mnF, mnG, mxG, P1, P2, lzS, lzB; };
// lazy tag (lzS: SS+=, lzB: b+=)
struct Seg {
    int n; vector<Node> t;
    Seg(int n) : n(n), t(4 * n + 8) {}
    void setLeaf(int p, ll F, ll G) { t[p].mnF = F; t[p].mnG = G; t[p].mxG = -G; t[p].P1 = INF; t[p].P2 = INF; t[p].lzS = t[p].lzB = 0; }
    void pull(int p) {
        Node &a = t[p], &L = t[p * 2], &R = t[p * 2 + 1];
        a.mnF = min(L.mnF, R.mnF);
        a.mnG = min(L.mnG, R.mnG);
        a.mxG = max(L.mxG, R.mxG);
        a.P1 = min(min(L.P1, R.P1), L.mnF + R.mnG);
        a.P2 = min(min(L.P2, R.P2), L.mnF - R.mxG);
    }
    void apply(int p, ll ds, ll db) {
        t[p].mnF += ds + db;
        t[p].mnG += db - ds;
        t[p].mxG += db - ds;
        t[p].P1 += 2 * db;
        t[p].P2 += 2 * ds;
        t[p].lzS += ds; t[p].lzB += db;
    }
    void push(int p) { if (t[p].lzS || t[p].lzB) { apply(p * 2, t[p].lzS, t[p].lzB); apply(p * 2 + 1, t[p].lzS, t[p].lzB); t[p].lzS = t[p].lzB = 0; } }
    void build(int p, int l, int r, const vector<ll> &F, const vector<ll> &G) {
        if (l == r) { setLeaf(p, F[l], G[l]); return; }
        int m = (l + r) / 2;
        build(p * 2, l, m, F, G); build(p * 2 + 1, m + 1, r, F, G);
        pull(p);
    }
    void rangeAdd(int p, int l, int r, int ql, int qr, ll ds, ll db) {
        if (ql <= l && r <= qr) { apply(p, ds, db); return; }
        push(p);
        int m = (l + r) / 2;
        if (ql <= m) rangeAdd(p * 2, l, m, ql, qr, ds, db);
        if (qr > m) rangeAdd(p * 2 + 1, m + 1, r, ql, qr, ds, db);
        pull(p);
    }
    void pointAdd(int p, int l, int r, int pos, ll ds, ll db) {
        if (l == r) { apply(p, ds, db); return; }
        push(p);
        int m = (l + r) / 2;
        if (pos <= m) pointAdd(p * 2, l, m, pos, ds, db);
        else pointAdd(p * 2 + 1, m + 1, r, pos, ds, db);
        pull(p);
    }
    void mergeInto(Node &o, const Node &c) {
        o.P1 = min(min(o.P1, c.P1), o.mnF + c.mnG);
        o.P2 = min(min(o.P2, c.P2), o.mnF - c.mxG);
        o.mnF = min(o.mnF, c.mnF);
        o.mnG = min(o.mnG, c.mnG);
        o.mxG = max(o.mxG, c.mxG);
    }
    void query(int p, int l, int r, int ql, int qr, Node &o) {
        if (ql <= l && r <= qr) { mergeInto(o, t[p]); return; }
        push(p);
        int m = (l + r) / 2;
        if (ql <= m) query(p * 2, l, m, ql, qr, o);
        if (qr > m) query(p * 2 + 1, m + 1, r, ql, qr, o);
    }
    Node get(int ql, int qr) {
        Node o; o.mnF = o.mnG = o.P1 = o.P2 = INF; o.mxG = -INF;
        if (ql <= qr) query(1, 1, n, ql, qr, o);
        return o;
    }
};
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, q; scanf("%d %d", &n, &q);
        vector<ll> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
        vector<ll> bit(n + 1, 0);
        auto addA = [&](int i, ll d) { for (; i <= n; i += i & -i) bit[i] += d; };
        auto sumA = [&](int i) { ll s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; };
        for (int i = 1; i <= n; i++) addA(i, a[i]);
        int N2 = 2 * n;
        auto SS = [&](int i) -> ll { return i - 1 <= n ? sumA(i - 1) : sumA(n) + sumA(i - 1 - n); };
        auto isl = [&](int i) { return (i - 1) % n + 1; };
        fprintf(stderr,"N2=%d\n",N2);
        vector<ll> F(N2 + 1), G(N2 + 1);
        for (int i = 1; i <= N2; i++) { ll s = SS(i); F[i] = s + b[isl(i)]; G[i] = b[isl(i)] - s; }
        Seg seg(N2);
        seg.build(1, 1, N2, F, G);
        for (int qi = 0; qi < q; qi++) {
            int type; scanf("%d", &type);
            if (type == 2) {
                int x; ll w; scanf("%d %lld", &x, &w);
                ll d = w - a[x]; a[x] = w;
                if (d) { addA(x, d); seg.rangeAdd(1, 1, N2, x + 1, N2, d, 0); }
            } else if (type == 3) {
                int x; ll w; scanf("%d %lld", &x, &w);
                ll e = w - b[x]; b[x] = w;
                if (e) { seg.pointAdd(1, 1, N2, x, 0, e); seg.pointAdd(1, 1, N2, x + n, 0, e); }
            } else {
                int s, tt; scanf("%d %d", &s, &tt);
                ll ans = INF, T = sumA(n);
                if (tt == n + 1) {
                    ll ss = SS(s);
                    Node A = seg.get(s, s + n - 1);
                    ans = min(ans, A.mnF - ss);
                    Node B = seg.get(s + 1, s + n - 1);
                    if (B.mxG > -INF) ans = min(ans, ss + T - B.mxG);
                } else {
                    ll ss = SS(s), st = SS(tt), ssn = SS(s + n);
                    ans = min(ans, st - ss);                    // cycle arc F
                    ans = min(ans, ss + T - st);                // cycle arc B
                    // case i: A fwd [s,u], B fwd [w,t], u<w
                    ans = min(ans, st - ss + seg.get(s, tt).P1);
                    // case ii: A fwd [s,u], B bwd [t,z]
                    Node A1 = seg.get(s, tt - 1), B1 = seg.get(tt + 1, s + n - 1);
                    if (A1.mnF < INF && B1.mnF < INF) ans = min(ans, A1.mnF + B1.mnF - ss - st);
                    // case iii: A bwd [u,s+n], B fwd [w,t]
                    Node A2 = seg.get(tt + 1, s + n - 1), B2 = seg.get(s + 1, tt);
                    if (A2.mxG > -INF && B2.mxG > -INF) ans = min(ans, ssn + st - A2.mxG - B2.mxG);
                    // case iv: A bwd [u,s+n], B bwd [t,z], z<u
                    if (A2.P2 < INF) ans = min(ans, ssn - st + A2.P2);
                }
                fprintf(stderr,"s=%d t=%d T=%lld ss=%lld ans=%lld\n",s,tt,sumA(n),SS(s),ans);
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}
