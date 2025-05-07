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

bool isValid(int n, int m, int x, int y, vector<vector<bool>> visited) {
    return x >= 1 && y >= 1 && x <= n && y <= m && !visited[x][y]; 
}

signed main() {
    FAST;
    int n, m, x, y; cin >> n >> m >> x >> y; 
    vector<vector<int>> A(n + 1, vector<int>(m + 1, 0));
    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> A[i][j];
            if(A[i][j] == 1) visited[i][j] = true;
        }
    }
    int d[] = {1, 0, -1, 0, 1};
    queue<pair<int, int>> Q;
    Q.push({x, y});
    int ans = 1;
    visited[x][y] = true;
    while(!Q.empty()) {
        pair<int, int> u = Q.front();
        int uX = u.first;
        int uY = u.second;
        Q.pop();
        for(int i = 0; i < 4; i++) {
            int vX = uX + d[i];
            int vY = uY + d[i + 1];
            if(!isValid(n, m, vX, vY, visited)) continue;
            ans++;
            Q.push({vX, vY});
            visited[vX][vY] = true;
        }
    }
    cout << ans;
}

