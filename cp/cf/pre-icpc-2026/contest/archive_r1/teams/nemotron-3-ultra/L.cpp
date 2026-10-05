#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (1LL<<60);

struct Node {
    ll minX, minY, minXY;
    ll lazyX, lazyY;
    Node(): minX(INF), minY(INF), minXY(INF), lazyX(0), lazyY(0) {}
    Node(ll x, ll y): minX(x), minY(y), minXY(INF), lazyX(0), lazyY(0) {}
};

Node combine(const Node& L, const Node& R) {
    if (L.minX == INF) return R;
    if (R.minX == INF) return L;
    Node res;
    res.minX = min(L.minX, R.minX);
    res.minY = min(L.minY, R.minY);
    res.minXY = min({L.minXY, R.minXY, L.minX + R.minY});
    return res;
}

struct SegTree {
    int n;
    vector<Node> t;
    SegTree(int _n=0) { init(_n); }
    void init(int _n) {
        n = _n;
        t.assign(4*n+4, Node());
    }
    void build(int v, int l, int r, const vector<ll>& X, const vector<ll>& Y) {
        t[v].lazyX = t[v].lazyY = 0;
        if (l == r) {
            t[v] = Node(X[l], Y[l]);
            return;
        }
        int m = (l+r)/2;
        build(2*v, l, m, X, Y);
        build(2*v+1, m+1, r, X, Y);
        t[v] = combine(t[2*v], t[2*v+1]);
    }
    void build(const vector<ll>& X, const vector<ll>& Y) {
        build(1, 1, n, X, Y);
    }
    void apply(int v, ll dx, ll dy) {
        if (t[v].minX == INF) return;
        t[v].minX += dx;
        t[v].minY += dy;
        t[v].minXY += dx + dy;
        t[v].lazyX += dx;
        t[v].lazyY += dy;
    }
    void push(int v) {
        if (t[v].lazyX != 0 || t[v].lazyY != 0) {
            apply(2*v, t[v].lazyX, t[v].lazyY);
            apply(2*v+1, t[v].lazyX, t[v].lazyY);
            t[v].lazyX = t[v].lazyY = 0;
        }
    }
    void range_add(int v, int l, int r, int ql, int qr, ll dx, ll dy) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            apply(v, dx, dy);
            return;
        }
        push(v);
        int m = (l+r)/2;
        range_add(2*v, l, m, ql, qr, dx, dy);
        range_add(2*v+1, m+1, r, ql, qr, dx, dy);
        t[v] = combine(t[2*v], t[2*v+1]);
    }
    void range_add(int l, int r, ll dx, ll dy) {
        if (l > r) return;
        range_add(1, 1, n, l, r, dx, dy);
    }
    void point_add(int v, int l, int r, int idx, ll dx, ll dy) {
        if (l == r) {
            apply(v, dx, dy);
            return;
        }
        push(v);
        int m = (l+r)/2;
        if (idx <= m) point_add(2*v, l, m, idx, dx, dy);
        else point_add(2*v+1, m+1, r, idx, dx, dy);
        t[v] = combine(t[2*v], t[2*v+1]);
    }
    void point_add(int idx, ll dx, ll dy) {
        point_add(1, 1, n, idx, dx, dy);
    }
    Node query(int v, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return Node();
        if (ql <= l && r <= qr) return t[v];
        push(v);
        int m = (l+r)/2;
        Node left = query(2*v, l, m, ql, qr);
        Node right = query(2*v+1, m+1, r, ql, qr);
        return combine(left, right);
    }
    Node query(int l, int r) {
        if (l > r) return Node();
        return query(1, 1, n, l, r);
    }
    ll query_minX(int l, int r) {
        Node res = query(l, r);
        return res.minX;
    }
    ll query_minY(int l, int r) {
        Node res = query(l, r);
        return res.minY;
    }
    ll query_minXY(int l, int r) {
        Node res = query(l, r);
        return res.minXY;
    }
};

