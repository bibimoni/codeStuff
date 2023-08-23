/**
 * File              : E.cpp
 * Author            : distiled
 * Date              : 07.05.2023
 * Last Modified Date: 07.05.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x);
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

#define int long long
#define mod 1000000007
#define endl '\n'
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI int t;cin>>t;while(t--)

int nxt() {int n; cin >> n; return n;}

void BFS(int src, int &ans, vector<vector<int>> adj, vector<int> &visited, vector<int> c) {
    queue<int> q;
    visited[src] = true;
    q.push(src);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        ans += c[u];
        for(int v : adj[u]) {
            if(visited[v]) continue;
            q.push(v);
            dbg(v, src);
            visited[v] = true;
        }
    }
}

signed main() {
    FAST;
    int n, m; cin >> n >> m;
    vector<int> c(n + 1);
    for(int i = 1; i <= n; i++) cin >> c[i];
    vector<vector<int>> adj(n + 1);
    vector<int> visited(n + 1, false);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i != j) {
                adj[i].emplace_back(j);
            }
        }
    }
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        for(int j = 0; j < adj[u].size(); j++) {
            if(v == adj[u][j]) {
                adj[u].erase(adj[u].begin() + j);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << i << endl;
        for(auto x : adj[i]) cout << x << ' ';
        cout << endl;
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(visited[i]) continue;
        int temp = 0;
        BFS(i, temp, adj, visited, c);
        ans = max(ans, temp);
    }
    cout << ans;
}

