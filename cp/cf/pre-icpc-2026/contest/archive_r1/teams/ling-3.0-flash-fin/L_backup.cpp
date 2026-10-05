#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

struct SegTree {
    int n;
    vector<ll> tree, lazy;
    SegTree() : n(0) {}
    SegTree(int n) : n(n), tree(4*n, INF), lazy(4*n, 0) {}
    void push(int node) {
        if (lazy[node]) {
            tree[2*node] += lazy[node]; lazy[2*node] += lazy[node];
            tree[2*node+1] += lazy[node]; lazy[2*node+1] += lazy[node];
            lazy[node] = 0;
        }
    }
    void _update(int nd, int lo, int hi, int l, int r, ll v) {
        if (r < lo || hi < l) return;
        if (l <= lo && hi <= r) { tree[nd] += v; lazy[nd] += v; return; }
        push(nd); int mid = (lo+hi)/2;
        _update(2*nd, lo, mid, l, r, v); _update(2*nd+1, mid+1, hi, l, r, v);
        tree[nd] = min(tree[2*nd], tree[2*nd+1]);
    }
    void update(int l, int r, ll v) { if (l <= r) _update(1, 1, n, l, r, v); }
    ll _query(int nd, int lo, int hi, int l, int r) {
        if (r < lo || hi < l) return INF;
        if (l <= lo && hi <= r) return tree[nd];
        push(nd); int mid = (lo+hi)/2;
        return min(_query(2*nd, lo, mid, l, r), _query(2*nd+1, mid+1, hi, l, r));
    }
    ll query(int l, int r) { return (l > r) ? INF : _query(1, 1, n, l, r); }
    void set(int pos, ll v) {
        ll cur = query(pos, pos);
        update(pos, pos, v - cur);
    }
};

struct Fenwick {
    int n; vector<ll> bit;
    Fenwick(int n) : n(n), bit(n+1, 0) {}
    void update(int i, ll d) { for (; i <= n; i += i&(-i)) bit[i] += d; }
    ll query(int i) { ll s = 0; for (; i > 0; i -= i&(-i)) s += bit[i]; return s; }
};

int main(){
    int t; scanf("%d", &t);
    while (t--) {
        int n, q; scanf("%d%d", &n, &q);
        vector<ll> a(n+1), b(n+1);
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
        
        Fenwick fenw(n);
        for (int i = 1; i <= n; i++) fenw.update(i, a[i]);
        auto getQ = [&](int i) -> ll { return i <= 0 ? 0 : fenw.query(i); };
        ll total = getQ(n);
        
        SegTree segA(n), segB(n);
        for (int i = 1; i <= n; i++) {
            ll qim1 = getQ(i-1);
            segA.set(i, qim1 + b[i]);
            segB.set(i, -qim1 + b[i]);
        }
        
        auto getCW = [&](int s, int t) -> ll {
            if (s == t) return 0;
            if (t > s) return getQ(t-1) - getQ(s-1);
            return total - getQ(s-1) + getQ(t-1);
        };
        
        while (q--) {
            int type; scanf("%d", &type);
            if (type == 1) {
                int s, tt; scanf("%d%d", &s, &tt);
                if (tt == n+1) {
                    ll ans = b[s];
                    ll qs1 = getQ(s-1);
                    if (s > 1) {
                        ans = min(ans, -qs1 + segA.query(1, s-1));
                        ans = min(ans, qs1 + segB.query(1, s-1));
                    }
                    if (s < n) {
                        ans = min(ans, -qs1 + segA.query(s+1, n));
                        ans = min(ans, qs1 + total + segB.query(s+1, n));
                    }
                    printf("%lld\n", ans);
                } else {
                    int t = tt;
                    ll cw = getCW(s, t);
                    ll ccw = total - cw;
                    ll direct = b[s] + b[t];
                    ll qs1 = getQ(s-1), qt1 = getQ(t-1);
                    
                    ll path4 = INF;
                    ll mA_cw = segA.query(s, t-1);
                    if (mA_cw < INF) {
                        ll p4_1 = -qs1 + mA_cw;
                        ll mA_c1 = segA.query(t, n);
                        ll mA_c2 = segA.query(1, s-1);
                        ll p4_2 = min(-qt1 + mA_c1, total + qt1 + mA_c2);
                        path4 = p4_1 + p4_2;
                    }
                    
                    ll path5 = INF;
                    {
                        ll mB_c1 = segB.query(t, n);
                        ll mB_c2 = segB.query(1, s-1);
                        ll p5_cw = qs1 + min(mB_c1, mB_c2);
                        ll mB_w = segB.query(s, t-1);
                        ll p5_ccw = qt1 + mB_w;
                        path5 = p5_cw + p5_ccw;
                    }
                    
                    ll ans = min({cw, ccw, direct, path4, path5});
                    printf("%lld\n", ans);
                }
            } else if (type == 2) {
                int x; ll w; scanf("%d%lld", &x, &w);
                ll delta = w - a[x];
                a[x] = w; fenw.update(x, delta); total += delta;
                if (x + 1 <= n) { segA.update(x+1, n, delta); segB.update(x+1, n, -delta); }
            } else {
                int x; ll w; scanf("%d%lld", &x, &w);
                ll qim1 = getQ(x-1); b[x] = w;
                segA.set(x, qim1 + w);
                segB.set(x, -qim1 + w);
            }
        }
    }
}
