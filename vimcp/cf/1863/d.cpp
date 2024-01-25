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
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m; cin >> n >> m;
    vector<string> board(n);
    vector<string> ans(n);
    vector<int> cntRow(n, 0), cntCol(m, 0);
    for(int i = 0; i < n; i++) {
      cin >> board[i];
      string tmp = "";
      for(int j = 0; j < m; j++) tmp += '.';
      ans[i] = tmp;
      for(int j = 0; j < m; j++) {
        if(board[i][j] == 'U') cntRow[i]++;
        else if(board[i][j] == 'L') cntCol[j]++;  
      }
    }
    for(int i = 0; i < n; i++) {
      vector<int> row(n, 0);
      for(int j = 0; j < m; j++) {
        if(ans[i][j] != '.') continue;
        if(board[i][j] == 'U' && row[i] + 1 <= cntRow[i] / 2) {
          row[i]++;
          ans[i][j] = 'W';
          ans[i + 1][j] = 'B';
        }
        else if(board[i][j] == 'U' && row[i] + 1 > cntRow[i] / 2) {
          row[i]++;
          ans[i][j] = 'B';
          ans[i + 1][j] = 'W';
        }
      }
    }
    for(int i = 0; i < m; i++) {
      vector<int> col(m, 0);
      for(int j = 0; j < n; j++) {
        if(ans[j][i] != '.') continue;
        if(board[j][i] == 'L' && col[i] + 1 <= cntCol[i] / 2) {
          col[i]++;
          ans[j][i] = 'W';
          ans[j][i + 1] = 'B';
        }
        else if(board[j][i] == 'L' && col[i] + 1 > cntCol[i] / 2) {
          col[i]++;
          ans[j][i] = 'B';
          ans[j][i + 1] = 'W';
        }
      }
    }
    bool ok = true;
    for(int i = 0; i < n; i++) {
      int black = 0, white = 0;
      for(int j = 0; j < m; j++) {
        if(ans[i][j] == '.') continue;
        if(ans[i][j] == 'B') black++;
        else white++;
      }
      if(black != white) ok = false;
    }
    for(int i = 0; i < m; i++) {
      int black = 0, white = 0;
      for(int j = 0; j < n; j++) {
        if(ans[j][i] == '.') continue;
        if(ans[j][i] == 'B') black++;
        else white++;
      }
      if(black != white) ok = false;
    }
    if(!ok) cout << "-1\n";
    else {
      for(int i = 0; i < n; i++)
        cout << ans[i] << '\n';
    }
  }
}


