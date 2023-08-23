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
#define MAXN (int) 1e5 + 5

int nxt() {int n; cin >> n; return n;}

int n, m, k;
int cnt_com = 0, time_dps= 0, num[MAXN], low[MAXN];
stack<int> st;
bool isDeleted[MAXN];
vector<int> adj[MAXN];
vector<int> stored;
int res = 0;

void DFS(int u) {
    num[u] = low[u] = ++time_dps;
    st.push(u);
    for(auto v : adj[u]) {
        if(isDeleted[v]) continue;
        if(!num[v]) {
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
        else {
            low[u] = min(low[u], num[v]);
        }
    }
    if(low[u] == num[u]) {
        bool store = false;
        res = max(res, ++cnt_com);
        int v;
        stored = vector<int>();
        dbg(st.size());
        do {
            v = st.top();
            stored.push_back(v);
            st.pop();
            isDeleted[v] = true;
        } while(v != u);
    }
}

signed main() {
    FAST;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    for(int i = 1; i <= n; i++) {
        if(!num[i]) DFS(i);
    }
    cout << cnt_com << endl;
    for(auto &i : stored) cout << i << ' ';
}
