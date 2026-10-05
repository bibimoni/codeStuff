#include "testlib.h"
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
};

int main(int argc, char* argv[]) {
    // Khởi tạo thư viện generator của testlib
    registerGen(argc, argv, 1);

    // Đọc n và type từ dòng lệnh truyền vào:
    // argv[1]: n (số đỉnh) - Mặc định là 4000 nếu không truyền
    // argv[2]: type (loại đồ thị từ 1 đến 6) - Mặc định là 0 (sẽ tự động sinh ngẫu nhiên theo tỉ lệ %)
    int n = opt<int>(1, 4000);
    int type = opt<int>(2, 0);

    // Nếu type == 0, tự động chọn dạng đồ thị theo đúng tỉ lệ phần trăm yêu cầu
    if (type == 0) {
        int p = rnd.next(1, 100);
        if (p <= 5)       type = 1; //  5%: Không có cạnh w = 0
        else if (p <= 15) type = 2; // 10%: Đồ thị đường thẳng (Line graph)
        else if (p <= 25) type = 3; // 10%: Đồ thị hình sao (Star graph)
        else if (p <= 35) type = 4; // 10%: Cây nhị phân (Binary tree)
        else if (p <= 60) type = 5; // 25%: Đồ thị ngẫu nhiên (Random tree)
        else              type = 6; // 40%: Đồ thị chiều cao rất lớn (Deep tree)
    }

    vector<pair<int, int>> base_edges;

    // --- BƯỚC 1: Xây dựng khung cây cơ bản (Topography) ---
    if (type == 2) { 
        // 10% - Đường thẳng (Line Graph)
        for (int i = 2; i <= n; i++) {
            base_edges.push_back({i - 1, i});
        }
    } 
    else if (type == 3) { 
        // 10% - Đồ thị hình sao (Star Graph: đỉnh 1 nối với tất cả đỉnh còn lại)
        for (int i = 2; i <= n; i++) {
            base_edges.push_back({1, i});
        }
    } 
    else if (type == 4) { 
        // 10% - Cây nhị phân (Binary Tree: đỉnh i nối với floor(i/2))
        for (int i = 2; i <= n; i++) {
            base_edges.push_back({i / 2, i});
        }
    } 
    else if (type == 5) { 
        // 25% - Đồ thị ngẫu nhiên (Random Tree)
        for (int i = 2; i <= n; i++) {
            int parent = rnd.next(1, i - 1);
            base_edges.push_back({parent, i});
        }
    } 
    else if (type == 6) { 
        // 40% - Đồ thị chiều cao rất lớn (Đỉnh i nối với random(i - 10, i - 1))
        for (int i = 2; i <= n; i++) {
            int parent = rnd.next(max(1, i - 10), i - 1);
            base_edges.push_back({parent, i});
        }
    } 
    else { 
        // type == 1: 5% Không có cạnh w = 0 (dùng dạng cây ngẫu nhiên/chiều cao lớn)
        for (int i = 2; i <= n; i++) {
            int parent = rnd.next(max(1, i - 10), i - 1);
            base_edges.push_back({parent, i});
        }
    }

    // --- BƯỚC 2: Hoán vị nhãn đỉnh ---
    // Giúp xáo trộn chỉ số đỉnh (tránh việc gốc luôn là đỉnh 1 hoặc đỉnh lớn nằm ở dưới)
    vector<int> perm(n + 1);
    iota(perm.begin(), perm.end(), 0);
    shuffle(perm.begin() + 1, perm.end());

    // --- BƯỚC 3: Sinh trọng số w và chiều cạnh ngẫu nhiên ---
    bool allow_zero = (type != 1); // Loại 1: Không cho phép w = 0
    vector<Edge> edges;

    for (auto [u, v] : base_edges) {
        u = perm[u];
        v = perm[v];

        // Ngẫu nhiên đảo thứ tự (u, v) hoặc (v, u) khi in
        if (rnd.next(2)) {
            swap(u, v);
        }

        // Chọn w
        int w = allow_zero ? rnd.next(0, 2) : rnd.next(1, 2);

        edges.push_back({u, v, w});
    }

    // --- BƯỚC 4: Xáo trộn danh sách cạnh ---
    shuffle(edges.begin(), edges.end());

    // --- BƯỚC 5: In kết quả ---
    cout << n << "\n";
    for (const auto& e : edges) {
        cout << e.u << " " << e.v << " " << e.w << "\n";
    }

    return 0;
}