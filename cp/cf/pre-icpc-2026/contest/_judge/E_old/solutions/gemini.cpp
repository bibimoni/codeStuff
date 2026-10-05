#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;
const int MAXN = 4005;

long long fact[MAXN], invFact[MAXN];

// Fast exponentiation for modular inverse
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// Compute modular inverse using Fermat's Little Theorem
long long modInverse(long long n) {
    return power(n, MOD - 2);
}

// Precompute factorials and their inverses for O(1) combination queries
void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAXN - 1] = modInverse(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

// Combinations (n choose r) modulo 998244353
long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

struct Edge {
    int to;
    int type; // 0: flexible, 1: strict (u before v), 2: reverse (v before u)
};

int n;
vector<Edge> adj[MAXN];
vector<long long> dp[MAXN];
int sz[MAXN];

void dfs(int u, int p) {
    sz[u] = 1;
    dp[u] = {0, 1}; // dp[u] is 1-indexed. dp[u][1] = 1

    for (auto edge : adj[u]) {
        int v = edge.to;
        if (v == p) continue;
        
        dfs(v, u);
        
        // Prepare new DP table to store merged configurations
        vector<long long> new_dp(sz[u] + sz[v] + 1, 0);
        
        // Precompute prefix sums of child's DP to compute multiplier W in O(1)
        vector<long long> pref_v(sz[v] + 1, 0);
        for (int i = 1; i <= sz[v]; i++) {
            pref_v[i] = (pref_v[i - 1] + dp[v][i]) % MOD;
        }
        long long sum_all_v = pref_v[sz[v]];

        // Merge subtree 'v' into subtree 'u'
        for (int j = 1; j <= sz[u]; j++) {
            for (int k = 0; k <= sz[v]; k++) {
                long long W = 0;
                
                if (edge.type == 0) {
                    // Flexible: v can be anywhere
                    W = sum_all_v;
                } else if (edge.type == 1) {
                    // Strict (u before v): v's position must be after the k elements placed before u
                    W = (pref_v[sz[v]] - pref_v[k] + MOD) % MOD;
                } else if (edge.type == 2) {
                    // Reverse (v before u): v's position must be among the k elements placed before u
                    W = pref_v[k];
                }
                
                if (W == 0) continue;

                int i = j + k; // New position of 'u'
                long long ways = nCr(i - 1, k) * nCr(sz[u] + sz[v] - i, sz[v] - k) % MOD;
                long long term = dp[u][j] * ways % MOD * W % MOD;
                
                new_dp[i] = (new_dp[i] + term) % MOD;
            }
        }
        
        sz[u] += sz[v];
        dp[u] = move(new_dp);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    if (!(cin >> n)) return 0;

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        if (w == 0) {
            adj[u].push_back({v, 0});
            adj[v].push_back({u, 0});
        } else if (w == 1) {
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 2});
        } else if (w == 2) {
            adj[u].push_back({v, 2});
            adj[v].push_back({u, 1});
        }
    }

    dfs(1, 0);

    long long total_schedules = 0;
    for (int i = 1; i <= n; i++) {
        total_schedules = (total_schedules + dp[1][i]) % MOD;
    }

    cout << total_schedules << "\n";

    return 0;
}