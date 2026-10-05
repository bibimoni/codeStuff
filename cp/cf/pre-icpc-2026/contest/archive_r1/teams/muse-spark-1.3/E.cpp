#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353LL;

int n;
vector<long long> fac, ifac;
long long Cnk(int N, int K) {
    if (K < 0 || K > N) return 0;
    return fac[N] * ifac[K] % MOD * ifac[N - K] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!(cin >> n)) return 0;
    // fixed edges only (flexible summed out); store per-endpoint "me_first" flag
    vector<vector<pair<int,int>>> adj(n); // (to, me_first?1:0)
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w; --u; --v;
        if (w == 1) { adj[u].push_back({v, 1}); adj[v].push_back({u, 0}); }
        else if (w == 2) { adj[u].push_back({v, 0}); adj[v].push_back({u, 1}); }
        // w==0 ignored
    }
    fac.assign(n + 1, 1); for (int i = 1; i <= n; i++) fac[i] = fac[i-1] * i % MOD;
    ifac.assign(n + 1, 1);
    auto mp = [&](long long a, long long e) {
        long long r = 1;
        while (e) { if (e&1) r=r*a%MOD; a=a*a%MOD; e>>=1; }
        return r;
    };
    ifac[n] = mp(fac[n], MOD - 2);
    for (int i = n; i > 0; i--) ifac[i-1] = ifac[i] * i % MOD;

    vector<int> comp(n, -1);
    long long answer = fac[n];
    vector<int> parent(n), order;
    vector<vector<int>> children(n);
    vector<vector<long long>> dp(n);
    vector<int> sub(n);

    int nc = 0;
    for (int s = 0; s < n; s++) if (comp[s] < 0) {
        // collect component, root at s
        order.clear();
        vector<int> stack = {s};
        comp[s] = nc; parent[s] = -1;
        while (!stack.empty()) {
            int v = stack.back(); stack.pop_back();
            order.push_back(v);
            for (auto [to, w] : adj[v]) if (comp[to] < 0) {
                comp[to] = nc; parent[to] = v;
                stack.push_back(to);
            }
        }
        for (int v : order) children[v].clear();
        for (int v : order) if (parent[v] >= 0) children[parent[v]].push_back(v);
        // postorder
        for (int ii = (int)order.size() - 1; ii >= 0; ii--) {
            int v = order[ii];
            vector<long long> f = {1}; // f[i]: v has i nodes before it
            int t = 1;
            for (int u : children[v]) {
                // direction between parent v and child u: child_first?
                int child_first = 0;
                for (auto [to, mf] : adj[u]) if (to == v) { child_first = mf; break; }
                vector<long long> &g = dp[u];
                int su = (int)g.size();
                // H[b] for b=0..su
                vector<long long> H(su + 1, 0);
                if (child_first) { // u before v: prefix
                    long long run = 0;
                    for (int b = 0; b <= su; b++) {
                        H[b] = run;
                        if (b < su) { run += g[b]; if (run >= MOD) run -= MOD; }
                    }
                } else { // v before u: suffix
                    long long run = 0;
                    for (int b = su; b >= 0; b--) {
                        H[b] = run;
                        if (b - 1 >= 0) { run += g[b-1]; if (run >= MOD) run -= MOD; }
                    }
                }
                vector<long long> nf(t + su, 0);
                for (int b = 0; b <= su; b++) if (H[b]) {
                    for (int i = 0; i < t; i++) if (f[i]) {
                        int k = i + b;
                        long long add = f[i] * H[b] % MOD;
                        add = add * Cnk(k, b) % MOD;
                        add = add * Cnk(t + su - 1 - k, su - b) % MOD;
                        nf[k] += add;
                        if (nf[k] >= MOD) nf[k] -= MOD;
                    }
                }
                f.swap(nf);
                t += su;
                dp[u].clear(); dp[u].shrink_to_fit();
            }
            dp[v] = move(f);
            sub[v] = t;
        }
        long long LE = 0;
        for (long long x : dp[s]) { LE += x; if (LE >= MOD) LE -= MOD; }
        dp[s].clear();
        answer = answer * LE % MOD * ifac[(int)order.size()] % MOD;
        nc++;
    }
    cout << answer % MOD << '\n';
    return 0;
}
