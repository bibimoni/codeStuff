#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    // Khởi tạo generator với seed lấy từ tham số dòng lệnh (argv[1] chính là t)
    registerGen(argc, argv, 1);

    // Sinh số lượng testcase T trong 1 file (ví dụ từ 1 đến 10000)
    int T = rnd.next(1000, 10000);
    cout << T << "\n";

    // Sinh n ngẫu nhiên cho từng testcase
    for (int i = 0; i < T; i++) {
        int n = rnd.next(1, 1000000000); // 1 <= n <= 10^9
        cout << n << "\n";
    }

    return 0;
}