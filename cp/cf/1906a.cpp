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

bool compareString(string a, string b) {
  for(int i = 0; i < 3; i++) {
    if(a[i] != b[i]) return a[i] < b[i];
  }
  return a < b;
}
vector<string> a(3);
vector<string> ans;
bool valid(int x, int y) {
  return x >= 0 && y >= 0 && x < 3 && y < 3;
}
int dx[] = {-1, 0,   1, 1, 1, 0, -1, -1};
int dy[] = {-1, -1, -1, 0, 1, 1,  1,  0};
void dfs(int i, string curr, int x, int y, int prevX = -1, int prevY = -1) {
  if(i == 3) {
    ans.push_back(curr);
    return;
  }
  for(int j = 0; j < 8; j++) {
    int ux = x + dx[j];
    int uy = y + dy[j];
    if(ux == prevX && uy == prevY) continue;
    if(valid(ux, uy))
      dfs(i + 1, curr + a[x][y], ux, uy, x, y);
  }
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  for(int i = 0; i < 3; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      dfs(0, "", i, j);
  sort(ans.begin(), ans.end(), compareString);
  cout << ans[0];
}

