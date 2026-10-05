#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (ll)4e18;

struct BIT {
    int N;
    vector<ll> t;
    void init(int n) { N = n; t.assign(n + 2, 0); }
    void add(int i, ll v) { for (; i <= N; i += i & -i) t[i] += v; }
    ll sum(int i) { ll r = 0; for (; i > 0; i -= i & -i) r += t[i]; return r; }
} bit;

struct Seg {
    int N;
    vector<ll> mnCX, mnDY, pr, lzC, lzD;
    struct Res { ll cx, dy, pr; };
    void init(int n) {
        N = n;
        mnCX.assign(4 * n + 8, 0); mnDY.assign(4 * n + 8, 0);
        pr.assign(4 * n + 8, INF); lzC.assign(4 * n + 8, 0); lzD.assign(4 * n + 8, 0);
    }
    void apply(int p, ll vc, ll vd) {
        mnCX[p] += vc; mnDY[p] += vd; pr[p] += vc + vd;
        lzC[p] += vc; lzD[p] += vd;
    }
    void push(int p) {
        if (lzC[p] || lzD[p]) {
            apply(p * 2, lzC[p], lzD[p]); apply(p * 2 + 1, lzC[p], lzD[p]);
            lzC[p] = lzD[p] = 0;
        }
    }
    void pull(int p) {
        mnCX[p] = min(mnCX[p * 2], mnCX[p * 2 + 1]);
        mnDY[p] = min(mnDY[p * 2], mnDY[p * 2 + 1]);
        pr[p] = min({pr[p * 2], pr[p * 2 + 1], mnCX[p * 2] + mnDY[p * 2 + 1]});
    }
    void build(int p, int l, int r, vector<ll> &b) {
        if (l == r) {
            ll pf = bit.sum(l - 1);
            mnCX[p] = pf + b[l];
            mnDY[p] = b[l] - pf;
            pr[p] = INF;
            return;
        }
        int m = (l + r) / 2;
        build(p * 2, l, m, b); build(p * 2 + 1, m + 1, r, b);
        pull(p);
    }
    void rangeAdd(int p, int l, int r, int ql, int qr, ll vc, ll vd) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) { apply(p, vc, vd); return; }
        push(p);
        int m = (l + r) / 2;
        rangeAdd(p * 2, l, m, ql, qr, vc, vd);
        rangeAdd(p * 2 + 1, m + 1, r, ql, qr, vc, vd);
        pull(p);
    }
    Res query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return {mnCX[p], mnDY[p], pr[p]};
        push(p);
        int m = (l + r) / 2;
        if (qr <= m) return query(p * 2, l, m, ql, qr);
        if (ql > m) return query(p * 2 + 1, m + 1, r, ql, qr);
        Res L = query(p * 2, l, m, ql, qr), R = query(p * 2 + 1, m + 1, r, ql, qr);
        return {min(L.cx, R.cx), min(L.dy, R.dy), min({L.pr, R.pr, L.cx + R.dy})};
    }
    void upd(int l, int r, ll vc, ll vd) { if (l <= r) rangeAdd(1, 1, N, l, r, vc, vd); }
    Res get(int l, int r) { if (l > r) return {INF, INF, INF}; return query(1, 1, N, l, r); }
} seg;

int main() {
    int T;
    scanf("%d", &T);
    string out;
    out.reserve(1 << 22);
    while (T--) {
        int n, q;
        scanf("%d %d", &n, &q);
        vector<ll> a(n + 1), b(n + 1);
        bit.init(n);
        for (int i = 1; i <= n; i++) { scanf("%lld", &a[i]); bit.add(i, a[i]); }
        for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
        seg.init(n);
        seg.build(1, 1, n, b);
        while (q--) {
            int ty;
            scanf("%d", &ty);
            if (ty == 1) {
                int s, t;
                scanf("%d %d", &s, &t);
                ll pref_s1 = bit.sum(s - 1);
                ll ans = INF;
                if (t == n + 1) {
                    ans = min(ans, pref_s1 + seg.get(1, s).dy);
                    if (1 <= s - 1)
                        ans = min(ans, bit.sum(n) - pref_s1 + seg.get(1, s - 1).cx);
                    ans = min(ans, seg.get(s, n).cx - pref_s1);
                    if (s + 1 <= n)
                        ans = min(ans, bit.sum(n) + pref_s1 + seg.get(s + 1, n).dy);
                } else {
                    ll pref_t1 = bit.sum(t - 1);
                    ll pref_n = bit.sum(n);
                    ans = min(ans, pref_t1 - pref_s1);
                    ans = min(ans, pref_n - pref_t1 + pref_s1);
                    ans = min(ans, seg.get(s, t).pr - pref_s1 + pref_t1);
                    if (s <= t - 1 && t + 1 <= n)
                        ans = min(ans, seg.get(s, t - 1).cx + seg.get(t + 1, n).cx - pref_s1 - pref_t1);
                    if (s <= t - 1 && 1 <= s - 1)
                        ans = min(ans, seg.get(s, t - 1).cx + seg.get(1, s - 1).cx - pref_s1 + pref_n - pref_t1);
                    if (1 <= s - 1 && s + 1 <= t)
                        ans = min(ans, pref_s1 + pref_t1 + seg.get(1, s - 1).dy + seg.get(s + 1, t).dy);
                    if (t + 1 <= n && s + 1 <= t)
                        ans = min(ans, pref_s1 + pref_t1 + pref_n + seg.get(t + 1, n).dy + seg.get(s + 1, t).dy);
                    if (1 <= s - 1 && t + 1 <= n)
                        ans = min(ans, pref_s1 - pref_t1 + seg.get(1, s - 1).dy + seg.get(t + 1, n).cx);
                    if (1 <= s - 1)
                        ans = min(ans, pref_s1 + pref_n - pref_t1 + seg.get(1, s - 1).pr);
                    if (t + 1 <= n)
                        ans = min(ans, pref_s1 + pref_n - pref_t1 + seg.get(t + 1, n).pr);
                }
                out += to_string(ans);
                out += '\n';
            } else if (ty == 2) {
                int x; ll w;
                scanf("%d %lld", &x, &w);
                ll d = w - a[x];
                a[x] = w;
                bit.add(x, d);
                seg.upd(x + 1, n, d, -d);
            } else {
                int x; ll w;
                scanf("%d %lld", &x, &w);
                ll d = w - b[x];
                b[x] = w;
                seg.upd(x, x, d, d);
            }
        }
    }
    fwrite(out.data(), 1, out.size(), stdout);
    return 0;
}
