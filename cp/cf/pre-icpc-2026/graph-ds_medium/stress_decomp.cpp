// Stress: prove the 4-case decomposition of shortest simple path on
// ring(a[1..n]) + hub(n+1, spokes b[i]) with point updates.
// brute = DFS over all simple paths; formula = case decomposition via
// plain O(n) scans over duplicated prefix arrays. Mismatch -> dump state.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL << 60);

int n;
ll A[12], B[12]; // ring edges, spokes; vertices 1..n, hub = n+1

vector<vector<pair<int,ll>>> buildGraph() {
    vector<vector<pair<int,ll>>> g(n + 2);
    for (int i = 1; i <= n; i++) {
        int j = i % n + 1;
        g[i].push_back({j, A[i]}); g[j].push_back({i, A[i]});
    }
    for (int i = 1; i <= n; i++) {
        g[i].push_back({n + 1, B[i]}); g[n +1].push_back({i, B[i]});
    }
    return g;
}

ll bestAns;
void dfs(int u, int t, ll d, const vector<vector<pair<int,ll>>>& g, vector<char>& vis) {
    if (u == t) { bestAns = min(bestAns, d); return; }
    for (auto [v, w] : g[u]) if (!vis[v]) {
        vis[v] = 1; dfs(v, t, d + w, g, vis); vis[v] = 0;
    }
}
ll brute(int s, int t) {
    auto g = buildGraph();
    bestAns = INF;
    vector<char> vis(n + 2, 0); vis[s] = 1;
    dfs(s, t, 0, g, vis);
    return bestAns;
}

// ---- formula ----
// dup[i] = A[((i-1)%n)+1], i=1..2n ; P prefix sums; AA/BB per dup position.
ll P[30], AA[30], BB[30];
int vtx(int p) { return (p - 1) % n + 1; }
void buildDup() {
    P[0] = 0;
    for (int i = 1; i <= 2 * n; i++) P[i] = P[i-1] + A[vtx(i)];
    for (int i = 1; i <= 2 * n; i++) { AA[i] = P[i-1] + B[vtx(i)]; BB[i] = P[i-1] - B[vtx(i)]; }
}
ll minA(int L, int R) { ll r = INF; for (int i = L; i <= R; i++) r = min(r, AA[i]); return r; }
ll maxB(int L, int R) { ll r = -INF; for (int i = L; i <= R; i++) r = max(r, BB[i]); return r; }
ll pairMax(int L, int R) { // max over L<=k<j<=R of BB[j]-AA[k]
    ll best = -INF, mn = INF;
    for (int j = L + 1; j <= R; j++) { mn = min(mn, AA[j-1]); best = max(best, BB[j] - mn); }
    return best;
}
ll formula(int s, int t) {
    buildDup();
    if (t == n + 1) {
        ll r1 = minA(s, s + n - 1) - P[s-1];
        ll r2 = P[s+n-1] - maxB(s + 1, s + n - 1); // p=s would be a full loop back to s (not simple)
        return min(r1, r2);
    }
    ll cw = P[t-1] - P[s-1], tot = P[n], ccw = tot - cw;
    ll ans = min(cw, ccw);
    if (t - s >= 2 || true) { // pair needs >=2 positions in [s,t]
        ll c1 = pairMax(s, t);
        if (c1 > -INF) ans = min(ans, cw - c1);
    }
    { // mirrored pair over cyclic complement
        ll c2 = pairMax(t, s + n);
        if (c2 > -INF) ans = min(ans, ccw - c2);
    }
    { // k in [s,t-1], j in cyclic (t,s): both via minA
        ll r1 = minA(s, t - 1), r2 = (t + 1 <= s + n - 1) ? minA(t + 1, s + n - 1) : INF;
        if (r1 < INF && r2 < INF) ans = min(ans, -P[s-1] + r1 - P[t-1] + r2);
    }
    { // k in cyclic (t,s), j in (s,t]: both via maxB
        ll r1 = (t + 1 <= s + n - 1) ? maxB(t + 1, s + n - 1) : -INF;
        ll r2 = maxB(s + 1, t);
        if (r1 > -INF && r2 > -INF) ans = min(ans, P[s+n-1] - r1 + P[t-1] - r2);
    }
    return ans;
}

int main(int argc, char** argv) {
    uint64_t seed = argc > 1 ? stoull(argv[1]) : 1;
    mt19937_64 rng(seed);
    int graphs = argc > 2 ? atoi(argv[2]) : 40000;
    for (int gno = 1; gno <= graphs; gno++) {
        n = 2 + rng() % 6;                    // 2..7
        int wlo = (gno % 2 ? -9 : -5), whi = (gno % 2 ? 2 : 5); // alternate negative-heavy
        for (int i = 1; i <= n; i++) A[i] = wlo + (ll)(rng() % (whi - wlo + 1));
        for (int i = 1; i <= n; i++) B[i] = wlo + (ll)(rng() % (whi - wlo + 1));
        int events = 20;
        for (int e = 0; e < events; e++) {
            int type = rng() % 2 ? (rng() % 2 ? 2 : 3) : 1;
            if (type == 1) {
                int s = 1 + rng() % (n + 1), t = 1 + rng() % (n + 1);
                if (s == t) continue;
                if (s > t) swap(s, t);
                ll fb = formula(s, t), rb = brute(s, t);
                if (fb != rb) {
                    printf("MISMATCH graph %d event %d query %d->%d: formula=%lld brute=%lld\n", gno, e, s, t, fb, rb);
                    printf("n=%d\nA:", n); for (int i = 1; i <= n; i++) printf(" %lld", A[i]);
                    printf("\nB:"); for (int i = 1; i <= n; i++) printf(" %lld", B[i]); printf("\n");
                    return 1;
                }
            } else if (type == 2) A[1 + rng() % n] = wlo + (ll)(rng() % (whi - wlo + 1));
            else B[1 + rng() % n] = wlo + (ll)(rng() % (whi - wlo + 1));
        }
    }
    printf("OK %d graphs x 20 events, seed %llu\n", graphs, (unsigned long long)seed);
    return 0;
}
