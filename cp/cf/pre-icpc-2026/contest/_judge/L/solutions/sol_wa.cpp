// WA solution (registered hack): the author considers ring arcs and hub
// detours whose two ring arcs lie in the SAME cyclic region (the pair-max
// cases), but forgets the mixed-orientation case where the arc leaving s goes
// clockwise while the arc entering t comes from the counterclockwise side.
// Fast and passes samples; killed by the pinned mixed-optimum tests.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (1LL << 62);

struct Fenw {
    int n; vector<ll> f;
    void init(int n_) { n = n_; f.assign(n + 1, 0); }
    void add(int i, ll v) { for (; i <= n; i += i & -i) f[i] += v; }
    ll sum(int i) const { ll r = 0; for (; i > 0; i -= i & -i) r += f[i]; return r; }
};

struct Seg {
    struct Node { ll mnA, mxB, best, tag; };
    int N; vector<Node> t;
    void init(int n_) { N = n_; t.assign(4 * N + 4, {INF, -INF, -INF, 0}); }
    static Node merge(const Node& l, const Node& r) {
        Node res; res.tag = 0;
        res.mnA = min(l.mnA, r.mnA); res.mxB = max(l.mxB, r.mxB);
        res.best = max({l.best, r.best, r.mxB - l.mnA});
        return res;
    }
    void apply(int p, ll v) { t[p].mnA += v; t[p].mxB += v; t[p].tag += v; }
    void push(int p) { if (t[p].tag) { apply(p<<1, t[p].tag); apply(p<<1|1, t[p].tag); t[p].tag = 0; } }
    void build(int p, int l, int r, const vector<ll>& P, const vector<ll>& bD) {
        if (l == r) { t[p].mnA = P[l-1] + bD[l]; t[p].mxB = P[l-1] - bD[l]; t[p].best = -INF; t[p].tag = 0; return; }
        int m = (l + r) >> 1;
        build(p<<1, l, m, P, bD); build(p<<1|1, m+1, r, P, bD);
        t[p] = merge(t[p<<1], t[p<<1|1]);
    }
    void add(int p, int l, int r, int ql, int qr, ll v) {
        if (qr < l || ql > r) return;
        if (ql <= l && r <= qr) { apply(p, v); return; }
        push(p); int m = (l + r) >> 1;
        add(p<<1, l, m, ql, qr, v); add(p<<1|1, m+1, r, ql, qr, v);
        t[p] = merge(t[p<<1], t[p<<1|1]);
    }
    void pointB(int p, int l, int r, int pos, ll delta) {
        if (l == r) { t[p].mnA += delta; t[p].mxB -= delta; return; }
        push(p); int m = (l + r) >> 1;
        if (pos <= m) pointB(p<<1, l, m, pos, delta); else pointB(p<<1|1, m+1, r, pos, delta);
        t[p] = merge(t[p<<1], t[p<<1|1]);
    }
    Node query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return t[p];
        push(p); int m = (l + r) >> 1;
        if (qr <= m) return query(p<<1, l, m, ql, qr);
        if (ql > m) return query(p<<1|1, m+1, r, ql, qr);
        return merge(query(p<<1, l, m, ql, qr), query(p<<1|1, m+1, r, ql, qr));
    }
};

int n, qnn;
vector<ll> A, Bv;
Fenw fw;
Seg seg;
int N2;

inline int vtx(int p) { return (p - 1) % n + 1; }
inline ll P(int m) { return fw.sum(m); }

ll answer(int s, int t) {
    if (t == n + 1) {
        ll r1 = seg.query(1, 1, N2, s, s + n - 1).mnA - P(s - 1);
        ll r2 = P(s + n - 1) - seg.query(1, 1, N2, s + 1, s + n - 1).mxB;
        return min(r1, r2);
    }
    ll cw = P(t - 1) - P(s - 1), tot = P(n), ccw = tot - cw;
    ll ans = min(cw, ccw);
    ll c1 = seg.query(1, 1, N2, s, t).best;
    if (c1 > -INF) ans = min(ans, cw - c1);
    ll c2 = seg.query(1, 1, N2, t, s + n).best;
    if (c2 > -INF) ans = min(ans, ccw - c2);
    return ans; // BUG: mixed-orientation hub detours never considered
}

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d %d", &n, &qnn);
        A.assign(n + 1, 0); Bv.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) scanf("%lld", &A[i]);
        for (int i = 1; i <= n; i++) scanf("%lld", &Bv[i]);
        N2 = 2 * n;
        vector<ll> Pv(N2 + 1, 0), bD(N2 + 1, 0);
        for (int i = 1; i <= N2; i++) Pv[i] = Pv[i-1] + A[vtx(i)];
        for (int i = 1; i <= N2; i++) bD[i] = Bv[vtx(i)];
        fw.init(N2);
        for (int i = 1; i <= N2; i++) fw.add(i, A[vtx(i)]);
        seg.init(N2);
        seg.build(1, 1, N2, Pv, bD);
        for (int e = 0; e < qnn; e++) {
            int tp; scanf("%d", &tp);
            if (tp == 1) {
                int s, t; scanf("%d %d", &s, &t);
                printf("%lld\n", answer(s, t));
            } else if (tp == 2) {
                int x; ll w; scanf("%d %lld", &x, &w);
                ll d = w - A[x]; A[x] = w;
                fw.add(x, d); fw.add(x + n, d);
                seg.add(1, 1, N2, x + 1, x + n, d);
                if (x + n + 1 <= N2) seg.add(1, 1, N2, x + n + 1, N2, 2 * d);
            } else {
                int x; ll w; scanf("%d %lld", &x, &w);
                ll d = w - Bv[x]; Bv[x] = w;
                seg.pointB(1, 1, N2, x, d);
                seg.pointB(1, 1, N2, x + n, d);
            }
        }
    }
    return 0;
}
