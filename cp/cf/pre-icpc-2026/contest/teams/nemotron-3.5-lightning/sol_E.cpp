#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 4005;

int addmod(int a, int b) { a += b; if (a >= MOD) a -= MOD; return a; }
int submod(int a, int b) { a -= b; if (a < 0) a += MOD; return a; }
int mulmod(long long a, long long b) { return int(a * b % MOD); }
int powmod(int a, int e) {
    int r = 1;
    while (e) {
        if (e & 1) r = mulmod(r, a);
        a = mulmod(a, a);
        e >>= 1;
    }
    return r;
}

int fact[MAXN], invfact[MAXN];

int C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return mulmod(fact[n], mulmod(invfact[k], invfact[n - k]));
}

struct Edge {
    int to;
    int dir; // 1: u->v, -1: v->u
};

int n;
vector<Edge> adj[MAXN];
bool vis[MAXN];
vector<int> comp_nodes;

void dfs_comp(int u) {
    vis[u] = true;
    comp_nodes.push_back(u);
    for (auto &e : adj[u]) {
        if (!vis[e.to]) dfs_comp(e.to);
    }
}

vector<int> dp[MAXN];
int sz[MAXN];

void merge_dp(vector<int> &dp_u, const vector<int> &dp_v, int dir) {
    int L = dp_u.size();
    int M = dp_v.size();
    vector<int> new_dp(L + M, 0);
    
    vector<int> pref(M + 1, 0), suff(M + 1, 0);
    for (int j = 0; j < M; ++j) pref[j + 1] = addmod(pref[j], dp_v[j]);
    for (int j = M - 1; j >= 0; --j) suff[j] = addmod(suff[j + 1], dp_v[j]);
    
    for (int i = 0; i < L; ++i) {
        if (dp_u[i] == 0) continue;
        for (int k = 0; k < L + M; ++k) {
            int sum_dp_v = 0;
            if (dir == 1) { // u -> v (u before v)
                int min_j = max(k - i, 0);
                if (min_j >= M) continue;
                sum_dp_v = submod(suff[min_j], suff[M]);
            } else { // v -> u (v before u)
                int max_j = min(k - i - 1, M - 1);
                if (max_j < 0) continue;
                sum_dp_v = pref[max_j + 1];
            }
            if (sum_dp_v == 0) continue;
            int comb = mulmod(C(k, i), C(L + M - k - 1, L - i - 1));
            new_dp[k] = addmod(new_dp[k], mulmod(mulmod(dp_u[i], sum_dp_v), comb));
        }
    }
    dp_u.swap(new_dp);
}

void dfs_dp(int u, int p) {
    dp[u] = {1};
    sz[u] = 1;
    for (auto &e : adj[u]) {
        int v = e.to;
        if (v == p) continue;
        dfs_dp(v, u);
        merge_dp(dp[u], dp[v], e.dir);
        sz[u] += sz[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) fact[i] = mulmod(fact[i - 1], i);
    invfact[MAXN - 1] = powmod(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; --i) invfact[i] = mulmod(invfact[i + 1], i + 1);
    
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        if (w == 1) {
            adj[u].push_back({v, 1}); // u -> v
            adj[v].push_back({u, -1});
        } else if (w == 2) {
            adj[u].push_back({v, -1}); // v -> u
            adj[v].push_back({u, 1});
        }
        // w == 0: flexible, ignored for the fixed-edge DP
        // (the sum over orientations factors correctly)
    }
    
    int ans = fact[n];
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            comp_nodes.clear();
            dfs_comp(i);
            if (comp_nodes.empty()) continue;
            
            int root = comp_nodes[0];
            dfs_dp(root, -1);
            
            int le = 0;
            for (int x : dp[root]) le = addmod(le, x);
            
            ans = mulmod(ans, mulmod(le, invfact[comp_nodes.size()]));
            
            // Clear dp for nodes in this component to save memory
            for (int u : comp_nodes) {
                dp[u].clear();
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}