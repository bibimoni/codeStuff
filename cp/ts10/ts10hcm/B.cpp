/**
 * File              : B.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 09.06.2023
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

signed main() {
  FAST;
  int n, m; cin >> n >> m;
  vector<pair<int, int>> a(n);
  for(int i = 0; i < n; i++) {
    a[i] = {nxt(), nxt()};
  }
  sort(a.begin(), a.end(), [&a] (pair<int, int> &b, pair<int, int> &c) {
      return b.first < c.first;
      });
  multiset<pair<int, int>> reverted;
  for(int i = 0; i < n; i++) {
    //reverted route
    if(a[i].first > a[i].second) {
      if(reverted.size() == 0 || (*reverted.rbegin()).first < a[i].second) {
        //e1 - s1 - e2 - s2
        reverted.insert({a[i].first, a[i].second});
      }
      if( (*reverted.rbegin()).first >= a[i].second) {
        // e1 - e2 - s1 - s2
        int ns = max(a[i].first, (*reverted.rbegin()).first) , ne = min((*reverted.rbegin()).second,  a[i].second);
        reverted.erase(--reverted.end());
        reverted.insert({ns, ne});
      }
    }
  }
  int ans = 0;
  for(auto p : reverted) {
    ans += 2*(p.first - p.second);
  }
  cout << ans + m;
}

