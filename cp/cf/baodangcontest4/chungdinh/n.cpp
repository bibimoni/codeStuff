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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
	  int n;
	  cin >> n;
	  array<pair<vector<int>, vector<int>>, 4> groups;
	  vector<int> a(n);
	 	for(int i = 0; i < n; i++) {
	 		cin >> a[i];
	 	}
	 	for(int i = 0; i < n; i++) {
	 		groups[a[i]% 2 + 2 * ((i + 1) % 2)].first.push_back(a[i]);
	 		groups[a[i]% 2 + 2 * ((i + 1) % 2)].second.push_back(i);
	 	}
	 	vector<int> ans(n);
	 	for(int k = 0; k < 4; k++) {
	 		auto &[vals, ids] = groups[k];
	 		sort(vals.begin(), vals.end());
	 		for(int i = 0; i < vals.size(); i++) {
	 			ans[ids[i]] = vals[i];
	 		}
	 	}
	 	cout << (is_sorted(ans.begin(), ans.end()) ? "YES\n" : "NO\n");
  }
}

