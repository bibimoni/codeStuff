#include <bits/stdc++.h>
using namespace std;
const long long INFLL = (long long)4e18;

struct SegTree {
    struct Node {
        long long mu = INFLL, mv = INFLL, best = INFLL;
        bool empty = true;
    };
    int n;
    vector<long long> mu, mv, best, lz;
    vector<long long> bleaf; // b per leaf
    SegTree() {}
    SegTree(int n_) { init(n_); }
    void init(int n_) {
        n = n_;
        mu.assign(4 * max(1, n), INFLL);
        mv.assign(4 * max(1, n), INFLL);
        best.assign(4 * max(1, n), INFLL);
        lz.assign(4 * max(1, n), 0);
        bleaf.assign(n, 0);
    }
    void apply(int p, long long d) {
        mu[p] += d; mv[p] -= d; lz[p] += d;
    }
    void push(int p) {
        if (lz[p] != 0) {
            apply(p << 1, lz[p]);
            apply(p << 1 | 1, lz[p]);
            lz[p] = 0;
        }
    }
    void pull(int p) {
        mu[p] = min(mu[p << 1], mu[p << 1 | 1]);
        mv[p] = min(mv[p << 1], mv[p << 1 | 1]);
        long long c = INFLL;
        if (mu[p << 1] < INFLL/2 && mv[p << 1 | 1] < INFLL/2)
            c = mu[p << 1] + mv[p << 1 | 1];
        best[p] = min({best[p << 1], best[p << 1 | 1], c});
    }
    void build(int p, int l, int r, const vector<long long> &U, const vector<long long> &V) {
        if (l == r) { mu[p] = U[l]; mv[p] = V[l]; best[p] = INFLL; return; }
        int m = (l + r) >> 1;
        build(p << 1, l, m, U, V);
        build(p << 1 | 1, m + 1, r, U, V);
        pull(p);
    }
    void build(const vector<long long> &U, const vector<long long> &V, const vector<long long> &B) {
        bleaf = B;
        if (n) build(1, 0, n - 1, U, V);
    }
    void range_add(int p, int l, int r, int ql, int qr, long long d) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) { apply(p, d); return; }
        push(p);
        int m = (l + r) >> 1;
        range_add(p << 1, l, m, ql, qr, d);
        range_add(p << 1 | 1, m + 1, r, ql, qr, d);
        pull(p);
    }
    void range_add(int l, int r, long long d) {
        if (l > r || n == 0) return;
        range_add(1, 0, n - 1, l, r, d);
    }
    void point_set(int p, int l, int r, int idx, long long nb) {
        if (l == r) {
            long long P = mu[p] - bleaf[l];
            bleaf[l] = nb;
            mu[p] = P + nb;
            mv[p] = nb - P;
            best[p] = INFLL;
            return;
        }
        push(p);
        int m = (l + r) >> 1;
        if (idx <= m) point_set(p << 1, l, m, idx, nb);
        else point_set(p << 1 | 1, m + 1, r, idx, nb);
        pull(p);
    }
    void point_set(int idx, long long nb) { point_set(1, 0, n - 1, idx, nb); }
    Node query(int p, int l, int r, int ql, int qr) {
        Node e;
        if (qr < l || r < ql) return e;
        if (ql <= l && r <= qr) {
            Node o; o.mu = mu[p]; o.mv = mv[p]; o.best = best[p]; o.empty = false;
            return o;
        }
        push(p);
        int m = (l + r) >> 1;
        Node L = query(p << 1, l, m, ql, qr);
        Node R = query(p << 1 | 1, m + 1, r, ql, qr);
        return merge(L, R);
    }
    static Node merge(const Node &L, const Node &R) {
        if (L.empty) return R;
        if (R.empty) return L;
        Node o;
        o.empty = false;
        o.mu = min(L.mu, R.mu);
        o.mv = min(L.mv, R.mv);
        long long c = INFLL;
        if (L.mu < INFLL/2 && R.mv < INFLL/2) c = L.mu + R.mv;
        o.best = min({L.best, R.best, c});
        return o;
    }
    // query over [l,r] linear; wrap handled by caller via two queries+merge
    Node query(int l, int r) {
        if (l > r) return Node();
        return query(1, 0, n - 1, l, r);
    }
    Node query_wrap(int l, int r) { // cw from l to r (may wrap)
        if (l <= r) return query(l, r);
        return merge(query(l, n - 1), query(0, r));
    }
};

