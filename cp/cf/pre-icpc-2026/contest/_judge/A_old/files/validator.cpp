#include "testlib.h"
#include <vector>
#include <set>

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    // 1. Đọc n và yêu cầu ngay sau đó PHẢI là dấu xuống dòng
    int n = inf.readInt(1, 50, "n");
    inf.readEoln();
    
    set<int> seen;
    for (int i = 0; i < n; i++) {
        // 2. Đọc p[i]
        int p_i = inf.readInt(1, n, format("p[%d]", i + 1));
        
        ensuref(seen.find(p_i) == seen.end(), "Duplicate element %d found at index %d", p_i, i + 1);
        seen.insert(p_i);
        
        // 3. Nếu chưa phải phần tử cuối thì phải có ĐÚNG 1 dấu cách
        if (i < n - 1) {
            inf.readSpace();
        }
    }

    // 4. Kết thúc mảng p phải là dấu xuống dòng
    inf.readEoln();

    // 5. Kết thúc file (đảm bảo không còn bất kỳ khoảng trắng hay ký tự rác nào dưới cuối file)
    inf.readEof();

    return 0;
}