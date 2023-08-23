#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

int dR[] = {-1, -2, -1, -2,  1, 2,  1,  2};
int dC[] = {-2, -1,  2,  1,  2, 1, -2, -1};

int n, m, xt, yt, destX, destY;
vector<vector<bool>> visited(1001, vector<bool>(1001, false));

bool foundDest = false;

bool isValid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m && !visited[x][y];
}

int res;
void BFS() {
    xt--; yt--; destX--; destY--;
    queue<pair<pair<int, int>, int>> Q;
    Q.push({{xt, yt}, 0});
    visited[xt][yt] = true;
    while(!Q.empty()) {
        if(foundDest) break;
        auto u = Q.front().first;
        auto step = Q.front().second;
        auto uX = u.first, uY = u.second;
        if(uX == destX && uY == destY) {
            foundDest = true;
            res = step;
            break;
        }
        Q.pop();
        for(int i = 0; i < 8; i++) {
            int vX = uX + dR[i];
            int vY = uY + dC[i];
            if(!isValid(vX, vY)) continue;
            //cout << vX << ' ' << vY << endl;
            visited[vX][vY] = true;
            Q.push({{vX, vY}, step + 1});
        }
    }
    if(!foundDest) {
        cout << -1;
    }
    else cout << res;
}

signed main()
{
    cin >> n >> m >> xt >> yt >> destX >> destY;
    BFS();
    return 0;
}
    
