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

int n;
int board[101][101];
bool visited[101][101] = {false};
int d[] = {1, 0, -1, 0, 1};

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < n && !visited[x][y];
}

int maxCell = 0, minCell = 1000;
void BFS() {
    queue<pair<int,int>> Q;
    int lo = board[0][0], hi = board[0][0];
    Q.push({0, 0});
    visited[0][0] = true;
    maxCell = max(maxCell, board[0][0]);
    minCell = min(minCell, board[0][0]);
    while(!Q.empty()) {
        auto [uX, uY] = Q.front(); Q.pop();
        int currMax = 0, currMin = 1000;
        int k = 0;
        dbg(uX, uY);
        for(int i = 0; i < 4; i++) {
            int vX = uX + d[i];
            int vY = uY + d[i + 1];
            int currDiff = 1000;
            if(!valid(vX, vY)) continue;
            dbg(currMax, currMin, board[uX][uY], board[vX][vY]);
            
            dbg(k);
        }
    }
}

signed main() {
    FAST;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    BFS();
    cout << abs(maxCell - minCell);
}

