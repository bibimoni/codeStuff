#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, Q;
    if (!(cin >> N >> M >> Q)) return 0;

    vector<vector<int>> mask(N + 1);
    for (int i = 1; i <= N; ++i) mask[i].push_back(i);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        mask[u].push_back(v);
        mask[v].push_back(u);
    }

    while (Q--) {
        // --- CHỈNH SỬA INPUT TẠI ĐÂY ---
        string s = "";
        for (int i = 0; i < N; ++i) {
            char c;
            cin >> c;
            s += c;
        }
        // -------------------------------
        
        vector<int> state(N + 1);
        int zeros = 0;
        for (int i = 1; i <= N; ++i) {
            state[i] = s[i - 1] - '0';
            if (state[i] == 0) zeros++;
        }

        set<int> toggled;
        int steps = 0;

        while (zeros > 0 && steps < N * 2) {
            int best_u = -1;
            int max_zeros = 0;

            for (int u = 1; u <= N; ++u) {
                int cnt = 0;
                for (int v : mask[u]) {
                    if (state[v] == 0) cnt++;
                }
                if (cnt > max_zeros) {
                    max_zeros = cnt;
                    best_u = u;
                }
            }

            if (best_u == -1 || max_zeros == 0) break;

            for (int v : mask[best_u]) {
                zeros += (state[v] == 0) ? -1 : 1;
                state[v] ^= 1;
            }

            if (toggled.count(best_u)) toggled.erase(best_u);
            else toggled.insert(best_u);

            steps++;
        }

        if (zeros == 0) {
            cout << toggled.size();
            for (int u : toggled) cout << " " << u;
            cout << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}