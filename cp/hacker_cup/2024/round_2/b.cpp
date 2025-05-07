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
#define int int64_t 

const int N = 6, M = 7;

int check_wins (vector<vector<char>> &a) {
  int ret = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M - 3; j++) {
      for (char c : {'C', 'F'}) {
        if (a[i][j] == c && a[i][j + 1] == c && a[i][j + 2] == c && a[i][j + 3] == c) {
          ret |= (c == 'C' ? 1 : 2);
        }
      }
    }
  }
  for (int j = 0; j < M; j++) {
    for (int i = 0; i < N - 3; i++) {
      for (char c : {'C', 'F'}) {
        if (a[i][j] == c && a[i + 1][j] == c && a[i + 2][j] == c && a[i + 3][j] == c) {
          ret |= (c == 'C' ? 1 : 2);
        }
      }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int x = i, y = j;
      for (char c : {'C', 'F'}) {
        if (x + 3 >= N || y + 3 >= M) {
          continue;
        }
        bool ok = true;
        for (int d = 0; d < 4; d++) {
          ok &= c == a[x + d][y + d];
        }
        if (ok) {
          ret |= (c == 'C' ? 1 : 2);
        }
        if (x + 3 >= N || y - 3 < 0) {
          continue;
        }
        ok = true;
        for (int d = 0; d < 4; d++) {
          ok &= c == a[x + d][y - d];
        }
        if (ok) {
          ret |= (c == 'C' ? 1 : 2);
        }
      }
    }
  }
  // if (ret == 3) {
  //   // dbg(a);
  // }
  return ret;
}

map<array<int, M>, int> f;

int bt(array<int, M> s, vector<vector<char>> &a, int st) {
  if (f.count(s)) {
    return f[s];
  }
  vector<vector<char>> cur(N, vector<char>(M, '.'));
  // dbg(s);
  for(int j = 0; j < M; j++) {
    for (int i = N - 1; i >= N - s[j]; i--) {
      cur[i][j] = a[i][j];
    }
  }
  int cw = check_wins(cur);
  if (cw > 0) {
    return cw;
  }
  if (st == N * M) {
    return cw;
  }
  int ret = 0;
  char nxt_turn = (st % 2 == 0 ? 'C' : 'F');
  for (int j = 0; j < M; j++) {
    int i = N - s[j] - 1;
    if (i >= 0 && cur[i][j] == '.' && nxt_turn == a[i][j]) {
      cur[i][j] = a[i][j];
      s[j] += 1;
      ret |= bt(s, a, st + 1);
      s[j] -= 1;
      cur[i][j] = '.';
    }
  
  }
  return f[s] = ret;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  freopen("four_in_a_burrow_input.txt", "r", stdin);
  freopen("four_in_a_burrow_validation_input.out", "w", stdout);
  for (int tc = 1; tc <= tt; tc++) {
    vector<vector<char>> a(N, vector<char>(M));
    for (int i = 0; i < N; i++) 
      for (int j = 0; j < M; j++)
        cin >> a[i][j];
    array<int, M> tmp{0, 0, 0, 0, 0, 0, 0};
    int ans = bt(tmp, a, 0);
    char ret;
    if (ans == 0) {
      ret = '0';
    } else if (ans == 1) {
      ret = 'C';
    } else if (ans == 2) {
      ret = 'F';
    } else {
      ret = '?';
    }
    f.clear();
    cout << "Case #" << tc << ": " << ret << '\n';  
  }
}


