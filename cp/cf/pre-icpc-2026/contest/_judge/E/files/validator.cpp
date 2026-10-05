#include "testlib.h"
#include <vector>

using namespace std;

// Cấu trúc Disjoint Set Union (DSU) để kiểm tra đồ thị có phải là cây hay không
struct DSU {
    vector<int> parent;
    
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    // Khởi tạo testlib
    registerValidation(argc, argv);

    // Đọc số n
    int n = inf.readInt(1, 4000, "n");
    inf.readEoln();

    DSU dsu(n);

    // Đọc n - 1 cạnh
    for (int i = 0; i < n - 1; i++) {
        int u = inf.readInt(1, n, "u");
        inf.readSpace();
        
        int v = inf.readInt(1, n, "v");
        inf.readSpace();
        
        int w = inf.readInt(0, 2, "w");
        inf.readEoln();

        // Kiểm tra cạnh khuyên (self-loop)
        ensuref(u != v, "Self-loop is not allowed between %d and %d", u, v);
        
        // Kiểm tra xem việc thêm cạnh có tạo chu trình hay không
        ensuref(dsu.unite(u, v), "Graph is not a tree: cycle detected with edge %d-%d", u, v);
    }

    // [SỬA LỖI]: Bắt buộc phải gọi inf.readEof().
    // Hàm này sẽ tự động nuốt sạch các dấu cách, tab, xuống dòng thừa ở cuối file
    // và báo FAIL nếu còn dư chữ/số bất thường.
    inf.readEof();
    
    return 0;
}