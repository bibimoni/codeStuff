#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);  cout.tie(nullptr)
#define endl '\n'

signed main() {
    int n; cin >> n;
    int curr = 1;
    int dx[] = {0, 1, 1, -1},
        dy[] = {1, -1, 0, 1};
    int k = 0;
    vector<vector<int>> mat(n, vector<int> (n));
    int x = 0, y = 0;
    while(x != n - 1 || y != n - 1) {
        mat[x][y] = curr; curr++;
//        cerr << x << ' ' << y << ' ' << mat[x][y] << ' ' << k << endl;
        x += dx[k]; y += dy[k]; 
        if(k == 0 || k == 2) k = (k + 1) % 4;
        else if((k == 1 || k == 3) && (x == 0 || x == n - 1 || y == 0 || y == n - 1)) {
            k = (k + 1) % 4;
        }
        if(x == n - 1 && y == 0) {
            k = (k - 2) % 4; dx[1] = -1; dy[1] = 1; dx[3] = 1; dy[3] = -1;
        }
    }
    mat[n - 1][n - 1] = curr;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }

}
