/**
 * File              : CCAY.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 26.07.2023
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

#define int           long long
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
#define INF           (int) 1e18
#define MAXN          (int) 1e6 + 5

int nxt() {int n; cin >> n; return n;}

struct dsu {
  vector<int> parent;
  dsu(int _n) : parent(_n) {};

  void make(int v) {
    parent[v] = v;
  }

  int findSet(int v) {
    return v == parent[v] ? v : parent[v] = findSet(parent[v]);
  }

  void unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if(a != b) {
      parent[b] = a;
    }
  }
};


signed main() {
  TLE;
  int cnt = 1;
  MULTI {
    int n, k; cin >> n >> k;
    dsu g(n + 1);
    map<pair<int, int>, bool> edges;
    for(int i = 0; i <= n; i++) g.make(i);
    int p[n + 1];
    for(int i = 0; i < n; i++) {
      int a = i, b = nxt();
      p[a] = b;
      edges[{a, b}] = true;
    }
    cout << "Case #" << cnt << ":" << endl;
    vector<pair<char, pair<int, int>>> queries;
    for(int i = 0, a, b; i < k; i++) {
      char type; cin >> type; 
      if(type == 'Q') {
        cin >> a >> b;
        queries.push_back({type, {a, b}});
        edges[{a, b}] = false;
      } 
      if(type == 'C') {
        queries.push_back({type, {nxt(), 0}});  
      }
    }
    for(auto [p, check] : edges) {
      if(!check) continue;
      g.unionSet(p.second, p.first);
    }
    vector<bool> answer;
    while(k--) {
      auto [type, q] = queries.back(); queries.pop_back();
      if(type == 'Q') {
        q.first = g.findSet(q.first);
        q.second = g.findSet(q.second);
        answer.push_back(q.second == q.first);
      }
      else {
        g.unionSet(p[q.first], q.first);
      }
    }
    reverse(all(answer));
    for(auto i : answer) {
      if(i) cout << "YES" << endl;
      else cout << "NO" << endl;
    }
  }
}



