#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

const int MAXN = 3005;

void solveQuery(int N, const vector<bitset<MAXN>>& adj, const string& initial_state) {
    vector<bitset<MAXN>> A(N);
    for (int i = 0; i < N; ++i) {
        A[i] = adj[i];
        A[i][N] = (initial_state[i] == '0') ? 1 : 0;
    }

    vector<int> pivot_row(N, -1);
    int row = 0;
    for (int col = 0; col < N && row < N; ++col) {
        int sel = row;
        while (sel < N && !A[sel][col]) sel++;
        if (sel == N) continue;

        swap(A[row], A[sel]);
        pivot_row[col] = row;

        for (int i = 0; i < N; ++i) {
            if (i != row && A[i][col]) {
                A[i] ^= A[row];
            }
        }
        row++;
    }

    for (int i = 0; i < N; ++i) {
        bool all_zero = true;
        for (int j = 0; j < N; ++j) {
            if (A[i][j]) {
                all_zero = false;
                break;
            }
        }
        if (all_zero && A[i][N]) {
            cout << -1 << "\n";
            return;
        }
    }

    vector<int> result;
    for (int col = 0; col < N; ++col) {
        if (pivot_row[col] != -1 && A[pivot_row[col]][N]) {
            result.push_back(col + 1);
        }
    }

    cout << result.size();
    for (int v : result) {
        cout << " " << v;
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, Q;
    if (!(cin >> N >> M >> Q)) return 0;

    vector<bitset<MAXN>> adj(N);
    for (int i = 0; i < N; ++i) adj[i][i] = 1; 

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for (int q = 0; q < Q; ++q) {
        string s = "";
        // SỬA LỖI: Đọc N ký tự cách nhau bởi khoảng trắng
        for (int i = 0; i < N; ++i) {
            char c;
            cin >> c;
            s += c;
        }
        solveQuery(N, adj, s);
    }

    return 0;
}