// time-limit: 3000
/**
 * Author: distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
#define int            long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int a[m], b[m];
  vector<int> row(n + 1, 0), col(n + 1, 0);
  set<pair<int, int>> ans;
  set<int> occCol;
  for(int i = 0; i < m; i++) {
  	cin >> a[i] >> b[i];
  	ans.insert({a[i], b[i]});
  	row[a[i]]++;
  	col[b[i]]++;
  	occCol.insert(b[i]);
  }
  auto getCol = [&] (int row) -> int {
  	if(occCol.size() < n) {
  		for(int i = 1; i <= n; i++) {
  			if(occCol.find(i) == occCol.end()) {
  				return i;
  			}
  		}
  	}
  	int cnt = 11, c = -1;
  	for(int i : occCol) {
  		if(cnt > col[i] && col[i] < m && ans.find({row, i}) == ans.end()) {
  			dbg(i);
  			c = i;
  			cnt = col[i];
  		}
  	}
  	return c;
  };
  for(int i = 1; i <= n; i++) {
  	while(row[i] < m) {
  		int c = getCol(i);
  		row[i]++;
  		col[c]++;
  		occCol.insert(c);
  		ans.insert({i, c});
  	}
  }
  cout << ans.size() << '\n';
  for(auto [p, v] : ans) {
  	cout << p << ' ' << v << '\n';
  }
}


