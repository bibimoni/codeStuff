#include "testlib.h"
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    // 1. Kiểm tra dòng đầu tiên: N, M, Q
    int n = inf.readInt(1, 3000, "N");
    inf.readSpace();
    int m = inf.readInt(0, 3000, "M");
    inf.readSpace();
    int q = inf.readInt(1, 500, "Q");
    inf.readEoln();

    // 2. Kiểm tra M dòng tiếp theo: các cạnh của đồ thị
    set<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u = inf.readInt(1, n, "u");
        inf.readSpace();
        int v = inf.readInt(1, n, "v");
        inf.readEoln();

        ensuref(u != v, "Self-loop detected at edge %d: (%d, %d)", i + 1, u, v);
        
        pair<int, int> edge = {min(u, v), max(u, v)};
        ensuref(edges.count(edge) == 0, "Duplicate edge detected at edge %d: (%d, %d)", i + 1, u, v);
        edges.insert(edge);
    }

    // 3. Kiểm tra Q dòng tiếp theo: N số 0/1 cách nhau bởi dấu cách
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < n; j++) {
            inf.readInt(0, 1, format("S_%d_%d", i + 1, j + 1));
            if (j < n - 1) inf.readSpace();
        }
        inf.readEoln();
    }

    // 4. Bỏ qua tất cả khoảng trắng/xuống dòng thừa ở cuối file và xác thực EOF
    inf.seekEof();
    inf.readEof();

    return 0;
}