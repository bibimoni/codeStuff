// OK solution: same math as MA, deliberately different structure — no
// duplicated array; cyclic intervals are decomposed into one direct range plus
// one wrapped range carrying a constant prefix-offset C (total ring sum).
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
    static Node merge(const Node& l, const Node& r) {
        Node res; res.tag = 0;
        res.mnA = min(l.mnA, r.mnA); res.mxB = max(l.mxB, r.mxB);
        res.best = max({l.best, r.best, r.mxB - l.mnA});
        return res;
    }
    static Node shifted(Node x, ll off) { x.mnA += off; x.mxB += off; return x; } // best invariant
    int N; vector<Node> t;
    void init(int n_) { N = n_; t.assign(4 * N + 4, {INF, -INF, -INF, 0}); }
    void apply(int p, ll v) { t[p].mnA += v; t[p].mxB += v; t[p].tag += v; }
    void push(int p) { if (t[p].tag) { apply(p<<1, t[p].tag); apply(p<<1|1, t[p].tag); t[p].tag = 0; } }
    void build(int p, int l, int r, const vector<ll>& P, const vector<ll>& b) {
        if (l == r) { t[p].mnA = P[l-1] + b[l]; t[p].mxB = P[l-1] - b[l]; t[p].best = -INF; t[p].tag = 0; return; }
        int m = (l + r) >> 1;
        build(p<<1, l, m, P, b); build(p<<1|1, m+1, r, P, b);
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
    bool query(int p, int l, int r, int ql, int qr, Node& out) {
        if (qr < ql) return false;
        if (ql <= l && r <= qr) { out = t[p]; return true; }
        push(p); int m = (l + r) >> 1;
        if (qr <= m) return query(p<<1, l, m, ql, qr, out);
        if (ql > m) return query(p<<1|1, m+1, r, ql, qr, out);
        Node ln, rn;
        query(p<<1, l, m, ql, qr, ln); query(p<<1|1, m+1, r, ql, qr, rn);
        out = merge(ln, rn);
        return true;
    }
};

int n, q;
vector<ll> A, B;
Fenw fw;
Seg seg;

ll P(int m) { return fw.sum(m); }

// cyclic interval [t .. s+n] on the dup ring == [t..n] ++ ([1..s] shifted +C)
// generic: direct part [l1..r1], wrapped part [1..r2] with offset C
Seg::Node wrapNode(int l1, int r1, int r2, ll C) {
    Seg::Node out{(INF), -INF, -INF, 0}, tmp;
    bool any = false;
    if (l1 <= r1 && seg.query(1, 1, n, l1, r1, tmp)) { out = tmp; any = true; }
    if (r2 >= 1 && seg.query(1, 1, n, 1, r2, tmp)) {
        tmp = Seg::shifted(tmp, C);
        out = any ? Seg::merge(out, tmp) : tmp;
        any = true;
    }
    return out;
}

ll answer(int s, int t) {
    ll C = fw.sum(n);
    if (t == n + 1) {
        ll r1 = wrapNode(s, n, s - 1, C).mnA - P(s - 1);
        ll r2 = P(s - 1) + C - wrapNode(s + 1, n, s - 1, C).mxB;
        return min(r1, r2);
    }
    ll cw = P(t - 1) - P(s - 1), ccw = C - cw;
    ll ans = min(cw, ccw);
    Seg::Node p1;
    seg.query(1, 1, n, s, t, p1);
    if (p1.best > -INF) ans = min(ans, cw - p1.best);
    Seg::Node p2 = wrapNode(t, n, s, C); // dup [t, s+n]
    if (p2.best > -INF) ans = min(ans, ccw - p2.best);
    if (t - s <= n - 2) { // complement region nonempty
        Seg::Node insideK; seg.query(1, 1, n, s, t - 1, insideK);
        Seg::Node comp = wrapNode(t + 1, n, s - 1, C); // dup [t+1, s+n-1]
        ans = min(ans, -P(s - 1) + insideK.mnA - P(t - 1) + comp.mnA);
        Seg::Node insideJ; seg.query(1, 1, n, s + 1, t, insideJ);
        ans = min(ans, P(s - 1) + C - comp.mxB + P(t - 1) - insideJ.mxB);
    }
    return ans;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d %d", &n, &q);
        A.assign(n + 1, 0); B.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) scanf("%lld", &A[i]);
        for (int i = 1; i <= n; i++) scanf("%lld", &B[i]);
        vector<ll> Pv(n + 1, 0);
        for (int i = 1; i <= n; i++) Pv[i] = Pv[i-1] + A[i];
        fw.init(n);
        for (int i = 1; i <= n; i++) fw.add(i, A[i]);
        seg.init(n);
        seg.build(1, 1, n, Pv, B);
        for (int e = 0; e < q; e++) {
            int tp; scanf("%d", &tp);
            if (tp == 1) {
                int s, t; scanf("%d %d", &s, &t);
                printf("%lld\n", answer(s, t));
            } else if (tp == 2) {
                int x; ll w; scanf("%d %lld", &x, &w);
                ll d = w - A[x]; A[x] = w;
                fw.add(x, d);
                if (x + 1 <= n) seg.add(1, 1, n, x + 1, n, d);
            } else {
                int x; ll w; scanf("%d %lld", &x, &w);
                ll d = w - B[x]; B[x] = w;
                seg.pointB(1, 1, n, x, d);
            }
        }
    }
    return 0;
}
