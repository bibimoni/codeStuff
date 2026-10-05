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
        for (int i = 1; i <= N; ++i) state[i] = s[i - 1] - '0';

        set<int> toggled;
        for (int pass = 0; pass < 2; ++pass) {
            for (int i = 1; i <= N; ++i) {
                if (state[i] == 0) {
                    for (int v : mask[i]) state[v] ^= 1;
                    if (toggled.count(i)) toggled.erase(i);
                    else toggled.insert(i);
                }
            }
        }

        bool all_ones = true;
        for (int i = 1; i <= N; ++i) {
            if (state[i] == 0) { all_ones = false; break; }
        }

        if (all_ones) {
            cout << toggled.size();
            for (int u : toggled) cout << " " << u;
            cout << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}