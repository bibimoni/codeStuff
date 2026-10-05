// L - The Coral Loop
// Wheel graph: cycle of n islands with weights a_i, plus Nook joined to all with b_i.
// Simple path s -> t. Either cycle-only (2 arcs), or uses the Nook once:
//   v_s ->[up/down arc]-> x ->(b_x)-> Nook ->(b_y)-> y ->[arc]-> v_t.
// All cost forms reduce to sums of  Up_i = b_i - Pp(i)  and  Vp_i = b_i + Pp(i),
// where Pp(i) = prefix sum of the doubled a-array before index i (0-indexed).
// Segment tree over the doubled array (2n leaves), node values relative to node start:
//   sum, minUp, minVp, ord = min_{i<j}(Vp_i + Up_j)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const ll INF = 2000000000000000000LL;

struct Node {
    ll sum, minUp, minVp, ord;
};

static inline Node mg(const Node &L, const Node &R) {
    Node r;
    r.sum = L.sum + R.sum;
    r.minUp = L.minUp;
    ll t = R.minUp - L.sum;
    if (t < r.minUp) r.minUp = t;
    r.minVp = L.minVp;
    t = R.minVp + L.sum;
    if (t < r.minVp) r.minVp = t;
    r.ord = min(min(L.ord, R.ord), L.minVp + R.minUp - L.sum);
    return r;
}

int base;
vector<Node> seg;

static inline void setLeaf(int p, ll a, ll b) { seg[base + p] = Node{a, b, b, INF}; }
static void build() {
    for (int i = base - 1; i >= 1; i--) seg[i] = mg(seg[2 * i], seg[2 * i + 1]);
}
static void upd(int p) {
    for (p = (base + p) >> 1; p; p >>= 1) seg[p] = mg(seg[2 * p], seg[2 * p + 1]);
}
// values relative to prefix Pp(l)
static Node qry(int l, int r) {
    if (l > r) return Node{0, INF, INF, INF};
    Node A{0, INF, INF, INF}, B{0, INF, INF, INF};
    for (l += base, r += base + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) A = mg(A, seg[l++]);
        if (r & 1) B = mg(seg[--r], B);
    }
    return mg(A, B);
}
static ll qrySum(int l, int r) {
    if (l > r) return 0;
    ll s = 0;
    for (l += base, r += base + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) s += seg[l++].sum;
        if (r & 1) s += seg[--r].sum;
    }
    return s;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, q;
        scanf("%d %d", &n, &q);
        vector<ll> a(n), b(n);
        for (auto &x : a) scanf("%lld", &x);
        for (auto &x : b) scanf("%lld", &x);
        base = 1;
        while (base < 2 * n) base <<= 1;
        seg.assign(2 * base, Node{0, INF, INF, INF});
        for (int i = 0; i < n; i++) { setLeaf(i, a[i], b[i]); setLeaf(i + n, a[i], b[i]); }
        build();
        while (q--) {
            int type;
            scanf("%d", &type);
            if (type == 2 || type == 3) {
                int x;
                ll w;
                scanf("%d %lld", &x, &w);
                --x;
                if (type == 2) a[x] = w; else b[x] = w;
                setLeaf(x, a[x], b[x]);
                setLeaf(x + n, a[x], b[x]);
                upd(x);
                upd(x + n);
            } else {
                int s, t;
                scanf("%d %d", &s, &t);
                --s;
                --t;
                ll ans;
                if (t == n) {  // t is the Nook
                    Node r = qry(s + 1, s + n - 1);
                    ll A = r.sum;  // sum over the whole arc except s
                    ans = min(b[s], min(r.minVp + a[s], r.minUp + A));
                } else {
                    ll Ps = qrySum(0, s - 1);
                    Node n1 = qry(s, t - 1);                 // arc1
                    ll A1 = n1.sum, Pt1 = Ps + A1;
                    ll A2 = qrySum(t, s + n - 1), Psn1 = Pt1 + A2;
                    Node n2 = qry(t, s + n - 1);             // arc2
                    ll U1 = n1.minUp - Ps, V1 = n1.minVp + Ps;
                    ll U2 = n2.minUp - Pt1, V2 = n2.minVp + Pt1;
                    Node m1 = qry(s + 1, t - 1);            // arc1 minus s
                    Node m2 = qry(t + 1, s + n - 1);        // arc2 minus t
                    ll U1b = m1.minUp - (Ps + a[s]), U2b = m2.minUp - (Pt1 + a[t]);
                    ans = min(A1, A2);
                    ans = min(ans, V1 - Ps + b[t]);
                    ans = min(ans, b[s] + Pt1 + U1b);
                    ans = min(ans, Psn1 + b[t] + U2b);
                    ans = min(ans, b[s] - Pt1 + V2);
                    ans = min(ans, V1 + V2 - Ps - Pt1);
                    ans = min(ans, Psn1 + Pt1 + U1b + U2b);
                    ans = min(ans, A1 + n1.ord);
                    ans = min(ans, A2 + n2.ord);
                }
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}
