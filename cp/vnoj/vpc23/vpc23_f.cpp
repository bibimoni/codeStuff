/**
 * File              : vpc23_f.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 04.08.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </home/distiled/templates/debug.h>
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

int n, q;
map<string, bool> f;

bool solveRecs(string t, vector<string> &curr) {
  if((int) t.size() == 0) return false;
  for(int i = 0; i < (int) t.size(); i++) {
    string prefix = t.substr(0, i + 1);
    string suffix = t.substr(i + 1);
    if(f[prefix]) {
      if((int) suffix.size() == 0 || solveRecs(suffix, curr)) {
        curr.push_back(prefix);
        return true;
      }
    }
  }
  return false;
}

void solveStr(string t) {
  vector<string> res;
  if(solveRecs(t, res)) {
    reverse(all(res));
    for(auto i : res) {
      cout << i << ' ';
    }
  }
  else {
    cout << -1;
  }
  cout << endl;
}

signed main() {
  TLE;
  cin >> n;
  for(int i = 0; i < n; i++) {
    string t; cin >> t;
    f[t] = true;
  }
  cin >> q;
  while(q--) {
    string curr; cin >> curr;
    solveStr(curr);
  }
}

