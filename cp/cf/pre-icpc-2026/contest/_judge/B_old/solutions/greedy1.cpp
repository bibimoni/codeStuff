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
        bool ok = true;

        while (zeros > 0) {
            int best_u = -1;
            int max_gain = 0;

            for (int u = 1; u <= N; ++u) {
                int gain = 0;
                for (int v : mask[u]) {
                    gain += (state[v] == 0) ? 1 : -1;
                }
                if (gain > max_gain) {
                    max_gain = gain;
                    best_u = u;
                }
            }

            if (best_u == -1 || max_gain <= 0) {
                ok = false;
                break;
            }

            for (int v : mask[best_u]) {
                zeros += (state[v] == 0) ? -1 : 1;
                state[v] ^= 1;
            }

            if (toggled.count(best_u)) toggled.erase(best_u);
            else toggled.insert(best_u);
        }

        if (ok && zeros == 0) {
            cout << toggled.size();
            for (int u : toggled) cout << " " << u;
            cout << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}