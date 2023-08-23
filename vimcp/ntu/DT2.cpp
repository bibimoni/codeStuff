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

int n, m;
int a[1001][1001];
vector<vector<bool>> visited(1001, vector<bool> (1001, false));
int dX[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dY[] = {0, 1, 0, -1, 1, -1, 1, -1};

void input() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
}

void BFS(int x, int y, int &res) {
    queue<pair<int, int>> Q;
    bool isHill = true;
    Q.push({x, y});
    visited[x][y] = true;
    while(!Q.empty()) {
        pair<int ,int> u = Q.front(); Q.pop();
        int uX = u.first, uY = u.second;
        for(int i = 0; i < 8; i++) {
            int vX = uX + dX[i];
            int vY = uY + dY[i];
            if(vX > 0 && vY > 0 && vX <= n && vY <= m) {
                if(a[vX][vY] == a[uX][uY] && !visited[vX][vY]) {
                    visited[vX][vY] = true;
                    Q.push({vX, vY});
                }
                if(a[vX][vY] > a[uX][uY]) isHill = false;
            }
        }
    }
//    if(isHill) dbg(x, y);
    res += isHill;
}

void solve() {
    int res = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(!visited[i][j]) {
                BFS(i, j, res);
            }
        }
    }
    cout << res << endl;
}

signed main() {
    FAST;
    input();
    solve();
}

