#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 4000000000000000000LL;

ll add(ll x, ll y) {
    return x >= INF / 2 || y >= INF / 2 ? INF : x + y;
}

struct Agg {
    ll sum = 0, fromStart = INF, fromEnd = INF;
    ll startExceptEnd = INF, endExceptStart = INF, pairCost = INF;
};

Agg join(const Agg &left, const Agg &right, ll edge) {
    Agg z;
    z.sum = left.sum + edge + right.sum;
    z.fromStart = min(left.fromStart, add(left.sum + edge, right.fromStart));
    z.fromEnd = min(right.fromEnd, add(right.sum + edge, left.fromEnd));
    z.startExceptEnd = min(left.fromStart, add(left.sum + edge, right.startExceptEnd));
    z.endExceptStart = min(right.fromEnd, add(right.sum + edge, left.endExceptStart));
    z.pairCost = min({add(left.pairCost, edge + right.sum),
                      add(right.pairCost, left.sum + edge),
                      add(left.fromStart, right.fromEnd)});
    return z;
}

struct Item {
    Agg value;
    int left = -1, right = -1;
    bool empty() const { return left == -1; }
};

struct SegmentTree {
    int n;
    vector<ll> &cycle, &spoke;
    vector<Agg> tree;
    SegmentTree(vector<ll> &a, vector<ll> &b) : n(a.size()), cycle(a), spoke(b), tree(4 * n) { build(1, 0, n - 1); }
    Agg leaf(int i) {
        Agg z;
        z.fromStart = z.fromEnd = spoke[i];
        return z;
    }
    void build(int node, int l, int r) {
        if (l == r) { tree[node] = leaf(l); return; }
        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        tree[node] = join(tree[node * 2], tree[node * 2 + 1], cycle[mid]);
    }
    void update(int node, int l, int r, int position) {
        if (l == r) { tree[node] = leaf(l); return; }
        int mid = (l + r) / 2;
        if (position <= mid) update(node * 2, l, mid, position);
        else update(node * 2 + 1, mid + 1, r, position);
        tree[node] = join(tree[node * 2], tree[node * 2 + 1], cycle[mid]);
    }
    void updateSpoke(int position, ll value) {
        spoke[position] = value;
        update(1, 0, n - 1, position);
    }
    void updateCycle(int position, ll value) {
        cycle[position] = value;
        if (position + 1 < n) update(1, 0, n - 1, position);
    }
    Item combine(Item a, Item b) {
        if (a.empty()) return b;
        if (b.empty()) return a;
        return {join(a.value, b.value, cycle[a.right]), a.left, b.right};
    }
    Item query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return {};
        if (ql <= l && r <= qr) return {tree[node], l, r};
        int mid = (l + r) / 2;
        return combine(query(node * 2, l, mid, ql, qr), query(node * 2 + 1, mid + 1, r, ql, qr));
    }
    Item query(int l, int r) { return query(1, 0, n - 1, l, r); }
    Item clockwise(int l, int r) {
        if (l <= r) return query(l, r);
        Item first = query(l, n - 1), second = query(0, r);
        return {join(first.value, second.value, cycle[n - 1]), l, r};
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
        vector<ll> a(n), b(n);
        for (ll &x : a) cin >> x;
        for (ll &x : b) cin >> x;
        SegmentTree tree(a, b);
        while (q--) {
            int type, x;
            ll y;
            cin >> type >> x >> y;
            --x;
            if (type == 2) tree.updateCycle(x, y);
            else if (type == 3) tree.updateSpoke(x, y);
            else {
                int s = x, t = (int)y - 1;
                if (t == n) {
                    Agg clockwise = tree.clockwise(s, (s + n - 1) % n).value;
                    Agg counterclockwise = tree.clockwise((s + 1) % n, s).value;
                    cout << min(clockwise.fromStart, counterclockwise.fromEnd) << '\n';
                } else {
                    Agg first = tree.clockwise(s, t).value;
                    Agg second = tree.clockwise(t, s).value;
                    ll answer = min({first.sum, second.sum, first.pairCost, second.pairCost,
                                     add(first.startExceptEnd, second.startExceptEnd),
                                     add(first.endExceptStart, second.endExceptStart)});
                    cout << answer << '\n';
                }
            }
        }
    }
}
