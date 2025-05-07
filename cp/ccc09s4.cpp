/**
 * File              : ccc09s4.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 26.06.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;
void __print(int x) {cerr << x;}void __print(long x) {cerr << x;}void __print(long long x) {cerr << x;}void __print(unsigned x) {cerr << x;}void __print(unsigned long x) {cerr << x;}void __print(unsigned long long x) {cerr << x;}void __print(float x) {cerr << x;}void __print(double x) {cerr << x;}void __print(long double x) {cerr << x;}void __print(char x) {cerr << '\'' << x << '\'';}void __print(const char *x) {cerr << '\"' << x << '\"';}void __print(const string &x) {cerr << '\"' << x << '\"';}void __print(bool x) {cerr << (x ? "true" : "false");}template<typename T, typename V>void __print(const pair<T, V> &x);template<typename T>void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}template<typename T, typename V>void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}void _print() {cerr << "]\n";}template <typename T, typename... V> void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...)     cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

#define all(x)        x.begin(), x.end()
#define rall(x)       x.rbegin(), x.rend()
#define sz(x)         (int) x.size()
#define __lcm(a, b)   (1ll * ((a) / __gcd((a), (b))) * (b))
#define YES           cout << "YES\n";
#define NO            cout << "NO\n";
#define mod           1000000007
#define endl          '\n'
#define TLE           ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI         int t;cin>>t;while(t--)
#define INF           (int) 1e9
#define MAXN          (int) 5e3 + 5

int nxt() {int n; cin >> n; return n;}
int numCities, tradeRoutes, numStores, dest, pencilCosts[MAXN], distanceTo[MAXN];
vector<vector<pair<int, int>>> adj(MAXN);
int answer = INF;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

//find minimum cost from a pencil 
//store to the destination using dijkstra
void findMinCostPerStore() { 
  Q.push({0, dest});
  distanceTo[dest] = 0; 
  while(!Q.empty()) {
   auto [currWeight, currNode] = Q.top(); 
    Q.pop();    
    if(currWeight > distanceTo[currNode]) continue;
    //if the current node is a pencil store then update
   for(auto [nextNode, nextWeight] : adj[currNode]) {
      if(distanceTo[currNode] + nextWeight < distanceTo[nextNode]) {
        distanceTo[nextNode] = distanceTo[currNode] + nextWeight;
        Q.push({distanceTo[nextNode], nextNode});
      }    
    }
  }
  for(int i = 0; i <= numCities; i++) {
    if(pencilCosts[i] != -1)
      answer = min(answer, distanceTo[i] + pencilCosts[i]);
  }
  cout << answer;
}

void input() {
  cin >> numCities >> tradeRoutes;
  for(int i = 0, u, v, cost; i < tradeRoutes; i++) {
    cin >> u >> v >> cost;
    adj[u].push_back({v, cost});
    adj[v].push_back({u, cost});
  }
  for(int i = 0; i <= numCities; i++) {
    distanceTo[i] = INF;
    pencilCosts[i] = -1;
  }
  cin >> numStores;
  for(int i = 0, pencilStore; i < numStores; i++) {
    cin >> pencilStore >> pencilCosts[pencilStore];
  }
  cin >> dest;
}
signed main() {
  TLE;
  input();
  findMinCostPerStore();
}

