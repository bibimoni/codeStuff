/**
 * File              : spiral.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 23.05.2023
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

vector<vector<int>> a(1001, vector<int>(1001, 0));

void spiralOrder(int n) {
      int order = 0; //increase this to move to the next direction
      int visitedCells = 0; 
      int x = 0; //curr position
      int y = 0;
      bool visited[1001][1001] = {false};
      int direction[] = {0, 1, 0, -1, 0};// the order of movement left down right up
      int totalCells = n * n;
      int xEdge = n;
      int yEdge = n;
      while(visitedCells < totalCells) {
        visitedCells++; //increase the visited cell
        visited[x][y] = true; //set that cell to true
        a[x][y] = visitedCells; 
        int oldOffsetX =  direction[(order % 4)];
        int oldOffsetY = direction[(order % 4) + 1];
        if((x + oldOffsetX) >= xEdge || (y + oldOffsetY) >= yEdge || 
          (x + oldOffsetX)  < 0 || (y + oldOffsetY) < 0 ||
          visited[x + oldOffsetX][y + oldOffsetY] ) 
        {
          order++;
        }
    int offsetX =  direction[(order % 4)];
    int offsetY = direction[(order % 4) + 1];
    x += offsetX;
    y += offsetY;
  }
}
signed main() {
  FAST;
  MULTI {
    int n, x, y; cin >> n >> x >> y;
    //find x
    spiralOrder(n);
    int xt, yt, xD, yD;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(a[i][j] == x) {
          xt = i;
          yt = j;
        }
        if(a[i][j] == y) {
          xD = i;
          yD = j;
        }
      }
    }
    //bfs
    vector<vector<int>> d(n, vector<int>(n,(int) 1e6));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[xt][yt] = true;
    d[xt][yt] = 0;
    queue<pair<pair<int, int>, int>> Q;
    int dir[] = {1, 0, -1, 0, 1};
    Q.push({{xt, yt}, 0});
//    dbg(xt, yt);
    while(!Q.empty()) {
      int uX = Q.front().first.first;
      int uY = Q.front().first.second;
      int step = Q.front().second;
      Q.pop();
      for(int i = 0; i < 4; i++) {
        int vX = dir[i] + uX;
        int vY = dir[i + 1] + uY;
        if(!(vX >= 0 && vY >= 0 && vX < n && vY < n)) continue;
//        dbg(a[uX][uY], uX, uY, a[vX][vY], vX, vY, gcd(a[uX][uY], a[vX][vY]));
//        cout << visited[vX][vY] << endl;
        if(!visited[vX][vY] && (__gcd(a[uX][uY], a[vX][vY]) == 1)) {
          d[vX][vY] = min(d[vX][vY], step + 1);
          Q.push({{vX, vY}, d[vX][vY]});
          visited[vX][vY] = true;
        }
      }
    }
    cout << ((d[xD][yD] == (int) (1e6)) ? -1 : d[xD][yD] ) << endl;
  }
}
