/**
 * File              : 3C.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 31.07.2023
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

vector<vector<char>> a(21, vector<char>(21));
int n;
vector<pair<int, int>> winLine;

bool isValid(int x, int y) {
  return x >= 1 && y >= 1 && x <= n && y <= n;
}

bool check(int x, int y, int dirX, int dirY) {
  int cnt = 1;
  int currX = x + dirX;
  int currY = y + dirY;
  char f = a[x][y];
  while(isValid(currX, currY) && a[currX][currY] == f) {
    cnt++;
    currX += dirX;
    currY += dirY;
  }:wq

  currX = x - dirX;
  currY = y - dirY;
  while(isValid(currX, currY) && a[currX][currY] == f) {
    cnt++;
    currX -= dirX;
    currY -= dirY;
  }
  return cnt >= 3;
}

bool solve(int x, int y) {
  if(check(x, y, 1, 0)) return true;
  if(check(x, y, 0, 1)) return true;
  if(check(x, y, 1, 1)) return true;
  if(check(x, y, 1, -1)) return true;
  return false;
}

signed main() {
  FAST;
  MULTI {
  n = 3;
  int cntX = 0, cntO = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> a[i][j];
      cntX += (a[i][j] == 'X');
      cntO += (a[i][j] == 'O');
    }
  } 
  bool turn = 0;
  if(cntX == cntO) turn = 1;
  int state = 0;
  int illegal;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(a[i][j] == 'X' && solve(i, j)) {
        state = 1;
        break;
      }
      else if(a[i][j] == 'O' && solve(i, j)) {
        state = 2;
        break;
      }
    }
  }
  if(state == 0) {
    cout << "DRAW";
  }
  else if(state == 1) {
    cout << "X";
  }
  else if(state == 2) {
    cout << "O";
  }
  else {
    cout << "+";
  }
  cout << endl;
  }
}
    
