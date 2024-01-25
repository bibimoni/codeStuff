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

signed main() {
    FAST;
    MULTI {
        int m = nxt();
        map<int, int> f;
        vector<vector<int>> adj(m);
        for(int i = 0; i < m; i++) {
            int n = nxt();
            for(int j = 0; j < n; j++) {
                adj[i].push_back(nxt());
            }
        }
        dbg(adj);
        vector<int> res(m);
        int check = true;
        for(int i = m - 1; i >= 0; i--) {
            int l = adj[i].size();
            dbg(i);
            for(int j = 0; j < l; j++) {
                int e = adj[i][j];
                dbg(e, f[e]);
                if(!f[e]) {
                    res[i] = e;
                }
                f[e]++;
            }
            dbg(res[i]);
            if(res[i] == 0) {
                check = false;
                break;
            }
        }
        if(!check) {
            cout << -1 << endl;
        }
        else {
            for(auto &i : res) cout << i << ' ';
            cout << endl;
        }
    }
}

