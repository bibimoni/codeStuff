/**
 * https://oj.uz/problem/view/NOI18_knapsack
 * File              : NOI18_knapsack.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 18.05.2023
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
#define INF (int) 1e9 + 1

int nxt() {int n; cin >> n; return n;}

signed main() {
  FAST;
  int s, n; cin >> s >> n;
  map<int, vector<pair<int, int>>> weight;
  for(int i = 0; i < n; i++) {
    int v, w, k; cin >> v >> w >> k;
    if(w <= s && k > 0)
    weight[w].push_back({v, k});
  }

  //dp[i][j] most value using j weight and i types
  vector<vector<int>> dp(weight.size() + 1, vector<int>(s + 1, -INF));
  dp[0][0] = 0;
  int at = 1;
 for(auto &[w, items] : weight) {
    sort(items.begin(), items.end(), greater<pair<int, int>>());
    for(int i = 0; i <= s; i++) {
      dp[at][i] = dp[at - 1][i];
      int total = 0;
      int currType = 0;
      int currUsed = 0;
      int profit = 0;
      
      while((total + 1) * w <= i && currType < items.size()) {
        total++;
        profit += items[currType].first;
        if(dp[at - 1][i - total * w] != -INF) {
          dp[at][i] = max(dp[at][i], dp[at - 1][i - total * w] + profit);
        }

        currUsed++;
        if(currUsed == items[currType].second) {
          currUsed = 0;
          currType++;
        }
      }
    }
    at++;
  }
  cout << *max_element(dp.back().begin(), dp.back().end()) << endl;
}

