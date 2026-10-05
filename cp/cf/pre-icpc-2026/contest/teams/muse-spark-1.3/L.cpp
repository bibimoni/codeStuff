#include <bits/stdc++.h>
using namespace std;
const long long INFLL = (long long)4e18;

struct SegTree {
    struct Node { long long x, y, b; }; // minX, minY, best
    int n;
    vector<long long> mx, my, be, lz;
    SegTree() {}
    SegTree(int n_) { init(n_); }
    void init(int n_) {
        n = n_;
        mx.assign(4 * n + 4, INFLL);
        my.assign(4 * n + 4, INFLL);
        be.assign(4 * n + 4, INFLL);
        lz.assign(4 * n + 4, 0);
    }
    void build(int v, int l, int r, const vector<long long> &X0, const vector<long long> &Y0) {
        if (l == r) { mx[v] = X0[l]; my[v] = Y0[l]; be[v] = INFLL; return; }
        int m = (l + r) >> 1;
        build(v<<1, l, m, X0, Y0);
        build(v<<1|1, m+1, r, X0, Y0);
        pull(v);
    }
    void build(const vector<long long> &X0, const vector<long long> &Y0) { build(1, 1, n, X0, Y0); }
    void apply(int v, long long d) {
        mx[v] += d; my[v] -= d; lz[v] += d;
    }
    void push(int v) {
        if (lz[v]) { apply(v<<1, lz[v]); apply(v<<1|1, lz[v]); lz[v] = 0; }
    }
    void pull(int v) {
        mx[v] = min(mx[v<<1], mx[v<<1|1]);
        my[v] = min(my[v<<1], my[v<<1|1]);
        long long cross = INFLL;
        if (mx[v<<1] < INFLL/2 && my[v<<1|1] < INFLL/2) {
            __int128 s = (__int128)mx[v<<1] + my[v<<1|1];
            cross = s > INFLL ? INFLL : (long long)s;
        }
        be[v] = min({be[v<<1], be[v<<1|1], cross});
    }
    void range_add(int v, int l, int r, int ql, int qr, long long d) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) { apply(v, d); return; }
        push(v);
        int m = (l + r) >> 1;
        range_add(v<<1, l, m, ql, qr, d);
        range_add(v<<1|1, m+1, r, ql, qr, d);
        pull(v);
    }
    void range_add(int l, int r, long long d) {
        if (l > r) return;
        range_add(1, 1, n, l, r, d);
    }
    void point_set(int v, int l, int r, int idx, long long xv, long long yv) {
        if (l == r) { mx[v] = xv; my[v] = yv; be[v] = INFLL; lz[v] = 0; return; }
        push(v);
        int m = (l + r) >> 1;
        if (idx <= m) point_set(v<<1, l, m, idx, xv, yv);
        else point_set(v<<1|1, m+1, r, idx, xv, yv);
        pull(v);
    }
    void point_set(int idx, long long xv, long long yv) { point_set(1, 1, n, idx, xv, yv); }
    Node query(int v, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return {INFLL, INFLL, INFLL};
        if (ql <= l && r <= qr) return {mx[v], my[v], be[v]};
        push(v);
        int m = (l + r) >> 1;
        Node L = query(v<<1, l, m, ql, qr);
        Node R = query(v<<1|1, m+1, r, ql, qr);
        Node res;
        res.x = min(L.x, R.x);
        res.y = min(L.y, R.y);
        long long cross = INFLL;
        if (L.x < INFLL/2 && R.y < INFLL/2) {
            __int128 s = (__int128)L.x + R.y;
            cross = s > INFLL ? INFLL : (long long)s;
        }
        res.b = min({L.b, R.b, cross});
        return res;
    }
    Node query(int l, int r) {
        if (l > r) return {INFLL, INFLL, INFLL};
        return query(1, 1, n, l, r);
    }
};

struct Fenwick {
    int n;
    vector<long long> bit;
    Fenwick() {}
    Fenwick(int n_) { init(n_); }
    void init(int n_) { n = n_; bit.assign(n + 1, 0); }
    void add(int i, long long d) { for (; i <= n; i += i & -i) bit[i] += d; }
    long long sumPrefix(int i) const { long long s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int TT;
    if (!(cin >> TT)) return 0;
    while (TT--) {
        int n, q;
        cin >> n >> q;
        vector<long long> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        int N2 = 2 * n;
        vector<long long> e(N2 + 2, 0);
        for (int i = 1; i <= N2; i++) e[i] = a[(i - 1) % n + 1];
        Fenwick fw(N2 + 2);
        for (int i = 1; i <= N2; i++) fw.add(i, e[i]);
        auto Pref = [&](int i) -> long long {
            // P[i] = sum e[1..i-1]
            if (i <= 1) return 0;
            return fw.sumPrefix(i - 1);
        };
        vector<long long> X0(N2 + 2, INFLL), Y0(N2 + 2, INFLL);
        long long run = 0;
        for (int i = 1; i <= N2; i++) {
            long long bv = b[(i - 1) % n + 1];
            X0[i] = run + bv;
            Y0[i] = bv - run;
            run += e[i];
        }
        SegTree st(N2);
        st.build(X0, Y0);
        auto Pt = [&](int i) -> long long { return Pref(i); };
        for (int iq = 0; iq < q; iq++) {
            int ty;
            cin >> ty;
            if (ty == 1) {
                int s, t;
                cin >> s >> t;
                long long ans;
                if (t == n + 1) {
                    long long Ps = Pt(s);
                    long long Stot = Pt(n + 1);
                    auto qx = st.query(s, s + n - 1);
                    long long cand1 = qx.x - Ps;
                    // ccw arcs: i=s degenerates (both arcs empty), exclude it
                    long long cand2 = Stot + Ps + st.query(s + 1, s + n - 1).y;
                    ans = min(cand1, cand2);
                } else {
                    long long Ps = Pt(s), Pt_ = Pt(t);
                    long long Stot = Pt(n + 1);
                    long long cw = Pt_ - Ps;
                    long long ring = min(cw, Stot - cw);
                    // hub cases
                    long long c1 = st.query(s, t - 1).x - Ps + st.query(t, s + n - 1).x - Pt_;
                    long long A2 = min(st.query(s, s).x - Ps, Pt(s + n) + st.query(t + 1, s + n - 1).y);
                    long long c2 = A2 + Pt_ + st.query(s + 1, t).y;
                    long long c3 = st.query(s, t).b + (Pt_ - Ps);
                    long long c4 = st.query(t, s + n).b + (Pt(s + n) - Pt_);
                    ans = min({ring, c1, c2, c3, c4});
                }
                cout << ans << "\n";
            } else if (ty == 2) {
                int x; long long w;
                cin >> x >> w;
                long long delta = w - a[x];
                if (delta != 0) {
                    a[x] = w;
                    fw.add(x, delta);
                    fw.add(x + n, delta);
                    st.range_add(x + 1, N2, delta);
                    st.range_add(x + n + 1, N2, delta);
                }
            } else {
                int x; long long w;
                cin >> x >> w;
                b[x] = w;
                long long Pxv = Pt(x), Pxn = Pt(x + n);
                st.point_set(x, Pxv + w, w - Pxv);
                st.point_set(x + n, Pxn + w, w - Pxn);
            }
        }
    }
    return 0;
}
