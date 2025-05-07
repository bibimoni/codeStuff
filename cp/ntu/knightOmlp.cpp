#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

int dR[] = {-1, -2, -1, -2, 1, 2, 1, 2};
int dC[] = {-2, -1, 2, 1, 2, 1, -2, -1};

int n, m, xt, yt, destX, destY;
vector<vector<int>> board(1001, vector<int>(1001, 1e5));
vector<vector<bool>> visited(1001, vector<bool>(1001, false));

bool foundDest = false;

bool isValid(int x, int y) {
    return x > 0 && y > 0 && x <= n && y <= m && !visited[x][y];
}

int res;
void BFS() {
    queue<pair<pair<int, int>, int>> Q;
    Q.push({{xt, yt}, 0});
    visited[xt][yt] = true;
    while(!Q.empty()) {
        if(foundDest) break;
        auto u = Q.front().first;
        auto step = Q.front().second;
        auto uX = u.first, uY = u.second;
        Q.pop();
        for(int i = 0; i < 8; i++) {
            int vX = uX + dR[i];
            int vY = uY + dC[i];
            if(!isValid(vX, vY)) continue;
            if(vX == destX && vY == destY) {
                foundDest = true;
                res = min(board[vX][vY], step + 1);
                break;
            }
            visited[vX][vY] = true;
            board[vX][vY] = min(board[vX][vY], step + 1);
            Q.push({{vX, vY}, board[vX][vY]});
        }
    }
    if(!foundDest) {
        cout << -1;
    }
    else cout << res;
}
void dfs(int x, int y, int step) {
    if(!isValid(x, y)) return;
    cout << x << ' ' << y << ' ' << step << endl;
    if(x == destX && y == destY) {
        res = min(board[x][y], step + 1);
        foundDest = true;
        return;
    }
    visited[x][y] = true;
    board[x][y] = min(board[x][y], step + 1);
    for(int i = 0; i < 8; i++) {
        dfs(x + dR[i], y + dC[i], step + 1);
    }
}
signed main()
{
    cin >> n >> m >> xt >> yt >> destX >> destY;
    dfs(xt, yt, 0);
    //cout << foundDest << endl;
    if(foundDest) cout << res;
    else cout << -1;
    return 0;
}
