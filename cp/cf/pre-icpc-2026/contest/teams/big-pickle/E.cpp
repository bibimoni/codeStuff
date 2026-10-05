#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

int n;
vector<vector<int>> adj;        // node -> children in rooted tree
vector<int> sz;
vector<vector<int>> f;          // f[v][k] = #orders of subtree(v) with v at 0-indexed pos k

int modpow(int a, int e) {
    int r = 1;
    while (e) { if (e & 1) r = (ll)r * a % MOD; a = (ll)a * a % MOD; e >>= 1; }
    return r;
}

int C(int a, int b, const vector<int>& fact, const vector<int>& ifact) {
    if (b < 0 || b > a) return 0;
    return (ll)fact[a] * ifact[b] % MOD * ifact[a - b] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<vector<pair<int,int>>> raw(n); // (neighbor, first-of-relation) ; first==-1 means w==0
    for (int i = 0; i < n - 1; i++) {
        int u, v, w; cin >> u >> v >> w; --u; --v;
        int first = (w == 1) ? u : (w == 2 ? v : -1);
        raw[u].push_back({v, first});
        raw[v].push_back({u, first});
    }
    // root the tree at 0, compute parent/dir and BFS order
    vector<int> par(n, -1), dir(n, 2), order;
    vector<int> stk = {0}; par[0] = 0;
    vector<char> vis(n, 0); vis[0] = 1;
    while (!stk.empty()) {
        int v = stk.back(); stk.pop_back();
        order.push_back(v);
        for (auto [to, first] : raw[v]) {
            if (vis[to]) continue;
            vis[to] = 1; par[to] = v;
            if (first == -1) dir[to] = 2;         // free
            else dir[to] = (first == to) ? 1 : 0;  // 1 => child before parent, 0 => parent before child
            stk.push_back(to);
        }
    }
    // build children lists
    adj.assign(n, {});
    for (int v = 0; v < n; v++) if (v != 0) adj[par[v]].push_back(v);

    vector<int> fact(n + 1, 1), ifact(n + 1, 1);
    for (int i = 1; i <= n; i++) fact[i] = (ll)fact[i - 1] * i % MOD;
    ifact[n] = modpow(fact[n], MOD - 2);
    for (int i = n; i > 0; i--) ifact[i - 1] = (ll)ifact[i] * i % MOD;

    sz.assign(n, 0);
    f.assign(n, {});

    // process in reverse BFS/DFS order (children before parents)
    for (int idx = (int)order.size() - 1; idx >= 0; idx--) {
        int v = order[idx];
        vector<int> acc(1, 1); // just v, v at pos 0
        int s = 1;
        for (int c : adj[v]) {
            int b = sz[c];
            vector<int>& fc = f[c];
            int Wc = 0; for (int x : fc) { Wc += x; if (Wc >= MOD) Wc -= MOD; }
            vector<int> R(b + 1, 0);
            if (dir[c] == 1) {          // c before v: R[t] = sum_{i<t} fc[i]
                for (int t = 1; t <= b; t++) { R[t] = R[t-1] + fc[t-1]; if (R[t]>=MOD) R[t]-=MOD; }
            } else if (dir[c] == 0) {   // v before c: R[t] = sum_{i>=t} fc[i]
                // R[b]=0; R[t]=R[t+1]+fc[t]
                for (int t = b - 1; t >= 0; t--) { R[t] = R[t+1] + fc[t]; if (R[t]>=MOD) R[t]-=MOD; }
            } else {                     // free: any split allowed
                for (int t = 0; t <= b; t++) R[t] = Wc;
            }
            vector<int> nw(s + b, 0);
            for (int k = 0; k < s; k++) {
                if (!acc[k]) continue;
                int after = s - 1 - k; // # A-elements after v
                ll base = acc[k];
                for (int t = 0; t <= b; t++) {
                    if (!R[t]) continue;
                    ll val = base * R[t] % MOD;
                    val = val * C(k + t, k, fact, ifact) % MOD;
                    val = val * C(after + b - t, after, fact, ifact) % MOD;
                    nw[k + t] = (nw[k + t] + val) % MOD;
                }
            }
            acc.swap(nw);
            s += b;
        }
        f[v] = acc;
        sz[v] = s;
    }
    int ans = 0;
    for (int x : f[0]) { ans += x; if (ans >= MOD) ans -= MOD; }
    cout << ans << '\n';
    return 0;
}
