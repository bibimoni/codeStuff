// time-limit: 3000
/**
 * Author: distiled
 * Optimized by: ChatGPT
 */
// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005; // Adjust according to constraints
const int MAX_M = 1005;
const int MAX_K = 1000005; // Maximum number of different colors

int n, m, q;
int a[MAX_N][MAX_M];
int col_idx[MAX_N][MAX_M];
int g[MAX_N][MAX_M];
int pre[MAX_N][MAX_M];
int parent[MAX_N * MAX_M];
int sz[MAX_N * MAX_M];
int was[MAX_K];
pair<int, int> cands[MAX_K];
int colors[MAX_K];
int color_to_index[MAX_K];
int color_present[MAX_K];

inline int id1(int x, int y) {
    return (x - 1) * m + y;
}

inline pair<int, int> id2(int x) {
    return make_pair((x + m - 1) / m, x % m == 0 ? m : x % m);
}

int find(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find(parent[v]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
        int xb = (b + m - 1) / m;
        int yb = b % m == 0 ? m : b % m;
        g[xb][yb] = 0;
    }
}

inline int sum(int xs, int ys, int xe, int ye) {
    return pre[xe][ye] - pre[xs - 1][ye] - pre[xe][ys - 1] + pre[xs - 1][ys - 1];
}

inline bool is_inside(int x, int y, int xs, int ys, int xe, int ye) {
    return xs <= x && x <= xe && ys <= y && y <= ye;
}

int main() {
    // Fast input/output
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    // Read input
    cin >> n >> m;

    int k = 0;
    unordered_map<int, int> color_map;

    // Read grid and map colors to indices
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (color_map.find(a[i][j]) == color_map.end()) {
                color_map[a[i][j]] = k;
                colors[k] = a[i][j];
                k++;
            }
            col_idx[i][j] = color_map[a[i][j]];
            g[i][j] = 1;
        }
    }

    // Initialize DSU
    int N = n * m + 1;
    for (int i = 0; i < N; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    // Build DSU
    const int dx[] = {0, 1, -1, 0};
    const int dy[] = {1, 0, 0, -1};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int u = id1(i, j);
            for (int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
                    if (a[nx][ny] == a[i][j]) {
                        int v = id1(nx, ny);
                        unite(u, v);
                    }
                }
            }
        }
    }

    // Build cands
    memset(color_present, 0, sizeof(color_present));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int color_idx = col_idx[i][j];
            if (!color_present[color_idx]) {
                int rep = find(id1(i, j));
                cands[color_idx] = id2(rep);
                color_present[color_idx] = 1;
            }
        }
    }

    // Build prefix sum
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i <= n; i++) {
        int row_sum = 0;
        for (int j = 1; j <= m; j++) {
            row_sum += g[i][j];
            pre[i][j] = pre[i - 1][j] + row_sum;
        }
    }

    // Read queries
    cin >> q;
    for (int qi = 0; qi < q; qi++) {
        int xs, ys, xe, ye;
        cin >> xs >> ys >> xe >> ye;
        int ans = sum(xs, ys, xe, ye);
        int s_size = 0;
        int s[MAX_K];

        // Collect border colors without duplicates
        for (int j = ys; j <= ye; j++) {
            int color_idx = col_idx[xs][j];
            if (!was[color_idx]) {
                s[s_size++] = color_idx;
                was[color_idx] = 1;
            }
            color_idx = col_idx[xe][j];
            if (!was[color_idx]) {
                s[s_size++] = color_idx;
                was[color_idx] = 1;
            }
        }
        for (int i = xs + 1; i <= xe - 1; i++) {
            int color_idx = col_idx[i][ys];
            if (!was[color_idx]) {
                s[s_size++] = color_idx;
                was[color_idx] = 1;
            }
            color_idx = col_idx[i][ye];
            if (!was[color_idx]) {
                s[s_size++] = color_idx;
                was[color_idx] = 1;
            }
        }

        for (int idx = 0; idx < s_size; idx++) {
            int color_idx = s[idx];
            auto [x, y] = cands[color_idx];
            if (!is_inside(x, y, xs, ys, xe, ye)) {
                ans += 1;
            }
            was[color_idx] = 0; // Reset for next query
        }

        cout << ans << '\n';
    }

    return 0;
}

// // time-limit: 3000
// /**
//  * Author: distiled
//  */
// #include<bits/stdc++.h>
// using namespace std;

// #ifdef DEBUG
// #include </Users/distiled/codeStuff/templates/debug.h>
// #else
// #define dbg(x...)
// #endif
// #define int int64_t 

// class Dsu {
//   vector<int> parent, size;

// public:
//   Dsu() {}
 
