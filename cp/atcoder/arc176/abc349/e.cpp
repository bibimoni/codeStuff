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
vector<vector<vector<int>>> states;
void Try(int i, int j, vector<vector<int>> curr) {
	if(i == 3 && j == 0) {
		bool ok = false;
		for(int r = 0; r < 3; r++) {
			ok |= (curr[r][0] == curr[r][1] && curr[r][0] == curr[r][2]);
		}
		for(int c = 0; c < 3; c++) {
			ok |= (curr[0][c] == curr[1][c] && curr[0][c] == curr[2][c]);
		}
		ok |= (curr[0][0] == curr[1][1] && curr[0][0] == curr[2][2]);
		ok |= (curr[2][0] == curr[1][1] && curr[2][0] == curr[0][2]);
		// dbg(curr, ok);
		if(!ok) {
			states.push_back(curr);
		}
		return;
	}
	int ni = i + (j == 2);
	int nj = (j == 2 ? 0 : j + 1);
	// dbg(ni, nj);
	Try(ni, nj, curr);
	curr[i][j] = 1;
	Try(ni, nj, curr);
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  vector<vector<int>> tmp(3, vector<int>(3, -1));
  Try(0, 0, tmp);
  // dbg(states);
  vector<vector<int>> a(3, vector<int>(3));
  for(int i = 0; i < 3; i++)
  	for(int j = 0; j < 3; j++)
  		cin >> a[i][j];
  bool win = false;
  for(auto p : states) {
  	int pts = 0;
  	if(p[1][1] == -1)
  		continue;
  	dbg(p);
  	for(int i = 0; i < 3; i++) {
  		for(int j = 0; j < 3; j++) {
  			pts += p[i][j] * a[i][j];
  		}
  	}
  	dbg(pts);
  	if(pts > 0) {
  		win = true;
  	}
  }
  cout << (win ? "Takahashi" : "Aoki");

}


