/**
 * https://ntucoder.net/Problem/Details/110
 * File              : line3.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 26.05.2023
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

int d[] = {1, 0, -1, 0, 1};
vector<vector<int>> board(10, vector<int>(10, 1e9));
vector<vector<bool>> visited(10, vector<bool>(10, false));
vector<vector<pair<int, int>>> trace(10, vector<pair<int, int>>(10));
signed main() {
  FAST;
  int n, sy, sx, dy, dx; cin >> n >> sy >> sx >> dy >> dx;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      visited[i][j] = nxt();
    }
  }
  visited[sy][sx] = true;
  queue<pair<int, int>> Q;
  Q.push({sy, sx});
  board[sy][sx] = 0;
  bool found = false;
  while(!Q.empty()) {
    int uY = Q.front().first;
    int uX = Q.front().second;
    if(uY == dy && uX == dx) {
      found = true;
      break;
    }
    Q.pop();
    for(int i = 0; i < 4; i++) {
      int vY = uY + d[i];
      int vX = uX + d[i + 1];
      if(visited[vY][vX] || vY <= 0 || vX <= 0 || vY > n || vX > n) continue;
      if(board[uY][uX] + 1 < board[vY][vX]) {
        board[vY][vX] = board[uY][uX] + 1;
        trace[vY][vX] = {uY, uX};
        Q.push({vY, vX});
      }
    }
  }
  if(!found) {
    cout << 0;
    return 0;
  }
  vector<pair<int, int>> path;
  pair<int, int> u = {dy, dx};
  while(u.first != sy || u.second != sx) {
    path.push_back(u);
    u = trace[u.first][u.second];
  }
  path.push_back({sy, sx});
  reverse(path.begin(), path.end());
  cout << path.size() << endl;
  for(int i = 0; i < path.size(); i++) {
    cout << path[i].first << ' ' << path[i].second << endl;
  }
}

