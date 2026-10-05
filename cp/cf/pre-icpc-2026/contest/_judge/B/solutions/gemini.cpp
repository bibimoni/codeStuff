#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

const int MAXN = 3005;
const int MAXQ = 505;
const int MAX_COLS = MAXN + MAXQ;

// M_matrix[i] represents the i-th row of the augmented matrix.
// Columns 0 to N-1 are the graph adjacency + identity.
// Columns N to N+Q-1 are the target vectors for each query.
bitset<MAX_COLS> M_matrix[MAXN];

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    if (!(cin >> n >> m >> q)) return 0;

    // Initialize the left side of the matrix (A)
    for (int i = 0; i < n; ++i) {
        M_matrix[i].set(i); // Node affects itself
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v; // 0-indexed
        M_matrix[u].set(v);
        M_matrix[v].set(u);
    }

    // Initialize the right side of the matrix (Queries)
    for (int query_idx = 0; query_idx < q; ++query_idx) {
        for (int i = 0; i < n; ++i) {
            char c;
            cin >> c; // Using char skips whitespace gracefully 
            // We want the final state to be 1. 
            // So if initial is 0, target is 1. If initial is 1, target is 0.
            if (c == '0') {
                M_matrix[i].set(n + query_idx);
            }
        }
    }

    // Gauss-Jordan Elimination over GF(2)
    int row = 0;
    vector<int> pivot_col(n, -1);

    for (int c = 0; c < n; ++c) {
        int pivot_row = row;
        // Find a pivot for column c
        while (pivot_row < n && !M_matrix[pivot_row].test(c)) {
            pivot_row++;
        }
        
        // If no pivot is found, c is a free variable (we can leave it as 0)
        if (pivot_row == n) continue; 
        
        // Swap current row with pivot row
        swap(M_matrix[row], M_matrix[pivot_row]);
        pivot_col[row] = c;
        
        // Eliminate the variable from all other rows
        for (int i = 0; i < n; ++i) {
            if (i != row && M_matrix[i].test(c)) {
                M_matrix[i] ^= M_matrix[row];
            }
        }
        row++;
    }

    // Answer each query
    for (int query_idx = 0; query_idx < q; ++query_idx) {
        bool possible = true;
        
        // Check for inconsistencies (0 = 1)
        for (int i = row; i < n; ++i) {
            if (M_matrix[i].test(n + query_idx)) {
                possible = false;
                break;
            }
        }
        
        if (!possible) {
            cout << -1 << "\n";
        } else {
            vector<int> ans;
            // Extract the solution for basic variables
            for (int i = 0; i < row; ++i) {
                if (M_matrix[i].test(n + query_idx)) {
                    ans.push_back(pivot_col[i] + 1); // Convert back to 1-indexed
                }
            }
            
            // Output
            cout << ans.size();
            for (int node : ans) {
                cout << " " << node;
            }
            cout << "\n";
        }
    }

    return 0;
}