struct Fenwick {
    int n;
    vector<ll> bit;
    Fenwick(int _n=0) { init(_n); }
    void init(int _n) { n = _n; bit.assign(n+1, 0); }
    void add(int idx, ll val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }
    ll sum(int idx) {
        ll res = 0;
        for (; idx > 0; idx -= idx & -idx) res += bit[idx];
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<ll> a(n+1), b(n+1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];
        
        int N2 = 2*n;
        vector<ll> A(N2+1), B(N2+1);
        for (int i = 1; i <= N2; ++i) {
            A[i] = a[(i-1)%n + 1];
            B[i] = b[(i-1)%n + 1];
        }
        vector<ll> P(N2+1, 0);
        for (int i = 1; i <= N2; ++i) P[i] = P[i-1] + A[i];
        
        vector<ll> X(N2+1), Y(N2+1);
        for (int i = 1; i <= N2; ++i) {
            X[i] = P[i-1] + B[i];
            Y[i] = B[i] - P[i-1];
        }
        
        Fenwick fw(n);
        for (int i = 1; i <= n; ++i) fw.add(i, a[i]);
        
        SegTree seg(N2);
        seg.build(X, Y);
        
        while (q--) {
            int type;
            cin >> type;
            if (type == 1) {
                int s, t;
                cin >> s >> t;
                if (t == n+1) { // s to Nook
                    ll Ps = fw.sum(s-1);
                    ll total = fw.sum(n);
                    // cw: min_{u in [s, s+n-1]} X[u] - Ps
                    ll minX_cw = seg.query_minX(s, s+n-1);
                    ll ans_cw = minX_cw - Ps;
                    // ccw: Ps + min( min_{u in [1,s]} Y[u], total + min_{u in [s+1, s+n]} Y[u] )
                    ll minY1 = seg.query_minY(1, s);
                    ll minY2 = seg.query_minY(s+1, s+n);
                    ll ans_ccw = Ps + min(minY1, total + minY2);
                    ll ans = min({b[s], ans_cw, ans_ccw});
                    cout << ans << "\n";
                } else { // s to t, both islands
                    ll Ps = fw.sum(s-1);
                    ll Pt = fw.sum(t-1);
                    ll total = fw.sum(n);
                    ll cw_dist = Pt - Ps;
                    ll ccw_dist = total - cw_dist;
                    
                    // Config 1: both on arc A (s..t), s->u cw, v->t ccw
                    ll minXY_cw = seg.query_minXY(s, t);
                    ll ans1 = cw_dist + minXY_cw;
                    
                    // Config 2: both on arc B (t..s+n), s->u ccw, v->t ccw
                    ll minXY_ccw = seg.query_minXY(t, s+n);
                    ll ans2 = ccw_dist + minXY_ccw;
                    
                    // Config 3: s->u cw on arc A, v->t ccw on arc B
                    // u in [s, t-1], v_dup in [t, s+n-1]
                    // cost = minX[s,t-1] + minX[t,s+n-1] - Ps - Pt
                    ll minX_s_t1 = seg.query_minX(s, t-1);
                    ll minX_t_sn1 = seg.query_minX(t, s+n-1);
                    ll ans3 = minX_s_t1 + minX_t_sn1 - Ps - Pt;
                    
                    // Config 4: s->u ccw on arc B, v->t cw on arc A
                    // u_dup in [t+1, s+n], v in [s+1, t]
                    // cost = total + Ps + Pt + minY[s+1,t] + min( minY[t+1,n], minY[1,s] - total )
                    ll minY_s1_t = seg.query_minY(s+1, t);
                    ll minY_t1_n = seg.query_minY(t+1, n);
                    ll minY_1_s = seg.query_minY(1, s);
                    ll minY_t1_s = min(minY_t1_n, minY_1_s - total);
                    ll ans4 = total + Ps + Pt + minY_s1_t + minY_t1_s;
                    
                    ll ans = min({cw_dist, ccw_dist, ans1, ans2, ans3, ans4});
                    cout << ans << "\n";
                }
            } else if (type == 2) {
                int x; ll w;
                cin >> x >> w;
                ll delta = w - a[x];
                a[x] = w;
                fw.add(x, delta);
                // X: [x+1, x+n] += delta; [x+n+1, 2n] += 2*delta
                // Y: [x+1, x+n] -= delta; [x+n+1, 2n] -= 2*delta
                seg.range_add(x+1, x+n, delta, -delta);
                if (x+n+1 <= N2) seg.range_add(x+n+1, N2, 2*delta, -2*delta);
            } else if (type == 3) {
                int x; ll w;
                cin >> x >> w;
                ll delta = w - b[x];
                b[x] = w;
                seg.point_add(x, delta, delta);
                seg.point_add(x+n, delta, delta);
            }
        }
    }
    return 0;
}