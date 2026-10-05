#include <bits/stdc++.h>
using namespace std;

const long long INF = (1LL << 62);
struct Node { long long x, y, pair; };

struct SegTree {
    int n;
    vector<Node> tree;
    vector<long long> lx, ly;
    SegTree(const vector<long long> &x, const vector<long long> &y) : n((int)x.size() - 1), tree(4 * n), lx(4 * n), ly(4 * n) { build(1, 1, n, x, y); }
    Node merge(Node a, Node b) { return {min(a.x, b.x), min(a.y, b.y), min({a.pair, b.pair, a.x + b.y})}; }
    void build(int p, int l, int r, const vector<long long> &x, const vector<long long> &y) {
        if (l == r) { tree[p] = {x[l], y[l], INF}; return; }
        int m = (l + r) / 2;
        build(p * 2, l, m, x, y); build(p * 2 + 1, m + 1, r, x, y);
        tree[p] = merge(tree[p * 2], tree[p * 2 + 1]);
    }
    void apply(int p, long long dx, long long dy) {
        tree[p].x += dx; tree[p].y += dy;
        if (tree[p].pair < INF) tree[p].pair += dx + dy;
        lx[p] += dx; ly[p] += dy;
    }
    void push(int p) { if (lx[p] || ly[p]) { apply(p * 2, lx[p], ly[p]); apply(p * 2 + 1, lx[p], ly[p]); lx[p] = ly[p] = 0; } }
    void add(int p, int l, int r, int ql, int qr, long long dx, long long dy) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) { apply(p, dx, dy); return; }
        push(p); int m = (l + r) / 2;
        add(p * 2, l, m, ql, qr, dx, dy); add(p * 2 + 1, m + 1, r, ql, qr, dx, dy);
        tree[p] = merge(tree[p * 2], tree[p * 2 + 1]);
    }
    Node get(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[p];
        push(p); int m = (l + r) / 2;
        if (qr <= m) return get(p * 2, l, m, ql, qr);
        if (ql > m) return get(p * 2 + 1, m + 1, r, ql, qr);
        return merge(get(p * 2, l, m, ql, qr), get(p * 2 + 1, m + 1, r, ql, qr));
    }
    void add(int l, int r, long long dx, long long dy) { if (l <= r) add(1, 1, n, l, r, dx, dy); }
    Node get(int l, int r) { return get(1, 1, n, l, r); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin >> tests;
    while (tests--) {
        int n, q;
        cin >> n >> q;
        vector<long long> a(n + 1), b(n + 1), pos(2 * n + 1), x(2 * n + 1), y(2 * n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];
        for (int i = 2; i <= n; ++i) pos[i] = pos[i - 1] + a[i - 1];
        long long cycle = pos[n] + a[n];
        for (int i = 1; i <= n; ++i) pos[n + i] = pos[i] + cycle;
        for (int i = 1; i <= 2 * n; ++i) x[i] = b[(i - 1) % n + 1] + pos[i], y[i] = b[(i - 1) % n + 1] - pos[i];
        SegTree st(x, y);
        while (q--) {
            int type, u;
            long long v;
            cin >> type >> u >> v;
            if (type == 2) {
                long long delta = v - a[u]; a[u] = v;
                st.add(u + 1, n, delta, -delta);
                st.add(n + 1, n + u, delta, -delta);
                st.add(n + u + 1, 2 * n, 2 * delta, -2 * delta);
                cycle += delta;
            } else if (type == 3) {
                long long delta = v - b[u]; b[u] = v;
                st.add(u, u, delta, delta); st.add(n + u, n + u, delta, delta);
            } else {
                int s = u, t = (int)v;
                auto coordinate = [&](int index) { return st.get(index, index).x - b[(index - 1) % n + 1]; };
                long long ps = coordinate(s), psn = coordinate(s + n);
                if (t == n + 1) {
                    Node clockwise = st.get(s, s + n - 1), counter = st.get(s + 1, s + n);
                    cout << min(clockwise.x - ps, counter.y + psn) << '\n';
                    continue;
                }
                long long pt = coordinate(t);
                Node direct = st.get(s, t), around = st.get(t, s + n);
                long long ans = min(pt - ps, psn - pt);
                ans = min(ans, pt - ps + direct.pair);
                ans = min(ans, psn - pt + around.pair);
                ans = min(ans, st.get(s, t - 1).x + st.get(t, s + n - 1).x - ps - pt);
                ans = min(ans, st.get(t + 1, s + n).y + st.get(s + 1, t).y + psn + pt);
                cout << ans << '\n';
            }
        }
    }
}