//   Dsu(int n) {
//     parent.resize(n);
//     size.assign(n, 1);
//     iota(parent.begin(), parent.end(), 0ll);
//   }
 
//   int find(int v) {
//     if (v == parent[v]) {
//       return v;
//     }
//     return parent[v] = find(parent[v]);
//   }
 
//   bool unite(int a, int b, vector<vector<int>> &g) {
//     a = find(a);
//     b = find(b);
//     if (a != b) {
//       if (size[a] < size[b]) {
//         swap(a, b);
//       }
//       parent[b] = a;
//       size[a] += size[b];
//       int gm = g[0].size() - 1;
//       int xb = (b + gm - 1) / gm;
//       int yb = (b % gm == 0 ? gm : b % gm);
//       g[xb][yb] = 0;
//       return true;
//     } else {
//       return false;
//     }
//   }
// };

// signed main() {
//   ios::sync_with_stdio(false); 
//   cin.tie(0);
//   int n, m;
//   cin >> n >> m;
//   vector<vector<int>> a(n + 1, vector<int>(m + 1));
//   vector<vector<int>> g(n + 1, vector<int>(m + 1, 1));
//   int mx = 0;
//   for (int i = 1; i <= n; i++) {
//     for (int j = 1; j <= m; j++) {
//       cin >> a[i][j];
//       mx = max(a[i][j], mx);
//     }
//   }

//   Dsu dsu((n + 2) * m);
//   vector<pair<int, int>> off = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
//   auto id1 = [&] (int x, int y) -> int {
//     return (x - 1) * m + y; 
//   };
//   for (int i = 1; i <= n; i++) {
//     for (int j = 1; j <= m; j++) {
//       for (auto [dx, dy] : off) {
//         int nx = i + dx;
//         int ny = j + dy;
//         if (nx <= n && ny <= m) {
//           if (a[nx][ny] == a[i][j]) {
//             dsu.unite(id1(i, j), id1(nx, ny), g);
//           }
//         }
//       }
//     }
//   }

//   auto id2 = [&] (int x) -> pair<int, int> {
//     return pair<int, int>{(x + m - 1) / m, x % m == 0 ? m : x % m};
//   };

//   vector<pair<int, int>> cands(mx + 1);

//   for (int i = 1; i <= n; i++) {
//     for (int j = 1; j <= m; j++) {
//       // cout << g[i][j] << " \n"[j == m];
//       cands[a[i][j]] = id2(dsu.find(id1(i, j)));
//     }
//   }

//   vector<vector<int>> pre(n + 1, vector<int>(m + 1));
//   for (int i = 1; i <= n; i++) {
//     for (int j = 1; j <= m; j++) {
//       pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + g[i][j];
//     }
//   }

//   auto sum = [&] (int xs, int ys, int xe, int ye) -> int {
//     return pre[xe][ye] - pre[xs - 1][ye] - pre[xe][ys - 1] + pre[xs - 1][ys - 1];
//   };

//   auto is_inside = [&] (int x, int y, int xs, int ys, int xe, int ye) -> bool {
//     return xs <= x && x <= xe && ys <= y && y <= ye;
//   };

//   vector<int> was(mx + 1, 0);

//   int q;
//   cin >> q;
//   for (int i = 0; i < q; i++) {
//     int xs, ys, xe, ye;
//     cin >> xs >> ys >> xe >> ye;
//     int ans = sum(xs, ys, xe, ye);
//     int bxl = xs, bxr = xe;
//     int byl = ys, byr = ye;
//     vector<int> s;
//     for (int j = byl; j <= byr; j++) {
//       if (is_inside(bxl, j, xs, ys, xe, ye)) {
//         s.push_back(a[bxl][j]);
//       }
//     }
//     for (int j = bxl + 1; j <= bxr; j++) {
//       if (is_inside(j, byr, xs, ys, xe, ye)) {
//         s.push_back(a[j][byr]);
//       }
//     }
//     for (int j = byr - 1; j >= byl; j--) {
//       if (is_inside(bxr, j, xs, ys, xe, ye)) {
//         s.push_back(a[bxr][j]);
//       }
//     }
//     for (int j = bxr - 1; j > bxl; j--) {
//       if (is_inside(j, byl, xs, ys, xe, ye)) {
//         s.push_back(a[j][byl]);
//       }
//     }
//     for (auto color : s) {
//       auto [x, y] = cands[color];
//       if (!is_inside(x, y, xs, ys, xe, ye) && !was[color]) {
//         ans += 1;
//         was[color] = 1;
//       }
//     }
//     for (auto color : s) {
//       was[color] = 0;
//     }
//     cout << ans << '\n';
//   }
// }


