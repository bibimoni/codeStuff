#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353LL;
long long modpow(long long a, long long e) {
    long long r = 1;
    while (e) { if (e & 1) r = r * a % MOD; a = a * a % MOD; e >>= 1; }
    return r;
}
int n;
vector<vector<int>> before_, after_;
vector<long long> fact, ifact;
long long Cnk(int N, int K) {
    if (K < 0 || K > N) return 0;
    return fact[N] * ifact[K] % MOD * ifact[N-K] % MOD;
}
// returns f where f[i] = # LE of subtree poset with u at rank i
vector<long long> dfs(int u, int par) {
    vector<long long> fA(1, 1); // |A| = 1
    int sA = 1;
    auto mergeChild = [&](vector<long long> fB, bool uBeforeV) {
        int sB = (int)fB.size();
        int S = sA + sB;
        vector<long long> g(S, 0);
        // suffix/prefix sums of fB
        vector<long long> acc(sB + 1, 0);
        if (uBeforeV) { for (int j = sB - 1; j >= 0; j--) { acc[j] = acc[j+1] + fB[j]; if (acc[j] >= MOD) acc[j] -= MOD; } }
        else { for (int j = 0; j < sB; j++) { acc[j+1] = acc[j] + fB[j]; if (acc[j+1] >= MOD) acc[j+1] -= MOD; } }
        for (int i = 0; i < sA; i++) if (fA[i]) {
            for (int t = 0; t < sB; t++) {
                long long w = uBeforeV ? acc[t] : acc[t]; // acc[t]=sum_{j>=t} or acc[t]=sum_{j<t}
                // for uBeforeV: suffix sum from t; for other: prefix sum below t
                if (!w) continue;
                int k = i + t;
                long long add = fA[i] * Cnk(i + t, i) % MOD * Cnk(S - 1 - k, sA - 1 - i) % MOD * w % MOD;
                g[k] += add;
                if (g[k] >= MOD) g[k] -= MOD;
            }
            if (!uBeforeV) {
                // t = sB: prefix acc[sB] (all j < sB); C(S-1-k, sA-1-i) with k=i+sB
                long long w = acc[sB];
                if (w) {
                    int k = i + sB;
                    long long add = fA[i] * Cnk(i + sB, i) % MOD * Cnk(S - 1 - k, sA - 1 - i) % MOD * w % MOD;
                    g[k] += add;
                    if (g[k] >= MOD) g[k] -= MOD;
                }
            }
        }
        fA.swap(g);
        sA = S;
    };
    for (int v : before_[u]) if (v != par) {
        // v before u
        mergeChild(dfs(v, u), false);
    }
    for (int v : after_[u]) if (v != par) {
        // u before v
        mergeChild(dfs(v, u), true);
    }
    return fA;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!(cin >> n)) return 0;
    before_.assign(n, {});
    after_.assign(n, {});
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        if (w == 1) { after_[u].push_back(v); before_[v].push_back(u); }
        else if (w == 2) { after_[v].push_back(u); before_[u].push_back(v); }
    }
    fact.assign(n + 1, 1); for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % MOD;
    ifact.assign(n + 1, 1); ifact[n] = modpow(fact[n], MOD - 2);
    for (int i = n; i > 0; i--) ifact[i-1] = ifact[i] * i % MOD;
    vector<vector<int>> fadj(n);
    for (int u = 0; u < n; u++) {
        for (int v : before_[u]) fadj[u].push_back(v);
        for (int v : after_[u]) fadj[u].push_back(v);
    }
    vector<int> vis(n, 0);
    long long ans = 1;
    int rest = n;
    for (int s = 0; s < n; s++) if (!vis[s]) {
        vector<int> comp;
        queue<int> q; q.push(s); vis[s] = 1;
        while (!q.empty()) { int u = q.front(); q.pop(); comp.push_back(u);
            for (int v : fadj[u]) if (!vis[v]) { vis[v] = 1; q.push(v); } }
        vector<long long> f = dfs(comp[0], -1);
        long long tot = 0;
        for (long long x : f) { tot += x; if (tot >= MOD) tot -= MOD; }
        int sz = (int)f.size();
        ans = ans * Cnk(rest, sz) % MOD * tot % MOD;
        rest -= sz;
    }
    cout << ans % MOD << "\n";
    return 0;
}