struct Fenwick {
    int n;
    vector<long long> b;
    Fenwick(int n = 0) { init(n); }
    void init(int n_) { n = n_; b.assign(n + 1, 0); }
    void add(int i, long long d) { for (++i; i <= n; i += i & -i) b[i] += d; }
    long long sumPrefix(int i) const { // sum [0..i], i may be -1
        long long s = 0;
        for (++i; i > 0; i -= i & -i) s += b[i];
        return s;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        auto rho = [&](int k) { return (n - k) % n; };
        // orig P
        vector<long long> P(n);
        P[0] = 0;
        for (int k = 1; k < n; k++) P[k] = P[k-1] + a[k-1];
        long long total = P[n-1] + a[n-1];
        vector<long long> U(n), V(n);
        for (int k = 0; k < n; k++) { U[k] = P[k] + b[k]; V[k] = b[k] - P[k]; }
        SegTree seg(n);
        seg.build(U, V, b);
        // rev
        vector<long long> a2(n);
        for (int e = 0; e < n; e++) a2[(n - 1 - e) % n] = a[e];
        vector<long long> P2(n);
        P2[0] = 0;
        for (int k = 1; k < n; k++) P2[k] = P2[k-1] + a2[k-1];
        vector<long long> b2(n);
        for (int k = 0; k < n; k++) b2[rho(k)] = b[k];
        vector<long long> U2(n), V2(n);
        for (int k = 0; k < n; k++) { U2[k] = P2[k] + b2[k]; V2[k] = b2[k] - P2[k]; }
        SegTree seg2(n);
        seg2.build(U2, V2, b2);
        Fenwick fw(n);
        for (int e = 0; e < n; e++) fw.add(e, a[e]);

        for (int iq = 0; iq < q; iq++) {
            int ty; cin >> ty;
            if (ty == 1) {
                int s, t; cin >> s >> t; --s; --t;
                if (t == n) { // hub target (t is 1-indexed n+1 -> 0-based n)
                    long long Ps = fw.sumPrefix(s - 1);
                    long long ans = INFLL;
                    auto q1 = seg.query(0, s - 1);
                    auto q2 = seg.query(s, n - 1);
                    auto q3 = seg.query(0, s);
                    auto q4 = seg.query(s + 1, n - 1);
                    if (!q1.empty) ans = min(ans, q1.mu + total - Ps);
                    if (!q2.empty) ans = min(ans, q2.mu - Ps);
                    if (!q3.empty) ans = min(ans, q3.mv + Ps);
                    if (!q4.empty) ans = min(ans, q4.mv + total + Ps);
                    cout << ans << '\n';
                    continue;
                }
                int s0 = s, t0 = t;
                long long Ps = fw.sumPrefix(s0 - 1);
                long long Pt = fw.sumPrefix(t0 - 1);
                long long ring = min(Pt - Ps, total - (Pt - Ps));
                long long ans = ring;
                // XX
                {
                    auto nd = seg.query(s0, t0);
                    ans = min(ans, (Pt - Ps) + nd.best);
                }
                // YY (rev interval may wrap: cross pairs need offset-total)
                {
                    int rl = rho(s0), rr = rho(t0);
                    long long off = Ps - Pt + total;
                    if (rl <= rr) {
                        auto nd = seg2.query(rl, rr);
                        ans = min(ans, off + nd.best);
                    } else {
                        auto L = seg2.query(rl, n - 1);
                        auto R = seg2.query(0, rr);
                        long long yy = INFLL;
                        if (!L.empty) yy = min(yy, off + L.best);
                        if (!R.empty) yy = min(yy, off + R.best);
                        if (!L.empty && !R.empty && L.mu < INFLL/2 && R.mv < INFLL/2)
                            yy = min(yy, (off - total) + L.mu + R.mv);
                        ans = min(ans, yy);
                    }
                }
                // Z
                {
                    auto left = seg.query(s0, t0 - 1);
                    long long za = left.mu - Ps;
                    auto r1 = seg.query(t0, n - 1);
                    auto r2 = seg.query(0, s0 - 1);
                    long long zb = INFLL;
                    if (!r1.empty) zb = min(zb, r1.mu);
                    if (!r2.empty) zb = min(zb, r2.mu + total);
                    zb -= Pt;
                    ans = min(ans, za + zb);
                }
                // W
                {
                    auto r1 = seg.query(0, s0);
                    auto r2 = seg.query(t0 + 1, n - 1);
                    long long wa = INFLL;
                    if (!r1.empty) wa = min(wa, r1.mv);
                    if (!r2.empty) wa = min(wa, r2.mv + total);
                    wa += Ps;
                    auto right = seg.query(s0 + 1, t0);
                    long long wb = Pt + right.mv;
                    ans = min(ans, wa + wb);
                }
                cout << ans << '\n';
            } else if (ty == 2) {
                int x; long long w; cin >> x >> w; --x;
                long long d = w - a[x];
                if (d != 0) {
                    a[x] = w;
                    total += d;
                    fw.add(x, d);
                    seg.range_add(x + 1, n - 1, d);
                    int f = (n - 1 - x) % n;
                    seg2.range_add(f + 1, n - 1, d);
                }
            } else {
                int x; long long w; cin >> x >> w; --x;
                b[x] = w;
                seg.point_set(x, w);
                seg2.point_set(rho(x), w);
            }
        }
    }
    return 0;
}
