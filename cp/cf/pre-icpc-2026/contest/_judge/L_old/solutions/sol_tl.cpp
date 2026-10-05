// TL solution: correct O(n) per event. Rebuilds the duplicated prefix arrays
// and evaluates the same case decomposition by plain scans. Sum 3e5 * 3e5.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (1LL << 62);

int n, q;
vector<ll> A, B;

int vtx(int p) { return (p - 1) % n + 1; }

ll solveQuery(int s, int t) {
    int m = 2 * n;
    vector<ll> P(m + 1, 0), AA(m + 1), BB(m + 1);
    for (int i = 1; i <= m; i++) P[i] = P[i-1] + A[vtx(i)];
    for (int i = 1; i <= m; i++) { AA[i] = P[i-1] + B[vtx(i)]; BB[i] = P[i-1] - B[vtx(i)]; }
    auto minA = [&](int L, int R) { ll r = INF; for (int i = L; i <= R; i++) r = min(r, AA[i]); return r; };
    auto maxB = [&](int L, int R) { ll r = -INF; for (int i = L; i <= R; i++) r = max(r, BB[i]); return r; };
    auto pairMax = [&](int L, int R) {
        ll best = -INF, mn = INF;
        for (int j = L + 1; j <= R; j++) { mn = min(mn, AA[j-1]); best = max(best, BB[j] - mn); }
        return best;
    };
    if (t == n + 1) {
        return min(minA(s, s + n - 1) - P[s-1], P[s+n-1] - maxB(s + 1, s + n - 1));
    }
    ll cw = P[t-1] - P[s-1], tot = P[n], ccw = tot - cw;
    ll ans = min(cw, ccw);
    ll c1 = pairMax(s, t);
    if (c1 > -INF) ans = min(ans, cw - c1);
    ll c2 = pairMax(t, s + n);
    if (c2 > -INF) ans = min(ans, ccw - c2);
    if (t + 1 <= s + n - 1) {
        ans = min(ans, -P[s-1] + minA(s, t - 1) - P[t-1] + minA(t + 1, s + n - 1));
        ans = min(ans, P[s+n-1] - maxB(t + 1, s + n - 1) + P[t-1] - maxB(s + 1, t));
    }
    return ans;
}

int main() {
    int tc; scanf("%d", &tc);
    while (tc--) {
        scanf("%d %d", &n, &q);
        A.assign(n + 1, 0); B.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) scanf("%lld", &A[i]);
        for (int i = 1; i <= n; i++) scanf("%lld", &B[i]);
        for (int e = 0; e < q; e++) {
            int tp; scanf("%d", &tp);
            if (tp == 1) {
                int s, t; scanf("%d %d", &s, &t);
                printf("%lld\n", solveQuery(s, t));
            } else if (tp == 2) {
                int x; ll w; scanf("%d %lld", &x, &w); A[x] = w;
            } else {
                int x; ll w; scanf("%d %lld", &x, &w); B[x] = w;
            }
        }
    }
    return 0;
}
