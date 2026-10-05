#include "testlib.h"
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>

using namespace std;

// Hàm tính Mảng hậu tố 1-indexed để sinh test case thực tế
vector<int> getSuffixArray(const string& s) {
    int n = s.length();
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    sort(p.begin(), p.end(), [&](int i, int j) {
        return s.substr(i - 1) < s.substr(j - 1);
    });
    return p;
}

int main(int argc, char* argv[]) {
    // Khởi tạo generator
    registerGen(argc, argv, 1);

    // Lấy giá trị n từ tham số thứ 1. 
    // Nếu tham số không hợp lệ hoặc không có, tự động sinh n ngẫu nhiên từ 1 đến 50.
    int n = opt<int>(1, rnd.next(1, 50)); 
    
    // Lấy loại test từ tham số thứ 2
    string type = opt<string>(2, "rand"); 

    vector<int> p;

    if (type == "rand") {
        // Sinh hoán vị ngẫu nhiên độ dài n (1-indexed)
        p = rnd.perm(n, 1);
    } 
    else if (type == "sorted") {
        // Dãy tăng dần: 1, 2, ..., n
        p.resize(n);
        iota(p.begin(), p.end(), 1);
    } 
    else if (type == "rev") {
        // Dãy giảm dần: n, n-1, ..., 1
        p.resize(n);
        iota(p.rbegin(), p.rend(), 1);
    } 
    else if (type == "string") {
        // Sinh mảng hậu tố có thể tồn tại xâu thực tế
        int k = opt<int>(3, rnd.next(1, min(n, 26)));
        string s = "";
        for (int i = 0; i < n; i++) {
            s += (char)('a' + rnd.next(0, k - 1));
        }
        p = getSuffixArray(s);
    }
    else {
        // [QUAN TRỌNG] Báo lỗi đỏ ngay lập tức nếu Script truyền sai tên type (ví dụ gõ 'random' thay vì 'rand')
        // Tránh tình trạng sinh ra mảng p rỗng gây lỗi "Unexpected white-space"
        quitf(_fail, "Unknown test type: %s", type.c_str());
    }

    // --- XUẤT DỮ LIỆU ĐÚNG ĐỊNH DẠNG NGHIÊM NGẶT ---
    
    // In ra n và xuống dòng
    cout << n << "\n";
    
    // In mảng p thủ công để kiểm soát dấu cách tuyệt đối
    for (int i = 0; i < n; i++) {
        cout << p[i];
        if (i < n - 1) {
            cout << " "; // Đảm bảo chỉ có dấu cách ở GIỮA các số
        }
    }
    cout << "\n"; // Dấu xuống dòng duy nhất ở cuối mảng

    return 0;
}