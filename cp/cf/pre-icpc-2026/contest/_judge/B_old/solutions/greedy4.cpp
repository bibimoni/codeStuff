#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

const int MAX_EXPAND = 300; 

struct State {
    int ones;
    string s;
    vector<int> path;

    bool operator<(const State& other) const {
        if (ones != other.ones) return ones < other.ones;
        return path.size() > other.path.size();
    }
};

void solveQuery(int N, const vector<vector<int>>& adj, string start_state) {
    string target_state(N, '1');
    if (start_state == target_state) {
        cout << 0 << "\n";
        return;
    }

    priority_queue<State> pq;
    unordered_set<string> visited;

    int initial_ones = count(start_state.begin(), start_state.end(), '1');
    pq.push({initial_ones, start_state, {}});
    visited.insert(start_state);

    int expand_count = 0;

    while (!pq.empty() && expand_count < MAX_EXPAND) {
        State curr = pq.top();
        pq.pop();
        expand_count++;

        for (int i = 0; i < N; ++i) {
            string next_s = curr.s;
            for (int v : adj[i]) {
                next_s[v] = (next_s[v] == '0') ? '1' : '0';
            }

            if (visited.find(next_s) == visited.end()) {
                vector<int> next_path = curr.path;
                next_path.push_back(i + 1);

                if (next_s == target_state) {
                    cout << next_path.size();
                    for (int x : next_path) cout << " " << x;
                    cout << "\n";
                    return;
                }

                int ones = count(next_s.begin(), next_s.end(), '1');
                pq.push({ones, next_s, next_path});
                visited.insert(next_s);
            }
        }
    }

    cout << -1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, Q;
    if (!(cin >> N >> M >> Q)) return 0;

    vector<vector<int>> adj(N);
    for (int i = 0; i < N; ++i) adj[i].push_back(i); 

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
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