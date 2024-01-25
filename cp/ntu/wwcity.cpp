/**
 * File              : wwcity.cpp
 * Author            : distiled
 * Date              : 18.06.2023
 * Last Modified Date: 18.06.2023
 * Last Modified By  : distiled
 */
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
vector<int> tree[MAXN];

int subtree_size[MAXN];
int centroid_parent[MAXN];
bool visited[MAXN];

int dfs(int node) {
    int size = 1;
    int heavy_child = 0;
    visited[node] = true;
    for (int neighbor : tree[node]) {
        if (!visited[neighbor]) {
            int subsize = dfs(neighbor);
            size += subsize;
            heavy_child = max(heavy_child, subsize);
        }
    }
    if (max(heavy_child, n - size) * 2 <= n) {
        centroid_parent[node] = 0;
    } else {
        for (int neighbor : tree[node]) {
            if (!visited[neighbor]) {
                subtree_size[neighbor] = size;
            }
        }
        int max_subtree_size = 0;
        for (int neighbor : tree[node]) {
            if (!visited[neighbor]) {
                max_subtree_size = max(max_subtree_size, subtree_size[neighbor]);
            }
        }
        while (max_subtree_size * 2 > size) {
            for (int neighbor : tree[node]) {
                if (!visited[neighbor] && subtree_size[neighbor] > subtree_size[node]) {
                    node = neighbor;
                    break;
                }
            }
            max_subtree_size = max(0, size - subtree_size[node]);
            for (int neighbor : tree[node]) {
                if (!visited[neighbor]) {
                    max_subtree_size = max(max_subtree_size, subtree_size[neighbor]);
                }
            }
        }
        centroid_parent[node] = dfs(node);
    }
    return size;
}

int cnt[MAXN];

void count_pairs(int node) {
    visited[node] = true;
    cnt[node] = n - 1;
    for (int neighbor : tree[node]) {
        if (!visited[neighbor]) {
            subtree_size[neighbor] = n - subtree_size[node];
            count_pairs(neighbor);
            cnt[node] -= subtree_size[neighbor];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        tree[u-1].push_back(v-1);
        tree[v-1].push_back(u-1);
    }

    dfs(0);

    memset(visited, false, sizeof(visited));
    memset(subtree_size, 0, sizeof(subtree_size));
    count_pairs(0);

    for (int i = 0; i < n; i++) {
        cout << cnt[centroid_parent[i]] << '\n';
    }

    return 0;
}
