#include "testlib.h"
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    setName("Checker for Neural Network Reboot Problem");
    registerTestlibCmd(argc, argv);

    // 1. Đọc dữ liệu từ file input (inf) theo định dạng mới (các số 0/1 cách nhau dấu cách)
    int n = inf.readInt(1, 3000, "N");
    int m = inf.readInt(0, 3000, "M");
    int q = inf.readInt(1, 500, "Q");

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u = inf.readInt(1, n, "u");
        int v = inf.readInt(1, n, "v");
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> scenarios(q, vector<int>(n + 1));
    for (int i = 0; i < q; i++) {
        for (int j = 1; j <= n; j++) {
            scenarios[i][j] = inf.readInt(0, 1, format("S_%d_%d", i + 1, j));
        }
    }

    // 2. Kiểm tra từng truy vấn
    for (int q_id = 1; q_id <= q; q_id++) {
        // Đọc đáp án của Jury
        int ans_k = ans.readInt(-1, n, format("ans_k (scenario %d)", q_id));
        if (ans_k != -1) {
            for (int j = 0; j < ans_k; j++) {
                ans.readInt(1, n, format("ans_v (scenario %d)", q_id));
            }
        }

        // Đọc đáp án của Contestant
        int ouf_k = ouf.readInt(-1, n, format("ouf_k (scenario %d)", q_id));
        vector<int> contestant_ops;
        if (ouf_k != -1) {
            for (int j = 0; j < ouf_k; j++) {
                int v = ouf.readInt(1, n, format("ouf_v (scenario %d, idx %d)", q_id, j + 1));
                contestant_ops.push_back(v);
            }
        }

        // 3. Đánh giá kết quả của Contestant
        if (ouf_k != -1) {
            vector<int> state(n + 1);
            for (int j = 1; j <= n; j++) {
                state[j] = scenarios[q_id - 1][j];
            }

            for (int v : contestant_ops) {
                state[v] ^= 1;
                for (int u : adj[v]) {
                    state[u] ^= 1;
                }
            }

            bool all_on = true;
            for (int j = 1; j <= n; j++) {
                if (state[j] == 0) {
                    all_on = false;
                    break;
                }
            }

            if (!all_on) {
                quitf(_wa, "Scenario %d: Contestant's reboot sequence failed to turn all terminals online", q_id);
            }

            if (ans_k == -1) {
                quitf(_fail, "Scenario %d: Contestant found a valid solution, but jury outputted -1", q_id);
            }
        } else {
            if (ans_k != -1) {
                quitf(_wa, "Scenario %d: Solution exists, but contestant reported impossible (-1)", q_id);
            }
        }
    }

    // 4. Bỏ qua các dấu cách/xuống dòng thừa ở cuối file output của Jury và Contestant
    ans.seekEof();
    ans.readEof();

    ouf.seekEof();
    ouf.readEof();

    quitf(_ok, "All %d scenarios checked successfully", q);
}