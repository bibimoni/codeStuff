#include "testlib.h"
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    // Tắt kiểm tra định dạng khoảng trắng nghiêm ngặt
    inf.strict = false;

    // Đọc số lượng chàng trai n (7 <= n <= 100)
    int n = inf.readInt(7, 100, "n");

    map<int, int> height_count;

    for (int i = 0; i < n; i++) {
        // Đọc tên: liền nhau, 1..10 ký tự a-z, A-Z
        string name = inf.readToken("[a-zA-Z]{1,10}", "S_i");

        // Đọc chiều cao: 1 <= H_i <= 1000
        int height = inf.readInt(1, 1000, "H_i");

        height_count[height]++;
    }

    // Bỏ qua toàn bộ khoảng trắng và dấu xuống dòng thừa ở cuối file
    inf.seekEof();

    // Polygon bắt buộc validator phải kết thúc bằng readEof()
    inf.readEof();

    // Kiểm tra logic: Phải có duy nhất 1 chiều cao xuất hiện đúng 7 lần
    int valid_dwarf_heights = 0;
    for (auto [height, count] : height_count) {
        if (count == 7) {
            valid_dwarf_heights++;
        }
    }

    ensuref(valid_dwarf_heights == 1,
            "Dữ liệu không hợp lệ: Cần duy nhất 1 chiều cao xuất hiện 7 lần, nhưng tìm thấy %d",
            valid_dwarf_heights);

    return 0;
}