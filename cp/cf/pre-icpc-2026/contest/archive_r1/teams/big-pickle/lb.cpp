// brute force for L: DFS over all simple paths (n small)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q, tgt;
ll a[20], b[20];
vector<pair<int, ll>> adj[20];
bool vis[20];
ll best;

void dfs(int u, ll cost) {
    if (u == tgt) { best = min(best, cost); return; }
    for (auto pr : adj[u]) {
        if (!vis[pr.first]) { vis[pr.first] = true; dfs(pr.first, cost + pr.second); vis[pr.first] = false; }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &q);
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
        while (q--) {
            int type;
            scanf("%d", &type);
            if (type == 1) {
                int s, t;
                scanf("%d %d", &s, &t);
                for (int i = 1; i <= n + 1; i++) { adj[i].clear(); vis[i] = false; }
                for (int i = 1; i <= n; i++) {
                    int j = i % n + 1;
                    adj[i].push_back({j, a[i]});
                    adj[j].push_back({i, a[i]});
                }
                for (int i = 1; i <= n; i++) {
                    adj[i].push_back({n + 1, b[i]});
                    adj[n + 1].push_back({i, b[i]});
                }
                tgt = t;
                vis[s] = true;
                best = LLONG_MAX / 4;
                dfs(s, 0);
                printf("%lld\n", best);
            } else {
                int x;
                ll w;
                scanf("%d %lld", &x, &w);
                if (type == 2) a[x] = w; else b[x] = w;
            }
        }
    }
    return 0;
}
