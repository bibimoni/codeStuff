#include "testlib.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    // Đọc tham số n từ command line (nếu không truyền thì sinh ngẫu nhiên 7..100)
    int n = opt<int>(1, rnd.next(7, 100));

    // Chọn chiều cao cho 7 chú lùn
    int dwarf_height = rnd.next(1, 1000);

    vector<pair<string, int>> people;
    map<int, int> height_count;

    // Sinh 7 chú lùn
    for (int i = 0; i < 7; i++) {
        string name = rnd.next("[a-zA-Z]{1,10}");
        people.push_back({name, dwarf_height});
    }
    height_count[dwarf_height] = 7;

    // Sinh n - 7 chàng trai còn lại
    for (int i = 0; i < n - 7; i++) {
        string name = rnd.next("[a-zA-Z]{1,10}");
        int h;
        do {
            h = rnd.next(1, 1000);
        } while (h == dwarf_height || height_count[h] == 6);
        // Tránh h trùng chiều cao chú lùn và tránh h đạt đúng 7 lần xuất hiện

        height_count[h]++;
        people.push_back({name, h});
    }

    // Trộn ngẫu nhiên thứ tự các chàng trai trong công viên
    shuffle(people.begin(), people.end());

    // In kết quả
    cout << n << "\n";
    for (const auto& p : people) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}